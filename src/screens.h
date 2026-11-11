#ifndef SCREENS_H
#define SCREENS_H

typedef struct {
    int vs; // 1 for pvp, 2 for pve and 3 for eve
    int enemyCount;
    int teamCount;
    bool exit;
} GameSettings;

void mainScreenSelect(int selected);
void aboutScreen();
GameSettings gameSettingsScreen(GameSettings);


#endif