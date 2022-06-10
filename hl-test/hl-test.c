#include "hl-test.h"
bool RUNNING = true;


void do_kat(){
  char *line;

  if (highlight_init(NULL) < 0) {
    fprintf(stderr, "Unable to initialize the highlight!\n");
    exit(1);
  }

  line = highlight_line("#include <stdio.h>", NULL, 0);
  puts(line);
  line = highlight_line("int main(int argc, char **argv){ /* Comment. */", line, 0);
  puts(line);
  line = highlight_line("    printf(\"Hello World \%s\\n\", argv[1]);", line, 0);
  puts(line);
  line = highlight_line("}", line, 0);
  puts(line);

  highlight_free(line);
  highlight_finish();
}


void show_focus(){
  fprintf(stdout,
          "<%d>"
          "\n",
          123
          );
}


TEST test_hl(void) {
  do_kat();
  PASS();
}


SUITE(the_suite) {
  RUN_TEST(test_hl);
}


GREATEST_MAIN_DEFS();


int do_test(int argc, char **argv) {
  GREATEST_MAIN_BEGIN();
  for (int i = 0; i < TEST_ITERATIONS; i++) {
    RUN_SUITE(the_suite);
  }
  GREATEST_MAIN_END();
  return(0);
}


int main(int argc, char **argv) {
  (void)argc; (void)argv;
  return(do_test(argc, argv));
}
