#include <stdbool.h>
#include <graphx.h>

#include "screens.h"
#include "keys.h"
#include "colors.h"
#include "bounds.h"
#include "gfx/gfx.h"

void mainScreenSelect(int selected){
    gfx_FillScreen(BACKGROUND);

    gfx_RLETSprite(logo, 44, 30);

    switch (selected){
        case 1:
            gfx_SetColor(SELECT1);
            gfx_Rectangle(144, 112, 31, 11);
            gfx_SetColor(OUTLINE1);
            gfx_Rectangle(144, 125, 31, 11);
            break;
        case 2:
            gfx_SetColor(OUTLINE1);
            gfx_Rectangle(144, 112, 31, 11);
            gfx_SetColor(SELECT1);
            gfx_Rectangle(144, 125, 31, 11);
            break;
    }

    gfx_SetColor(INFILL1);
    gfx_FillRectangle(145, 113, 29, 9);
    gfx_FillRectangle(145, 126, 29, 9);

    gfx_SetTextScale(1, 1);
    gfx_PrintStringXY("Play", 146, 114);
    gfx_PrintStringXY("Exit", 146, 127);

    gfx_SwapDraw();
}

void aboutScreen(){
    // not implemented yet
}

GameSettings gameSettingsScreen(GameSettings g){
    Dpad d;
    FKeys f;
    g.vs = 2;
    g.enemyCount = 1;
    g.teamCount = 1;

    bool start = false;
    // detect if the button is alr down
    bool fk[4] = {0};
    bool dp[2] = {0};
    while(!start){
        gfx_FillScreen(BACKGROUND);

        gfx_SetTextScale(3, 3);
        gfx_PrintStringXY("Settings", 76, 3);

        gfx_SetTextScale(2, 2);
        gfx_PrintStringXY("Left team", 5, 29);
        gfx_PrintStringXY("Right team", 181, 29);

        gfx_SetTextScale(1, 1);
        // pvp
        if (exitkey()){goto exit;}
        gfx_SetColor(OUTLINE1);
        if (g.vs == 1){
            gfx_Rectangle(148, 43, 27, 11);
            gfx_Rectangle(148, 57, 27, 11);
            gfx_SetColor(SELECT1);
            gfx_Rectangle(148, 29, 27, 11);
        } else if (g.vs == 2){
            gfx_Rectangle(148, 29, 27, 11);
            gfx_Rectangle(148, 57, 27, 11);
            gfx_SetColor(SELECT1);
            gfx_Rectangle(148, 43, 27, 11);
        } else if (g.vs == 3){
            gfx_Rectangle(148, 29, 27, 11);
            gfx_Rectangle(148, 43, 27, 11);
            gfx_SetColor(SELECT1);
            gfx_Rectangle(148, 57, 27, 11);
        }

        gfx_SetColor(INFILL1);
        gfx_FillRectangle(149, 30, 23, 9);
        gfx_FillRectangle(149, 44, 23, 9);
        gfx_FillRectangle(149, 58, 23, 9);

        gfx_PrintStringXY("PvP", 150, 31);
        gfx_PrintStringXY("PvE", 150, 45);
        gfx_PrintStringXY("EvE", 150, 59);

        // team
        gfx_SetColor(OUTLINE1);
        for(int i = 0; i < g.teamCount; i++){
            gfx_Rectangle(5, 48 + (i * 22), 83, 20);
            gfx_RLETSprite(soldierlookleft, 7, 49 + (i * 22));
        }

        // enemy
        for(int i = 0; i < g.enemyCount; i++){
            gfx_Rectangle(232, 48 + (i * 22), 83, 20);
            gfx_RLETSprite(enemylookleft, 234, 49 + (i * 22));
        }

        gfx_SwapDraw();
        if (exitkey()){goto exit;}
        f = getFKeys();
        d = getDpad();

        if (anyKeyDown()){
            // vs
            if (d.dpad[0] && !dp[0]){
                g.vs--;
                g.vs = rollover(g.vs, 1, 3);
            }
            if (d.dpad[2] && !dp[1]){
                g.vs++;
                g.vs = rollover(g.vs, 1, 3);
            }

            // team
            if (f.fkey[0] && !fk[0]){
                g.teamCount++;
                g.teamCount = bound(g.teamCount, 1, 4);
            }
            if (f.fkey[1] && !fk[1]){
                g.teamCount--;
                g.teamCount = bound(g.teamCount, 1, 4);
            }

            // enemy
            if (f.fkey[2] && !fk[2]){
                g.enemyCount++;
                g.enemyCount = bound(g.enemyCount, 1, 4);
            }
            if (f.fkey[3] && !fk[3]){
                g.enemyCount--;
                g.enemyCount = bound(g.enemyCount, 1, 4);
            }

            //start
            if (f.fkey[4]){
                start = true;
            }
        }

        // memory so that it presses once
        for (int i = 0; i < 4; i++){fk[i] = f.fkey[i];}
        dp[0] = d.dpad[0];
        dp[1] = d.dpad[2]; 
    }
    return g;
    exit:
        g.exit = true;
        return g;
}