//#pragma once

#ifndef _ZMIENNE
#define _ZMIENNE

//#include "ofMain.h"
//#include "listaWynikow.hpp"
#include "efefte.hpp"
#include "wejv.hpp"
#include <vector>


#define PROMIEN 90
#define WYSOKOSC 100
#define SZEROKOSC 60
#define PREDKOSC 15
#define ZMNIEJSZANIE 0.9
#define MAX_KOL 4
#define POZIOM_LINII 400
#define MIN_OGRANICZENIE 45
#define TIME 80

//const unsigned int rozmiar = 1024;

extern Complex test[rozmiar];
extern string tytul;
extern ofFmodSoundPlayer song;
extern lista * tab;
extern ofTrueTypeFont	verdana, verdana_Big;


extern long int wynik;// = 0;
extern int i, j, pocz, temp;// = 0, j = 0, pocz = 0, temp = 0;
extern int czas, czasp, opoznienie, opoznienieP;// = 0, czasp = 0, opoznienie = 20, opoznienieP = 40;
extern int xCircle,yCircle;// = 512, yCircle = 384;
extern double fftAktualne, fftPoprzednie, prog;// = 0.0, fftPoprzednie = 0.0, prog = 60000;
extern bool klik;// = FALSE;
extern int start;// = 2;
extern int dodajodejmij;// = -1;
extern int rysuj_Plusa;
extern char znak;// = '0';
extern int menu;// = 1;
extern int etap;// = 0;

//enum klawiatura {u=278-(SZEROKOSC/2), i=434-(SZEROKOSC/2),o=590-(SZEROKOSC/2),p=746-(SZEROKOSC/2)};

extern int z_osu, z_kwadr, koniec;// = 0, z_kwadr = 0, koniec = 0;

#endif /* wejv_hpp */
