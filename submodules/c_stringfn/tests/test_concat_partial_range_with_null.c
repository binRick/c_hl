#include "stringfn.h"
#include "test.h"


void test_impl()
{
  char **strings = malloc(sizeof(char *) * 7);

  strings[0] = "first line";
  strings[1] = "second line";
  strings[2] = "3rd";
  strings[3] = NULL;
  strings[4] = "4!!!";
  strings[5] = "bad";
  strings[6] = NULL;
  char *string = stringfn_concat(strings, 2, 3);

  assert_string_equal(string, "3rd4!!!");

  free(string);
  free(strings);
}


int main()
{
  test_run(test_impl);
}

