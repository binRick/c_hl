#include "ansilove-test.h"
bool RUNNING = true;


void do_ansilove_str_test_0(){
  char *SRC_FILE   = "../ansilove/ansilove.h";
  char *HL_CONTENT = hl_str(fsio_read_text_file(SRC_FILE));

  hl_str_save(HL_CONTENT, "/tmp/ansilove_str_0_HL.png");
}


void do_ansilove_file_test_1(){
  struct ansilove_ctx     ctx;
  struct ansilove_options options;

  ansilove_init(&ctx, &options);
  ansilove_loadfile(&ctx, "ansilove/ansilove.c");
  ansilove_ansi(&ctx, &options);
  ansilove_savefile(&ctx, "/tmp/ansilove.png");
  ansilove_clean(&ctx);
}


void do_ansilove_file_test_0(){
  struct ansilove_ctx     ctx;
  struct ansilove_options options;

  ansilove_init(&ctx, &options);
  ansilove_loadfile(&ctx, "/tmp/ansilove-test.c");
  ansilove_ansi(&ctx, &options);
  ansilove_savefile(&ctx, "/tmp/ansilove-test.png");
  ansilove_clean(&ctx);
}


TEST test_ansilove_save_load_tests(void) {
  hl_load_save("../ansilove-test/ansilove-test.c", "/tmp/ansilove-test_save-load.png");
  hl_load_save("../ansilove/ansilove.c", "/tmp/ansilove_save-load.png");
  PASS();
}


TEST test_ansilove_str_load_tests(void) {
  do_ansilove_str_test_0();
  PASS();
}


TEST test_ansilove_file_tests(void) {
  do_ansilove_file_test_0();
  do_ansilove_file_test_1();
  PASS();
}


SUITE(load_str_tests) {
  RUN_TEST(test_ansilove_str_load_tests);
}

SUITE(load_save_tests) {
  RUN_TEST(test_ansilove_save_load_tests);
}

SUITE(file_tests) {
  RUN_TEST(test_ansilove_file_tests);
}


GREATEST_MAIN_DEFS();


int do_test(int argc, char **argv) {
  GREATEST_MAIN_BEGIN();
  for (int i = 0; i < TEST_ITERATIONS; i++) {
    RUN_SUITE(file_tests);
    RUN_SUITE(load_save_tests);
    RUN_SUITE(load_str_tests);
  }
  GREATEST_MAIN_END();
  return(0);
}


int main(int argc, char **argv) {
  (void)argc; (void)argv;
  return(do_test(argc, argv));
}
