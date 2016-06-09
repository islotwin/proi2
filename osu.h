#pragma once

#ifndef _OSU
#define _OSU


//#include "ofMain.h"
#include <iostream>
#include "zmienne.h"
#include "kwadrat.h"

class Kolo :public zmienna
{

public:
	void update();
	void draw();
	void keyPressed(int);
	void mousePressed(int, int, int);

	float odleglosc(int x1, int y1, int x2, int y2);


	int xCircle = 512, yCircle = 384;
	int promien;
	ofColor kolor;
	int czasKolka;
    bool pierwszyraz = TRUE, roznica = FALSE, proba = FALSE;
    
	Kolo();
};

extern vector <Kolo *> kolka;
#endif

