#pragma once

#include "wejv.hpp"


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
        float odleglosc (int x1, int y1, int x2, int y2);
    
    ofFmodSoundPlayer song;
    lista * tab;
    Complex test[rozmiar];
    ofTrueTypeFont	verdana;
    long int wynik=0;
    int i=0,j=0, pocz=0;
    int czas=0, czasp=0, opoznienie=60, opoznienieP=40;
    int xCircle=512, yCircle=384;
    double fftAktualne=0.0, fftPoprzednie=0.0, prog=60000;
    bool klik=FALSE;
    int start = 2;
    int dodajodejmij = 0;
    char znak = '0';
    int menu = 1;
    int etap = 0;
    std::vector <int> bazax;
    std::vector <int> bazay;
    std::vector <int> bazar;

};
