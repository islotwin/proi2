#pragma once

#include "wejv.hpp"
#include "menu.h"
#include <vector>


class ofApp : public ofBaseApp{

public:
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

    

    ofFmodSoundPlayer song;
    lista * tab;
    Complex test[rozmiar];
    ofTrueTypeFont	verdana, verdana_Big;
    long int wynik=0;
    int i=0,j=0, pocz=0,temp=0;
    int czas=0, czasp=0, opoznienie=20, opoznienieP=40;
    int xCircle=512, yCircle=384;
    double fftAktualne=0.0, fftPoprzednie=0.0, prog=60000;
    bool klik=FALSE;
    int start = 2;
    int dodajodejmij = -1;
    int rysuj_Plusa;
    char znak = '0';
    int menu = 1;
    int etap = 0;
    bool pierwszyraz=TRUE, roznica=TRUE, proba=TRUE;
    std::vector <int> bazax;
    std::vector <int> bazay;
    std::vector <float> bazar;
    string tytul;
    //enum klawiatura {u=278-(SZEROKOSC/2), i=434-(SZEROKOSC/2),o=590-(SZEROKOSC/2),p=746-(SZEROKOSC/2)};
};
