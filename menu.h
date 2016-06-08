#pragma once

#ifndef menu_h
#define menu_h

//#include "ofMain.h"
#include "zmienne.h"
#include "osu.h"
#include <exception>
//#include "osu.h"

class wyswietlMenu: public zmienna {
public:
    void setup();
    void draw();
    void update();
    void keyPressed(char key);


};
#endif
