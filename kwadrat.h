#pragma once

#ifndef _KWADRAT
#define _KWADRAT

//#include "ofMain.h"
#include <iostream>
#include "zmienne.h"

class Kwadrat :public zmienna
{

public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);

	
	int xSquare = 0, ySquare = 0;
	ofColor kolor;

	bool pierwszyraz = TRUE, roznica = TRUE, proba = TRUE;


	Kwadrat();//gdzie destruktory itd??
};

extern vector <Kwadrat *> kwadraty;
#endif


