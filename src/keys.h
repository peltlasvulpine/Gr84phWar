#ifndef KEYS_H
#define KEYS_H
#include <stdbool.h>

#define EXITKEY kb_KeyClear // use long key format

typedef struct {
    bool dpad[4]; // 0, 1, 2, 3 ; up, left, down, right
} Dpad;

typedef struct {
    bool fkey[5]; // 0, 1, 2, 3, 4 ; y= , window, zoom, trace, graph
} FKeys;


bool anyKeyDown();
Dpad getDpad();
FKeys getFKeys();
bool exitkey();
bool execkey();

#endif