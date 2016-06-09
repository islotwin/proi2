//#pragma once

#ifndef _ZMIENNE
#define _ZMIENNE

#include "efefte.hpp"
#include "wejv.hpp"
#include <vector>


#define PROMIEN 80
#define WYSOKOSC 100
#define SZEROKOSC 60
#define PREDKOSC 15
#define ZMNIEJSZANIE 1.1
#define MAX_KOL 4
#define POZIOM_LINII 400
#define MIN_OGRANICZENIE 45
#define TIME 90

class zmienna :public efefte
{
    public:
    static Complex test[rozmiar];
    static string tytul;
    static ofFmodSoundPlayer song;
    static lista * tab;
    static ofTrueTypeFont	verdana, verdana_Big;
    
    
    static long int wynik;
    static int i, j , pocz, temp;
    static int czas, czasp;
    static int xCircle , yCircle ;
    static double fftAktualne, fftPoprzednie, prog;
    static bool klik ;
    static int start;
    static int rysuj_Plusa;
    static char znak ;
    static int menu ;
    static int etap ;
    
    
    static int z_osu , z_kwadr , koniec ;
};
#endif /* wejv_hpp */
