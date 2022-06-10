#pragma once
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//////////////////////////////////////////////////////
#include "hl/hl.h"
#include "submodules/bytes/bytes.h"
#include "submodules/c_ansi/ansi-codes/ansi-codes.h"
#include "submodules/c_stringfn/include/stringfn.h"
#include "submodules/fs.c/fs.h"
#include "submodules/libansilove/include/ansilove.h"
#include "submodules/parson/parson.h"
//////////////////////////////////////////////////////
void hl_load_save(const char *SRC, const char *DST);
void hl_str_save(const char *CONTENT, const char *DST);

//ok

/////////
