#include "ansilove-test.h"
bool RUNNING = true;


void do_ansilove(){
  struct ansilove_ctx     ctx;
  struct ansilove_options options;

  ansilove_init(&ctx, &options);
  ansilove_loadfile(&ctx, "/tmp/ansilove-test.c");
  ansilove_ansi(&ctx, &options);
  ansilove_savefile(&ctx, "/tmp/ansilove-test.png");
  ansilove_clean(&ctx);
}


void show_focus(){
  fprintf(stdout,
          "<%d>"
          "\n",
          123
          );
}


TEST test_ansilove(void) {
  do_ansilove();
  PASS();
}


SUITE(the_suite) {
  RUN_TEST(test_ansilove);
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
