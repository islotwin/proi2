#ifndef menu_h
#define menu_h

#include "ofMain.h"

#define PROMIEN 90
#define WYSOKOSC 100
#define SZEROKOSC 60
#define PREDKOSC 15
#define ZMNIEJSZANIE 0.9
#define MAX_KOL 4
#define POZIOM_LINII 400
#define MIN_OGRANICZENIE 45
#define TIME 80

class wyswietlMenu{
public:
    void setup();
    void draw();
    void update();
    void keyPressed(char key);

    int menu=1;
    int z_osu=0, z_kwadr=0,koniec=0;
	
	int czas = 0, czasp = 0, opoznienie = 20, opoznienieP = 40;
	long int wynik = 0;
	int i = 0, j = 0, pocz = 0, temp = 0;

	double fftAktualne = 0.0, fftPoprzednie = 0.0, prog = 40000;
	bool klik = FALSE;
	int start = 2;
	int dodajodejmij = -1;
	int rysuj_Plusa;
	char znak = '0';
	int menu = 1;
	int etap = 0;
	bool pierwszyraz = TRUE, roznica = TRUE, proba = TRUE;
	string tytul;
	//enum klawiatura {u=278-(SZEROKOSC/2), i=434-(SZEROKOSC/2),o=590-(SZEROKOSC/2),p=746-(SZEROKOSC/2)};

	ofFmodSoundPlayer song;
	lista * tab;
	Complex test[rozmiar];
	ofTrueTypeFont	verdana, verdana_Big;
};
#endif
