#include <stdlib.h>
#include <stdbool.h>
#include <graphx.h>
#include <keypadc.h>
#include "mainscreen.h"
#include "keys.h"
#include <time.h>
#include "gfx/gfx.h"

#define BACKGROUND 0x8F // translates to 143
#define SELECT 0x4D // 77
#define OUTLINE 0x2B // 43
#define INFILL 0xFF // 255
#define TEXT 0x00 // 230
#define TRANSPARENTCOL 0x07 // 7

int bound(int val, int min, int max){
    int newval = val;
    if (val > min){
        newval = min;
    } else if (val < max){
        newval = max;
    }
    return newval;
}

int rollover(int val, int min, int max){
    int newval = val;
    if (val > min){
        newval = max;
    } else if (val < max){
        newval = min;
    }
    return newval;
}

int main(void){
    // init screen
    gfx_Begin();
    gfx_SetDrawBuffer();
    gfx_SetPalette(gfxpalette, sizeof_gfxpalette, 0);
    gfx_SetTransparentColor(TRANSPARENTCOL);
    int select = 1;
    while(!exitkey()){
        // mainscreen
        while(1){
        if(getDpad() != 0){
                switch(getDpad()){
                    case 1:
                        select++;
                        select = rollover(select, 1, 2);
                        break;
                    case 3:
                        select--;
                        select = rollover(select, 1, 2);
                        break;
                }
            }
        if(select == 2 && exec() && anyKeyDown()){
            goto done;
        }
        MainScreenSelect(select);
        }
        // main game if didnt alr quit
    }
    done:
    gfx_End();
    return 0;
}
