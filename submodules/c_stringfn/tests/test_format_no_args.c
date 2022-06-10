#include "string.h"
#include "stringfn.h"
#include "test.h"


void test_impl()
{
  char *string = stringfn_format("test format");

  assert_string_equal(string, "test format");
  assert_num_equal(strlen(string), 11);

  free(string);
}


int main()
{
  test_run(test_impl);
}

