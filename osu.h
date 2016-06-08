#ifndef _OSU
#define _OSU
#include "ofMain.h"
#include "wejv.hpp"
#include "menu.h"
#include <vector>


class Kolo {

public:
	void setup();
	void update();
	void draw();
	void keyPressed(int);
	void mousePressed(int, int, int);

	float odleglosc(int x1, int y1, int x2, int y2);


	int xCircle = 512, yCircle = 384;
	int promien;
	ofColor kolor;
	int czasKolka;

	Kolo();
};

vector <Kolo *> kolka;
#endif

