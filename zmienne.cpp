//
//  zmienne.cpp
//  emptyExample
//
//  Created by Iga on 08.06.2016.
//
//

#include <stdio.h>
#include "zmienne.h"

Complex zmienna::test[efefte::rozmiar];
string zmienna::tytul;
ofFmodSoundPlayer zmienna::song;
lista * zmienna::tab;
ofTrueTypeFont	zmienna::verdana, zmienna::verdana_Big;


long int zmienna::wynik = 0;
int zmienna::i = 0, zmienna::j = 0, zmienna::pocz = 0, zmienna::temp = 0;
int zmienna::czas = 0, zmienna::czasp = 0, zmienna::opoznienie = 20, zmienna::opoznienieP = 40;
int zmienna::xCircle = 512, zmienna::yCircle = 384;
double zmienna::fftAktualne = 0.0, zmienna::fftPoprzednie = 0.0, zmienna::prog = 40000;
bool zmienna::klik = FALSE;
int zmienna::start = 2;
int zmienna::dodajodejmij = -1;
int zmienna::rysuj_Plusa;
char zmienna::znak = '0';
int zmienna:: menu = 1;
int zmienna::etap = 0;

//enum klawiatura {u=278-(SZEROKOSC/2), i=434-(SZEROKOSC/2),o=590-(SZEROKOSC/2),p=746-(SZEROKOSC/2)};

int zmienna::z_osu = 0, zmienna::z_kwadr = 0, zmienna::koniec = 0;

