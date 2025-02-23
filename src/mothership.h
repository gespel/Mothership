#pragma once
#include "menues/menu.h"
#include "menues/moscillator/moscillator.h"
#include "menues/main/mainmenu.h"
#include <stdlib.h>
#include <GyverOLED.h>

class Menu;

class Mothership {
public:
    Mothership(GyverOLED<SSH1106_128x64>* oled);
    void render();
    void setBrightness(int nb);
    void setMenu(int menuNr);
    void readInputs();
private:
    int brightness = 255;
    Menu* currentMenu;
    Menu* menues[16];
    GyverOLED<SSH1106_128x64>* oled;
};