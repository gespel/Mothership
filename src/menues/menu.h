#pragma once
#include <GyverOLED.h>

class Menu {
public:
    virtual void renderInterface() = 0;
    virtual void northButtonPushed() = 0;
    virtual void southButtonPushed() = 0;
    virtual void westButtonPushed() = 0;
    virtual void eastButtonPushed() = 0;
};