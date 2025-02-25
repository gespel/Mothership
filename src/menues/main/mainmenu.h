#pragma once
#include "../menu.h"
#include "../../mothership.h"

class Menu;
class Mothership;

class MainMenu : public Menu {
public:
    MainMenu(GyverOLED<SSH1106_128x64>* oled, Mothership* m);
    void renderInterface();
    void northButtonPushed();
    void southButtonPushed();
    void westButtonPushed();
    void eastButtonPushed();
private:
    GyverOLED<SSH1106_128x64>* oled;
    Mothership* m;
    int selected = 0;
    void printMenuLines();
    void addMenuLine(std::string line);
    std::string menuLines[8];
    int numMenuLines = 0;
};