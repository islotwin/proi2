#pragma once


#include "ofMain.h"
#include "listaWynikow.cpp"
#include "efefte.cpp"
#include "wejv.cpp"
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

const unsigned int rozmiar = 1024;

Complex test[rozmiar];
string tytul;
ofFmodSoundPlayer song;
lista * tab;
ofTrueTypeFont	verdana, verdana_Big;


long int wynik = 0;
int i = 0, j = 0, pocz = 0, temp = 0;
int czas = 0, czasp = 0, opoznienie = 20, opoznienieP = 40;
int xCircle = 512, yCircle = 384;
double fftAktualne = 0.0, fftPoprzednie = 0.0, prog = 60000;
bool klik = FALSE;
int start = 2;
int dodajodejmij = -1;
int rysuj_Plusa;
char znak = '0';
int menu = 1;
int etap = 0;

//enum klawiatura {u=278-(SZEROKOSC/2), i=434-(SZEROKOSC/2),o=590-(SZEROKOSC/2),p=746-(SZEROKOSC/2)};

int z_osu = 0, z_kwadr = 0, koniec = 0;

