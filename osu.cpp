#include "Osu.h"


Kolo::Kolo() {
}

float Kolo::odleglosc(int x1, int y1, int x2, int y2){
	float odleglosc;
	odleglosc = sqrt(((x1 - x2)*(x1 - x2)) + ((y1 - y2)*(y1 - y2)));
	return odleglosc;
}

void Kolo::setup() {
	verdana.load("verdana.ttf", 14);
	verdana_Big.load("verdana.ttf", 24);
}

void Kolo::update() {
    if (z_osu==1 && menu==0){
    opoznienieP = opoznienie;
	if ((j + rozmiar) < tab->wielkoscListy)
	{
		for (i = 0; i < rozmiar; i++)
		{
			test[i].real(tab->pobierzElement());
			test[i].imag(0);
		}

		fftPoprzednie = fftAktualne;
		fftAktualne = fft2(test);
		opoznienie--;

		/*
		if (opoznienie <= 0 && ((fftAktualne - fftPoprzednie) > prog))//tu bedzie if klik==true, koniec gry :(
		{
		klik = TRUE;
		opoznienie = 35;
		}*/

		do {
			czasp = czas;
			czas = song.getPositionMS();
			if (czasp > czas) ofExit();
		} while (czasp == czas);

	}
	else
	{
		//for (opoznienie = 1000; opoznienie > 0; opoznienie--) {}

		ofExit();
	}
	//exit do poprawy - juz powinno byc ok

	j += rozmiar;
	if ((fftAktualne - fftPoprzednie) > prog && kolka.size() < MAX_KOL)
	{
		Kolo * nowe_kolo = new Kolo;
		nowe_kolo->xCircle = (int)fftAktualne % (1024 - 2 * PROMIEN) + PROMIEN;
		nowe_kolo->yCircle = (int)fftAktualne % (768 - 2 * PROMIEN) + PROMIEN;
		nowe_kolo->promien = PROMIEN;
		nowe_kolo->czasKolka = TIME;
		kolka.push_back(nowe_kolo);
	}
	//dodawanie nowego kolka je¿eli ró¿nica > próg

	for (int i = 0; i < kolka.size(); i++)
	{
		kolka[i]->czasKolka = kolka[i]->czasKolka - 1;
		if (kolka[i]->promien >= MIN_OGRANICZENIE)
			kolka[i]->promien -= ZMNIEJSZANIE;
	}//zmniejszanie wszystkich kol wiêkszych od MIN_OGRANICZENIE

	for (int i = 0; i < kolka.size(); i++)
	{
		if (kolka[i]->czasKolka <= 0)
		{
			kolka.erase(kolka.begin() + i);

			wynik--;
			dodajodejmij = -1;
		}
	}//usuwanie tych które zniknely

    }
}

void Kolo::draw() {
	if (z_osu==1 && menu==0){
		for (i = 0; i<kolka.size(); i++)
			ofDrawCircle(kolka[i]->xCircle, kolka[i]->yCircle, kolka[i]->promien);
		ofSetColor(225);
		verdana.drawString("score: " + ofToString(wynik) + "", 30, 35);
		ofSetHexColor(0xffffff);
	}
}

void Kolo::keyPressed(int key){
	if (z_osu==1 && menu==0 && key=='e')
        	menu=4;
}

void Kolo::mousePressed(int x, int y, int button){
    if (z_osu==1 && menu == 0 && kolka.size()!=0 && odleglosc(kolka[0]->xCircle, kolka[0]->yCircle, x, y) <= kolka[0]->promien)//0 wymusza klikanie w kolejności
    {
        kolka.erase(kolka.begin());
        wynik++;
        dodajodejmij = 1;
    }
    else if (menu == 0) {
        //wynik--;
        //dodajodejmij = -1;
    }
}

