#include "hl.h"
///////////////////////////////////

static int hl_get_max_width(const char *bytes, size_t len){
  unsigned char *b        = (unsigned char *)bytes;
  char          *STRIPPED = malloc(strlen(b));

  size_t        i;

  for (i = 0; i < len; /* none */) {
    if (b[i] < 0x20) {       // C0
      break;
    }else if (b[i] < 0x80) { // ASCII
      i++;
    }else if (b[i] < 0xa0) { // C1
      break;
    }else if (b[i] < 0xc0) { // UTF-8 continuation
      break;
    }else if (b[i] < 0xe0) { // UTF-8 2-byte
      if (len < i + 2) {
        break;
      }
      i += 2;
    }else if (b[i] < 0xf0) { // UTF-8 3-byte
      if (len < i + 3) {
        break;
      }
      i += 3;
    }else if (b[i] < 0xf8) { // UTF-8 4-byte
      if (len < i + 4) {
        break;
      }
      i += 4;
    }else {                 // otherwise invalid
      break;
    }
  }
  fprintf(stderr, "i:%lu|b len:%lu|s:%.*s|\n", i, strlen(b), (int)i, b);
  sprintf(STRIPPED, "%.*s\n", (int)i, b);
  if (i > 0 && strlen(b) > 0) {
    fprintf(stderr, "%.*s\n", (int)i, b);
  }
  return(strlen(STRIPPED));
} /* hl_get_max_width */

///////////////////////////////////
int hl_max_columns(const char *CONTENT){
  int                    cols  = 120;
  struct StringFNStrings LINES = stringfn_split_lines(CONTENT);

  for (int i = 0; i < LINES.count; i++) {
    int WIDTH = hl_get_max_width(LINES.strings[i], strlen(LINES.strings[i]));
    fprintf(stderr, "WIDTH:%d\n", WIDTH);
    if (WIDTH > cols) {
      cols = WIDTH;
    }
  }
  stringfn_release_strings_struct(LINES);
  fprintf(stderr, "MAX WIDTH:%d\n", cols);
  return(cols);
}

char *hl_str(const char *CONTENT){
  if (highlight_init(NULL) < 0) {
    fprintf(stderr, "Unable to initialize the highlight!\n");
    exit(1);
  }
  char                   *HIGHLIGHTED_CONTENT = NULL;
  char                   *line                = highlight_alloc_line();
  struct StringBuffer    *SB                  = stringbuffer_new_with_options(strlen(CONTENT), true);
  struct StringFNStrings LINES                = stringfn_split_lines(CONTENT);

  for (int i = 0; i < LINES.count; i++) {
    line = highlight_line(LINES.strings[i], line, strlen(LINES.strings[i]));
    stringbuffer_append_string(SB, line);
    if (i <= LINES.count - 2) {
      stringbuffer_append_string(SB, "\n");
    }
  }
  highlight_free(line);
  highlight_finish();

  HIGHLIGHTED_CONTENT = stringbuffer_to_string(SB);
  stringfn_release_strings_struct(LINES);
  stringbuffer_release(SB);

  fprintf(stderr, "%s\n", HIGHLIGHTED_CONTENT);
  return(HIGHLIGHTED_CONTENT);
}

void do_kat_test_0(){
  char *line;

  if (highlight_init(NULL) < 0) {
    fprintf(stderr, "Unable to initialize the highlight!\n");
    exit(1);
  }

  line = highlight_line("#include <stdio.h>", NULL, 0);
  fprintf(stdout, "%s\n", line);

  line = highlight_line("int main(int argc, char **argv){ /* Comment. */", line, 0);
  fprintf(stdout, "%s\n", line);

  line = highlight_line("    printf(\"Hello World \%s\\n\", argv[1]);", line, 0);
  fprintf(stdout, "%s\n", line);

  line = highlight_line("}", line, 0);
  fprintf(stdout, "%s\n", line);

  highlight_free(line);
  highlight_finish();
}

int init_hl(){
  return(0);
}
