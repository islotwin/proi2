#pragma once

#ifndef menu_h
#define menu_h

#include "zmienne.h"
#include "osu.h"
#include <exception>

class wyswietlMenu: public zmienna {
public:
    
    void draw();
    void update();
    void keyPressed(int key);


};
#endif
