default: all
##############################################################
include submodules/c_deps/etc/includes.mk
##############################################################
TIDIED_FILES = \
			   hl*/*.h hl*/*.c \
			   png*/*.h png*/*.c \
			   ansilove*/*.h ansilove*/*.c \

##############################################################
local-test: do-clear test local-tests
local-tests: do-hl-test do-png-test do-ansilove-test

do-clear:
	@clear

do-png-test:
	@./build/png-test/png-test -v

do-ansilove-test:
	@cp ansilove-test/ansilove-test.c /tmp/.
	@unlink /tmp/ansilove-test.png 2>/dev/null||true
	@cd ./build/. && ./ansilove-test/ansilove-test -v
	@file /tmp/ansilove-test.png | grep PNG

do-hl-test:
	@cd ./build/. && ./hl-test/hl-test -v


hl-include-h:
	@./scripts/random-c-files.sh > .objs.json
	@j2 -f json -o .hl-i.h scripts/hl_include.h.j2 .objs.json && cat .hl-i.h
