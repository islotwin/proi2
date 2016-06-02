#include "ofApp.h"
#define PROMIEN 90
#define PREDKOSC 15
#define ZMNIEJSZANIE 1
#define MAX_KOL 3
/**
jakis zarzadca do operowania na danych tzn. obrazki, dzwieki
wyjatki w przypadku bledu w danych, np. nie da sie odczytac pliku (oczywiscie odpowiednio trzeba je obsluzyc)
trzeba zbudowac sobie jakas klase gry i poprzenosic te rzeczy z ofapp?
2 tryb gry -> nutki z gory
ogolnie obudowac w klasy Wave, FFT, itd.
koleczka tez mozna zamknac w klase tzn. zbudowac klase -> Note -> po niej dziedzicza kolka, linie i jakies inne wyimaginowane ksztalty
jakis taki interfejs dla uzytownika, z wyborem co chce robic? (zacznij wyjdz itp.)
*/
//--------------------------------------------------------------
float ofApp::odleglosc(int x1, int y1, int x2, int y2)
{
	float odleglosc;
	odleglosc = sqrt(((x1 - x2)*(x1 - x2)) + ((y1 - y2)*(y1 - y2)));
	return odleglosc;
}
//--------------------------------------------------------------
void ofApp::setup()
{
	//tab = czytajPlik();
	verdana.load("verdana.ttf", 14);
}

//--------------------------------------------------------------
void ofApp::update() {
	if (menu == 1 || etap == 0) {
		if (znak == '1')
		{
			etap = 1;
			menu = 0;
			znak = NULL;
		}
		if (znak == '2')
		{
			etap = 2;
			menu = 0;
			znak = NULL;
		}
	}
	if (menu==0 && start==1){
		if (znak == '1')
		{
			tytul = "Dubstep";
			start = 0;
			znak = NULL;
		}
		else if (znak == '2')
		{
			tytul = "Zachody";
			start=0;
			znak = NULL;
		}
		else if (znak == '3')
		{
			tytul = "Granda";
			start = 0;
			znak = NULL;
		}
		if (start == 0)
		{
			tab = czytajPlik(tytul); //jezeli tab==0 to blad
			song.load(tytul + ".wav");
		song.load(tytul + ".wav");
		song.play();
		}
	}
	else if (menu==0 && etap == 1 && start<=0)//OSU
	{
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
		if ( (fftAktualne - fftPoprzednie) > prog) //dodawanie nowego kolka jeżeli różnica > próg
		{
			if ( size(bazax) < MAX_KOL)//jeżeli jest więcej niż MAX_KOL to nie dodaje 
			{
				xCircle = (int)fftAktualne % (1024 - 2 * PROMIEN) + PROMIEN;
				yCircle = (int)fftAktualne % (768 - 2 * PROMIEN) + PROMIEN;

				bazax.push_back(xCircle);
				bazay.push_back(yCircle);
				bazar.push_back(PROMIEN);
			}
		}

		for (int i = 0; i < size(bazar); i++)//zmniejszanie wszystkich kol
			bazar[i] -= ZMNIEJSZANIE;

		for (int i = 0; i<size(bazar); i++)//usuwanie etych które zniknely
			if (bazar[i] <= 0)
			{
				bazax.erase(bazax.begin() + i);
				bazay.erase(bazay.begin() + i);
				bazar.erase(bazar.begin() + i);
				//wynik--;
			}
	}
	else if (menu == 0 && etap == 2 && start <= 0)//spadajace kolka
	{
		if ((j + rozmiar) < tab->wielkoscListy)
		{
			
			for (i = 0; i < rozmiar; i++)
			{
				test[i].real(tab->pobierzElement());
				test[i].imag(0);
			}

			fftPoprzednie = fftAktualne;
			fftAktualne = fft2(test);

			if ((fftAktualne - fftPoprzednie) > prog)//dodawanie nowego kolka jeżeli różnica > próg
			{
				if (size(bazax) < MAX_KOL)//jeżeli jest więcej niż MAX_KOL to nie dodaje 
				{
					bazax.push_back((int)fftAktualne % (1024 - 2 * PROMIEN) + PROMIEN);
					bazay.push_back(-PROMIEN);
					bazar.push_back(PROMIEN);

				}
			}

			for (int i = 0; i < size(bazay); i++)//przesuwanie wszystkich kół
				bazay[i] = bazay[i] + PREDKOSC;

			for (int i = 0; i<size(bazax); i++)//usuwanie etych które juz przelecialy
				if (bazay[i] > 858)
				{
					bazax.erase(bazax.begin() + i);
					bazay.erase(bazay.begin() + i);
					bazar.erase(bazar.begin() + i);
					//wynik--;
				}
			
			do {
				czasp = czas;
				czas = song.getPositionMS();
				if (czasp > czas) ofExit();
			} while (czasp == czas);

		}
		else
		{
			for (opoznienie = 1000; opoznienie > 0; opoznienie--) {}
			ofExit();
		}

		j += rozmiar;
		
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	if (menu==1 || etap==0){
		ofSetColor(225);
		verdana.drawString("Wybierz typ gry", 500, 200);
		verdana.drawString("kliknij 1. OSU", 500, 250);
		verdana.drawString("kliknij 2. Spadajace kolka", 500, 300);
		ofSetHexColor(0xffffff);
	}
	if (menu==0 && start == 1)
	{
		ofSetColor(225);
		verdana.drawString("Wybierz piosenke", 500, 200);
		verdana.drawString("kliknij 1. Dubpstep", 500, 250);
		verdana.drawString("kliknij 2. Zachody", 500, 300);
		verdana.drawString("kliknij 3. Granda", 500, 350);
		verdana.drawString("tytul " + ofToString(tytul) + " start " + ofToString(start) + "", 500, 400);
		ofSetHexColor(0xffffff);
	}
	if (menu==0 && etap == 1) {//OSU
//{
		ofSetColor(225);
		verdana.drawString("score: " + ofToString(wynik) + "", 30, 35);
		if (dodajodejmij == 1)
			verdana.drawString("+", 150, 35);
		else if (dodajodejmij == -1)
			verdana.drawString("-", 150, 35);//znak czy dodaje czy odejmuje
		verdana.drawString("j = " + ofToString(j) + "", 30, 55);
		verdana.drawString("opoznienie = " + ofToString(opoznienie) + "", 30, 75);
		verdana.drawString("fftAktualne = " + ofToString(fftAktualne) + "", 30, 95);
		verdana.drawString("rozmiar = " + ofToString(rozmiar) + "", 30, 115);
		verdana.drawString("klik = " + ofToString(klik) + "", 30, 135);
		verdana.drawString("menu = " + ofToString(menu) + "", 30, 155);
		verdana.drawString("start = " + ofToString(start) + "", 30, 175);
		if (size(bazar))
		verdana.drawString("bazar[0] " + ofToString(bazar[0]) + "", 30, 195);
		verdana.drawString("size(bazax) " + ofToString(size(bazax)) + "", 30, 215);
		ofSetHexColor(0xffffff);//wyswietlanie tekstow

		for (int i = 0; i < size(bazax); i++)
			ofDrawCircle(bazax[i], bazay[i], bazar[i]);
		//koleczka np modulo rozmiar okienka - jakies brzegowe wartosci (50+20)
	}
	if (menu == 0 && etap == 2) {//spadanie
		ofSetColor(225);
		verdana.drawString("score: " + ofToString(wynik) + "", 30, 35);
		if (dodajodejmij == 1)
			verdana.drawString("+", 150, 35);
		else if (dodajodejmij == -1)
			verdana.drawString("-", 150, 35);//znak czy dodaje czy odejmuje

		verdana.drawString("j = " + ofToString(j) + "", 30, 55);
		verdana.drawString("opoznienie = " + ofToString(opoznienie) + "", 30, 75);
		verdana.drawString("fftAktualne = " + ofToString(fftAktualne) + "", 30, 95);
		verdana.drawString("rozmiar = " + ofToString(rozmiar) + "", 30, 115);
		verdana.drawString("klik = " + ofToString(klik) + "", 30, 135);
		verdana.drawString("menu = " + ofToString(menu) + "", 30, 155);
		verdana.drawString("start = " + ofToString(start) + "", 30, 175);
		verdana.drawString("yCircle2 = " + ofToString(yCircle2) + "", 30, 195);
		verdana.drawString("yCircle2 = " + ofToString(yCircle2) + "", 30, 195);
		verdana.drawString("yCircle2 = " + ofToString(yCircle2) + "", 30, 195);
		verdana.drawString("size(bazax) = " + ofToString(size(bazax)) + "", 30, 215);


		ofSetHexColor(0xffffff);//wyswietlanie tekstow
		
		for (int i = 0; i < size(bazax); i++)
			ofDrawCircle(bazax[i], bazay[i], bazar[i]);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	znak = key;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	
	if (etap == 1){
		for (int i = 0; i<size(bazax); i++)
			if (odleglosc(bazax[i], bazay[i], x, y) <= bazar[i] && menu == 0)
			{
				bazax.erase(bazax.begin() + i);
				bazay.erase(bazay.begin() + i);
				bazar.erase(bazar.begin() + i);
				wynik++;
				dodajodejmij = 1;
			}
			else if (menu == 0) {
				//wynik--;
				//dodajodejmij = -1;
			}
	}
	else if (etap == 2) {
		for (int i = 0; i<size(bazax); i++)
			if (odleglosc(bazax[i], bazay[i], x, y) <= bazar[i] && menu == 0)
			{
				bazax.erase(bazax.begin() + i);
				bazay.erase(bazay.begin() + i);
				bazar.erase(bazar.begin() + i);
				wynik++;
				dodajodejmij = 1;
			}
		else if (menu == 0) {
			//wynik--;
			//dodajodejmij = -1;
		}
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
