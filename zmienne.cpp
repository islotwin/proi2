//
//  zmienne.cpp
//  emptyExample
//
//  Created by Iga on 08.06.2016.
//
//

#include <stdio.h>
#include "zmienne.h"

Complex test[rozmiar];
string tytul;
ofFmodSoundPlayer song;
lista * tab;
ofTrueTypeFont	verdana, verdana_Big;


long int wynik = 0;
int i = 0, j = 0, pocz = 0, temp = 0;
int czas = 0, czasp = 0, opoznienie = 20, opoznienieP = 40;
int xCircle = 512, yCircle = 384;
double fftAktualne = 0.0, fftPoprzednie = 0.0, prog = 40000;
bool klik = FALSE;
int start = 2;
int dodajodejmij = -1;
int rysuj_Plusa;
char znak = '0';
int menu = 1;
int etap = 0;

//enum klawiatura {u=278-(SZEROKOSC/2), i=434-(SZEROKOSC/2),o=590-(SZEROKOSC/2),p=746-(SZEROKOSC/2)};

int z_osu = 0, z_kwadr = 0, koniec = 0;
