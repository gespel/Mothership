#include "mainmenu.h"

MainMenu::MainMenu(GyverOLED<SSH1106_128x64>* oled, Mothership* m) {
    this->oled = oled;
    this->m = m;
    this->addMenuLine("MOscilator");
    this->addMenuLine("Settings");
}

void MainMenu::renderInterface() {
    this->oled->invertText(true);
    this->oled->println("MOTHERSHIP");
    this->oled->invertText(false);

    this->printMenuLines();
}

void MainMenu::northButtonPushed() {
    if(selected > 0) {
        selected--;
    }
}

void MainMenu::southButtonPushed() {
    if(selected < numMenuLines-1) {
        selected++;
    }
}

void MainMenu::westButtonPushed() {

}

void MainMenu::eastButtonPushed() {

}

void MainMenu::printMenuLines() {
    for(int i = 0; i < this->numMenuLines; i++) {
        if(selected == i) {
            this->oled->invertText(true);
        }
        this->oled->println(this->menuLines[i].c_str());
        if(selected == i) {
            this->oled->invertText(false);
        }
    }
}

void MainMenu::addMenuLine(std::string line) {
    this->menuLines[this->numMenuLines] = line;
    this->numMenuLines += 1;
}