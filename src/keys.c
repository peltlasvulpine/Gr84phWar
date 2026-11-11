#include "keys.h"
#include <keypadc.h>
#include <stdbool.h>

bool anyKeyDown(){
    kb_Scan();

    bool keyDown = false;
    for (int i = 0; i < 8; i++){
        if (kb_Data[i] != 0){
            keyDown = true;
            break;
        }
    }

    return keyDown;
}

Dpad getDpad(){
    
    Dpad pressed = {0};

    kb_Scan();
    if (kb_Data[7] != 0){
        if (kb_Data[7] & kb_Up){
            pressed.dpad[0] = true;
        }
        if (kb_Data[7] & kb_Left){
            pressed.dpad[1] = true;
        }
        if (kb_Data[7] & kb_Down){
            pressed.dpad[2] = true;
        }
        if (kb_Data[7] & kb_Right){
            pressed.dpad[3] = true;
        }
    }

    return pressed;
}

FKeys getFKeys(){
    
    FKeys pressed = {0};
    
    kb_Scan();
    if (kb_Data[1] != 0){
        if (kb_Data[1] & kb_Yequ){
            pressed.fkey[0] = true;
        }
        if (kb_Data[1] & kb_Window){
            pressed.fkey[1] = true;
        }
        if (kb_Data[1] & kb_Zoom){
            pressed.fkey[2] = true;
        }
        if (kb_Data[1] & kb_Trace){
            pressed.fkey[3] = true;
        }
        if (kb_Data[1] & kb_Graph){
            pressed.fkey[4] = true;
        }
    }

    return pressed;
}

bool exitkey(){
    bool keyDwn = false;
    kb_Scan();
    if(kb_IsDown(EXITKEY)){keyDwn = true;}
    return keyDwn;
}

bool execkey(){
    bool execPressed = false;
    kb_Scan();
    if(kb_IsDown(kb_Key2nd) || kb_IsDown(kb_KeyEnter)){execPressed = true;}
    return execPressed;
}