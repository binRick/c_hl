default: all
##############################################################
PASSH=$(shell command -v passh)
GIT=$(shell command -v git)
SED=$(shell command -v gsed||command -v sed)
NODEMON=$(shell command -v nodemon)
FZF=$(shell command -v fzf)
BLINE=$(shell command -v bline)
UNCRUSTIFY=$(shell command -v uncrustify)
PWD=$(shell command -v pwd)
FIND=$(shell command -v find)
EMBED_BINARY=$(shell command -v embed)
JQ_BIN=$(shell command -v jq)
##############################################################
DIR=$(shell $(PWD))
M1_DIR=$(DIR)
LOADER_DIR=$(DIR)/loader
EMBEDS_DIR=$(DIR)/embeds
VENDOR_DIR=$(DIR)/vendor
PROJECT_DIR=$(DIR)
MESON_DEPS_DIR=$(DIR)/meson/deps
VENDOR_DIR=$(DIR)/vendor
DEPS_DIR=$(DIR)/deps
BUILD_DIR=$(DIR)/build
ETC_DIR=$(DIR)/etc
MENU_DIR=$(DIR)/menu
DOCKER_DIR=$(DIR)/docker
LIST_DIR=$(DIR)/list
SOURCE_VENV_CMD=$(DIR)/scripts
VENV_DIR=$(DIR)/.venv
SCRIPTS_DIR=$(DIR)/scripts
HL_DIR=$(DIR)/hl
SOURCE_VENV_CMD = source $(VENV_DIR)/bin/activate
##############################################################
TIDIED_FILES = \
			   hl*/*.h hl*/*.c \
			   png*/*.h png*/*.c \
			   ansilove*/*.h ansilove*/*.c \

##############################################################
all: do-reset setup build test
git-pull:
	@git pull --recurse-submodules
setup: 
#do-setup-kat:
#	@$(SED) -i 's/CURRENT_THEME = ELF_DEITY/CURRENT_THEME = COLOR_8/g' ./submodules/c_kat/highlight.c

do-reset:
	@reset
clean:
	@rm -rf build
test: do-clear do-test
do-test: do-hl-test do-png-test do-ansilove-test

do-clear:
	@clear

do-png-test:
	@./build/png-test/png-test -v | ./submodules/greatest/contrib/greenest

do-ansilove-test:
	@cp ansilove-test/ansilove-test.c /tmp/.
	@unlink /tmp/ansilove-test.png 2>/dev/null||true
	@cd ./build/. && ./ansilove-test/ansilove-test -v | ../submodules/greatest/contrib/greenest
	@file /tmp/ansilove-test.png | grep PNG

do-hl-test:
	@cd ./build/. && ./hl-test/hl-test -v | ../submodules/greatest/contrib/greenest

do-meson: 
	@eval cd . && {  meson build || { meson build --reconfigure || { meson build --wipe; } && meson build; }; }

do-build:
	@eval cd . && { ninja -C build; }
	@eval cd . && { ninja test -C build -v; }

build: do-meson do-build

uncrustify:
	@$(UNCRUSTIFY) -c etc/uncrustify.cfg --replace $(TIDIED_FILES) 
#	@shfmt -w scripts/*.sh

uncrustify-clean:
	@find  . -type f -name "*unc-back*"|xargs -I % unlink %

fix-dbg:
	@$(SED) 's|, % s);|, %s);|g' -i $(TIDIED_FILES)
	@$(SED) 's|, % lu);|, %lu);|g' -i $(TIDIED_FILES)
	@$(SED) 's|, % d);|, %d);|g' -i $(TIDIED_FILES)
	@$(SED) 's|, % zu);|, %zu);|g' -i $(TIDIED_FILES)

tidy: uncrustify uncrustify-clean fix-dbg add-meson-deps

add-meson-deps:
	@git add meson/deps/*/meson.build

dev-all: all

pull:
	@git pull


dev: nodemon
nodemon:
	@$(PASSH) -L .nodemon.log $(NODEMON) -V -i build \
		-i submodules \
		-w "subprojects/*.wrap" -w . -w '*/meson.build' --delay 1 -i '*/subprojects' -I  -w 'include/*.h' -w meson.build -w src -w Makefile -w loader/meson.build -w loader/src -w loader/include -i '*/embeds/*' \
		-e wrap,tpl,build,sh,c,h,Makefile \
		-x env -- bash -c 'make||true'


git-pull:
	@git pull --recurse-submodules
git-submodules-pull-master:
	@git submodule foreach git pull origin master --jobs=10
git-submodules-update:
	@git submodule update --init	
