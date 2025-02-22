#include "mainmenu.h"

MainMenu::MainMenu(GyverOLED<SSH1106_128x64>* oled, Mothership* m) {
    this->oled = oled;
    this->m = m;
}

void MainMenu::renderInterface() {
    this->oled->invertText(true);
    this->oled->println("MOTHERSHIP");
    this->oled->invertText(false);
    this->oled->println("MOscillator");
    this->oled->println("Settings");
}