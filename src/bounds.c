#include "bounds.h"
int bound(int val, int min, int max){
    int newval = val;
    if (val < min){
        newval = min;
    } else if (val > max){
        newval = max;
    }
    return newval;
}

int rollover(int val, int min, int max){
    int newval = val;
    if (val < min){
        newval = max;
    } else if (val > max){
        newval = min;
    }
    return newval;
}