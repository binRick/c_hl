////////////////////////////////
#include <ctype.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
////////////////////////////////
#include "ansilove-test/ansilove-test.h"
#include "ansilove/ansilove.h"
#include "hl/hl.h"
////////////////////////////////
#include "submodules/c_fsio/include/fsio.h"
#include "submodules/c_stringfn/include/stringfn.h"
#include "submodules/greatest/greatest.h"
////////////////////////////////
bool RUNNING = true;


void do_ansilove_str_test_0(){
  char *SRC_FILE   = "../ansilove/ansilove.c";
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


TEST t_ansilove_save_load_tests(void) {
  hl_load_save("../ansilove-test/ansilove-test.c", "/tmp/ansilove-test_save-load.png");
  hl_load_save("../ansilove/ansilove.c", "/tmp/ansilove_save-load.png");
  PASS();
}


TEST t_ansilove_str_load_tests(void) {
  do_ansilove_str_test_0();
  PASS();
}


TEST t_ansilove_file_tests(void) {
  do_ansilove_file_test_0();
  do_ansilove_file_test_1();
  PASS();
}


SUITE(s_ansilove) {
  RUN_TEST(t_ansilove_str_load_tests);
  RUN_TEST(t_ansilove_save_load_tests);
  RUN_TEST(t_ansilove_file_tests);
}

GREATEST_MAIN_DEFS();


int main(int argc, char **argv) {
  GREATEST_MAIN_BEGIN();
  RUN_SUITE(s_ansilove);
  GREATEST_MAIN_END();
}
