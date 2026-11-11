# ----------------------------
# Makefile Options
# ----------------------------

NAME = GR84PHWR
ICON = icon.png
DESCRIPTION = "Destroy your enemies with the power of MATH!"
COMPRESSED = YES
ARCHIVED = YES
COMPRESSED_MODE = zx7

GFXDIR = src/gfx
CONVIMG = convimg -i convimg.yaml

CFLAGS = -Wall -Wextra -Oz
CXXFLAGS = -Wall -Wextra -Oz

# ----------------------------

.DEFAULT_GOAL := all

include $(shell cedev-config --makefile)
gfxclean:
	@echo "Removing old gfx sprites..."
	cd src/gfx && \
	rm -f *.c *.h *.lst
	@echo "Cleaned!"
gfxrefresh:
	@echo "Refreshing gfx sprites..."	
	$(MAKE) gfxclean
	@echo "Generating gfx sprites..."
	$(MAKE) gfx
	@echo "Generated!"
	@echo "Refreshed!"
all:
	$(MAKE) gfxrefresh
	$(MAKE) build
