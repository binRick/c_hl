#include "hl-test.h"
#define MIN_SRC_LEN        10
#define X_STR(STR)    #STR
#define X_FXN(STR)    X_STR(STR)
#define TEST_SRC_FILE_1    "../png/png.c"
#define TEST_SRC_FILE_2    "../hl-test/hl-test.c"
#define TEST_SRC_FILE_3    "../hl-test/hl-test.h"
#define TEST_SRC_FILE_4    "../hl/hl.c"
#define TEST_SRC_FILE_5    "../hl/hl.h"
#define TEST_SRC_FILE_6    "../ansilove/ansilove.c"
#define TEST_SRC_FILE_7    "../ansilove/ansilove.h"
/////////////////////////////////////////////////////
const char TEST_SRCS[1024 * 32][32];

/////////////////////////////////////////////////////
static void do_hl_str_test(const char *FILE_NAME, const char *CONTENT){
  ct_start(NULL);
  char *HIGHLIGHTED_CONTENT = hl_str(CONTENT);
  char *DUR                 = ct_stop("");

  fprintf(stdout,
          AC_RESETALL AC_RED_BLACK AC_ITALIC
          "================================\n"
          "=      Highlight From string   =\n"
          "================================\n"
          "= File:  %s\n"
          "= In:    %s\n"
          "= Out:   %s\n"
          "= Dur:   %s\n"
          "================================"
          AC_RESETALL
          "\n"
          "%s"
          "\n"
          AC_RESETALL AC_RED_BLACK AC_ITALIC
          "================================"
          "\n"
          AC_RESETALL,
          FILE_NAME,
          bytes_to_string(strlen(CONTENT)),
          bytes_to_string(strlen(HIGHLIGHTED_CONTENT)),
          DUR,
          HIGHLIGHTED_CONTENT
          );
}

/////////////////////////////////////////////////////

void load_src(int SRC_ID, const char *SRC_FILE){
  sprintf(&TEST_SRCS[SRC_ID], "%s", fsio_read_text_file(SRC_FILE));
  long SRC_LEN = fsio_file_size(SRC_FILE);
  int  LEN     = strlen(TEST_SRCS[SRC_ID]);

  ASSERT_GTE(LEN, MIN_SRC_LEN);
  ASSERT_GTE(LEN, SRC_LEN);
  do_hl_str_test(SRC_FILE, &TEST_SRCS[SRC_ID]);
}

SUITE(load_srcs) {
  load_src(2, TEST_SRC_FILE_2);
  load_src(3, TEST_SRC_FILE_3);
  load_src(4, TEST_SRC_FILE_4);
  load_src(5, TEST_SRC_FILE_5);
  load_src(6, TEST_SRC_FILE_6);
  load_src(7, TEST_SRC_FILE_7);
  PASS();
}

GREATEST_MAIN_DEFS();

int do_test(int argc, char **argv) {
  GREATEST_MAIN_BEGIN();
  RUN_SUITE(load_srcs);
  GREATEST_MAIN_END();
  return(0);
}

int main(int argc, char **argv) {
  (void)argc; (void)argv;
  ct_set_unit(ct_MILLISECONDS);
  return(do_test(argc, argv));
}
