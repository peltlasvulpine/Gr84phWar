#include "keys.h"
#include <keypadc.h>
#include <stdbool.h>

#define EXITKEY kb_KeyClear // use long key format

bool anyKeyDown(){
    kb_Scan();

    bool keyDown = false;
    for (int i = 0; i < 7; i++){
        if (kb_Data[i] != 0){
            keyDown = true;
            break;
        }
    }

    return keyDown;
}

int getDpad(){
    
    int key = 0;

    kb_Scan();
    if (kb_Data[7] != 0){
        if (kb_Data[7] & kb_Up){
            key = 1;
        }
        if (kb_Data[7] & kb_Left){
            key = 2;
        }
        if (kb_Data[7] & kb_Down){
            key = 3;
        }
        if (kb_Data[7] & kb_Right){
            key = 4;
        }
    }

    return key;
}

bool exitkey(){
    bool keydwn = false;
    kb_Scan();
    if(kb_IsDown(EXITKEY)){
        keydwn = true;
    }
    return keydwn;
}

bool exec(){
    bool execPressed = false;
    kb_Scan();
    if(kb_IsDown(kb_Key2nd) || kb_IsDown(kb_KeyEnter)){execPressed = true;}
    return execPressed;
}