#include "mothership.h"

Mothership::Mothership(GyverOLED<SSH1106_128x64>* oled) {
    Menu* mm = new MainMenu();
    Menu* mosc = new MOscilator();
    this->menues[0] = mm;
    this->menues[1] = mosc;
    this->currentMenu = mm;
    this->oled = oled;
}

void Mothership::render() {
    this->currentMenu->renderInterface();
}
