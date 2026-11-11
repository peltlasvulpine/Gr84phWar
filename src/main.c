#include <stdlib.h>
#include <stdbool.h>
#include <graphx.h>
#include <keypadc.h>
#include <time.h>

#include "gfx/gfx.h"
#include "colors.h"
#include "bounds.h"
#include "keys.h"

#include "screens.h"

int main(void){
    // init screen
    gfx_Begin();
    gfx_SetDrawBuffer();
    gfx_SetPalette(gfxpalette, sizeof_gfxpalette, 0);

    gfx_SetTextTransparentColor(TEXTTRANSPARENT);
    gfx_SetTextFGColor(TEXTFG);
    gfx_SetTextBGColor(TEXTTRANSPARENT);
    
    int select = 1;
    while(!exitkey()){
        // homescreen
        bool dp[4] = {0};
        while(1){
            bool dpadDown = false;
            Dpad d = getDpad();
            for (int i = 0; i <= 6; i++){
                if (!d.dpad[i]){
                    dpadDown = true;
                    break;
                }
            }

            if (dpadDown){
                if (d.dpad[0] && !dp[0]){
                    select--;
                    select = rollover(select, 1, 2);
                } else if (d.dpad[2] && !dp[1]){
                    select++;
                    select = rollover(select, 1, 2);
                }
            }
            dp[0] = d.dpad[0];
            dp[2] = d.dpad[2];

            if(select == 1 && execkey()){break;}
            if((select == 2 && execkey()) || exitkey()){goto exit;}
            mainScreenSelect(select);
            }
        // config for main game
        GameSettings s = {0};
        s = gameSettingsScreen(s);
        if (s.exit){goto exit;} else {
            // for now, break
            break;
        }

    }
    exit:
        gfx_End();
        return 0;
}
