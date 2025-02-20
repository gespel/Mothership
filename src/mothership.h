#include "menues/menu.h"
#include "menues/moscillator/moscillator.h"
#include "menues/main/mainmenu.h"

class Mothership {
public:
    Mothership();
    void render();
private:
    Menu* currentMenu;
    Menu** menues;
};