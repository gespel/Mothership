#pragma once
#include "../menu.h"
#include "../../mothership.h"

class Mothership;

class MainMenu : public Menu {
public:
    MainMenu(GyverOLED<SSH1106_128x64>* oled, Mothership* m);
    void renderInterface();


private:
    GyverOLED<SSH1106_128x64>* oled;
    Mothership* m;
};