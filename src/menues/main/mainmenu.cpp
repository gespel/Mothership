#include "mainmenu.h"

MainMenu::MainMenu(GyverOLED<SSH1106_128x64>* oled) {
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

void MainMenu::northButtonPushed() {

}

void MainMenu::southButtonPushed() {

}

void MainMenu::westButtonPushed() {

}

void MainMenu::eastButtonPushed() {

}