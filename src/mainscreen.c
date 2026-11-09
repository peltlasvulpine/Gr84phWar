#include <graphx.h>
#include "mainscreen.h"
#include "keys.h"
#include "gfx/gfx.h"

#define BACKGROUND 0x8F
#define SELECT 0x4D
#define OUTLINE 0x2B
#define INFILL 0xFF
#define TEXTFG 0x00

void MainScreenSelect(int selected){
    gfx_FillScreen(BACKGROUND);

    gfx_RLETSprite(logo, 4, 30);

    switch (selected){
        case 1:
            gfx_SetColor(SELECT);
            gfx_Rectangle(144, 112, 31, 11);
            gfx_SetColor(OUTLINE);
            gfx_Rectangle(144, 125, 31, 11);
            break;
        case 2:
            gfx_SetColor(OUTLINE);
            gfx_Rectangle(144, 112, 31, 11);
            gfx_SetColor(SELECT);
            gfx_Rectangle(144, 125, 31, 11);
            break;
    }

    gfx_SetColor(INFILL);
    gfx_FillRectangle(145, 113, 29, 9);
    gfx_FillRectangle(145, 126, 29, 9);

    gfx_SetTextFGColor(TEXTFG);
    gfx_SetTextBGColor(INFILL);
    gfx_PrintStringXY("Play", 146, 114);
    gfx_PrintStringXY("Exit", 146, 127);

    gfx_SwapDraw();
}
