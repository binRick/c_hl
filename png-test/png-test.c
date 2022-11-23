#include "png-test.h"
bool RUNNING = true;

void do_png(){
}

void show_focus(){
  fprintf(stdout,
          "<%d>"
          "\n",
          123
          );
}

TEST test_png(void) {
  do_png();
  PASS();
}

SUITE(the_suite) {
  RUN_TEST(test_png);
}

GREATEST_MAIN_DEFS();

int do_test(int argc, char **argv) {
  GREATEST_MAIN_BEGIN();
  for (int i = 0; i < TEST_ITERATIONS; i++)
    RUN_SUITE(the_suite);
  GREATEST_MAIN_END();
  return(0);
}

int main(int argc, char **argv) {
  (void)argc; (void)argv;
  return(do_test(argc, argv));
}
