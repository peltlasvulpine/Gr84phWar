# ----------------------------
# Makefile Options
# ----------------------------

NAME = GR84PHWR
ICON = icon.png
DESCRIPTION = "Kill your enemies with the power of MATH!"
COMPRESSED = YES

CFLAGS = -Wall -Wextra -Oz
CXXFLAGS = -Wall -Wextra -Oz

# ----------------------------

include $(shell cedev-config --makefile)

gfx:
	cd src/gfx && \
	convimg

gfxclean:
	cd src/gfx && \
	rm -f *.c *.h *.lst

all: gfx
