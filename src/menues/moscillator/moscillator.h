#pragma once
#include "../menu.h"

class Menu;

class MOscilator : public Menu {
public:
    MOscilator();
    void renderInterface();
    void northButtonPushed();
    void southButtonPushed();
    void westButtonPushed();
    void eastButtonPushed();
private:

};