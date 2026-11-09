# ----------------------------
# Makefile Options
# ----------------------------

NAME = GR84PHWR
ICON = icon.png
DESCRIPTION = "Kill your enemies with the power of MATH!"
COMPRESSED = YES
ARCHIVED = YES
COMPRESSED_MODE = zx7

GFXDIR = src/gfx
CONVIMG = convimg -i convimg.yaml

CFLAGS = -Wall -Wextra -Oz
CXXFLAGS = -Wall -Wextra -Oz

# ----------------------------

include $(shell cedev-config --makefile)
gfxclean:
	cd src/gfx && \
	rm -f *.c *.h *.lst

all: gfx
