#ifndef menu_h
#define menu_h

#include "ofMain.h"


class wyswietlMenu{
public:
    void setup();
    void draw();
    void update();
    void keyPressed(char key);

    int menu=1;
    int z_osu=0, z_kwadr=0,koniec=0;
};
#endif
