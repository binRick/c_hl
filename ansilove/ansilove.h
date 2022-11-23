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
#include "submodules/module/def.h"
#include "submodules/module/module.h"
#include "submodules/module/require.h"
#include "submodules/parson/parson.h"
//////////////////////////////////////////////////////
void hl_load_save(const char *SRC, const char *DST);
void hl_str_save(const char *CONTENT, const char *DST);
struct hl_private_t;
module(hl) {
  define(hl, CLIB_MODULE);
  struct hl_private_t *priv;
  uint8_t             *(*string_new_buffer)(const char *CONTENT, size_t *len);
  uint8_t             *(*png_new_buffer)(const char *CONTENT, size_t *len);
  uint8_t             *(*qoir_new_buffer)(const char *CONTENT, size_t *len);
};
int  hl_init(module(hl) * exports);

void hl_deinit(module(hl) * exports);

exports(hl) {
  .init   = hl_init,
  .deinit = hl_deinit,
};

//ok

/////////
