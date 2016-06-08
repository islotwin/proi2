#pragma once

//#include "wejv.hpp"
#include "osu.h"
#include "menu.h"
#include "kwadrat.h"


class ofApp : public ofBaseApp , public wyswietlMenu, public zmienna, public Kolo, public Kwadrat
{

public:
    wyswietlMenu w_menu;
    Kolo osu;
    Kwadrat spadanie;
    
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
   
};
