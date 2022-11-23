#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//////////////////////////////////////////////////////
#include "submodules/bytes/bytes.h"
#include "submodules/c_ansi/ansi-codes/ansi-codes.h"
#include "submodules/c_kat/include/highlight.h"
#include "submodules/c_string_buffer/include/stringbuffer.h"
#include "submodules/c_stringfn/include/stringfn.h"
#include "submodules/fs.c/fs.h"
#include "submodules/parson/parson.h"
//////////////////////////////////////////////////////
void do_kat_test_0();
char *hl_str(const char *CONTENT);
char *hl_highlight_path(const char *path);
int hl_max_columns(const char *CONTENT);

//////////////////////////////////////////////////////
