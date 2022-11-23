#include "ansilove/ansilove.h"
#include "msf_gif/msf_gif.h"
//#include "vips/vips.h"
#include "qoi/qoi.h"
#include "qoir/src/qoir.h"
struct {
  int width;
}                              hl_private_t;

static struct ansilove_options png_options = {
  .dos       = false,
  .diz       = false,
  .truecolor = true,
  .icecolors = true,
  .font      = ANSILOVE_FONT_TERMINUS,
  .mode      = ANSILOVE_MODE_TRANSPARENT,
  .columns   = 120,
};

__attribute__((unused))static int load_buffer(struct ansilove_ctx *ctx, const char *CONTENT){
  ctx->maplen = ctx->length = strlen(CONTENT);
  ctx->buffer = (uint8_t *)CONTENT;
  return(0);
}

void hl_deinit(module(hl) *exports) {
}

int hl_init(module(hl) *exports) {
  clib_module_init(hl, exports);
//  exports->priv=calloc(1,sizeof(struct hl_private_t));
  return(0);
}

void hl_str_save(const char *CONTENT, const char *DST){
  struct ansilove_options *options = malloc(sizeof(struct ansilove_options));
  struct ansilove_ctx     *ctx     = malloc(sizeof(struct ansilove_ctx));

  ansilove_init(ctx, options);
  char *content = malloc(strlen(CONTENT) + 32);

  sprintf(content, "%s", CONTENT);

  ctx->maplen = ctx->length = strlen(content);
  ctx->buffer = (uint8_t *)content;

  options->truecolor = png_options.truecolor;
  options->dos       = png_options.dos;
  options->diz       = png_options.diz;
  options->font      = png_options.font;
  options->icecolors = png_options.icecolors;
  options->columns   = png_options.columns;
  options->mode      = png_options.mode;

  ansilove_ansi(ctx, options);
  ansilove_savefile(ctx, DST);

  ansilove_clean(ctx);
  free(ctx);
  free(content);
  free(options);
}

void hl_load_save(const char *SRC, const char *DST){
  struct ansilove_ctx     ctx;
  struct ansilove_options *options = malloc(sizeof(struct ansilove_options));

  ansilove_init(&ctx, options);
  ansilove_loadfile(&ctx, SRC);

  options->truecolor = png_options.truecolor;
  options->dos       = png_options.dos;
  options->diz       = png_options.diz;
  options->font      = png_options.font;
  options->icecolors = png_options.icecolors;
  options->columns   = png_options.columns;
  options->mode      = png_options.mode;

  ansilove_ansi(&ctx, options);
  ansilove_savefile(&ctx, DST);
  ansilove_clean(&ctx);
}

int init_ansilove(){
  return(0);
}
