#include "Osu.h"

vector <Kolo *> kolka;

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
        
    (fftAktualne<fftPoprzednie)? roznica=TRUE :NULL ;
        if(!proba)
        {
            roznica=FALSE;
        }
        if (((fftAktualne - fftPoprzednie) > prog) /*&& (bazax.size() < MAX_KOL)*/)//dodawanie nowego kolka jeøeli rÛønica > prÛg
        {
            //  if (bazax.empty() || (opoznienie <= 0))//jeøeli jest wiÍcej niø MAX_KOL to nie dodaje
            proba=(kolka.empty() || ((kolka.back()->promien)<=MIN_OGRANICZENIE));// && roznica==TRUE) );
            //roznica porownuje fftaktualne z fftpoprzednie - zeby nie tworzyl nowej nutki, jesli dzwiek tylko wzrasta - np jakas dluzsza nuta - trzeba ocenic jak to lapie i ewentualnie wrocic do opoznienie
            //majac ta roznice wlasciwie nie korzystam z MAX_KOL - w spadajacych kolkach
            //osu jest bez zmian
            if (proba)
            {
                Kolo * nowe_kolo = new Kolo;
                nowe_kolo->xCircle = (int)fftAktualne % (1024 - 2 * PROMIEN) + PROMIEN;
                nowe_kolo->yCircle = (int)fftAktualne % (768 - 2 * PROMIEN) + PROMIEN;
                
                if (kolka.size() > 0) 
		{
			cout << "jestem tu 1" << endl;
			while (odleglosc(nowe_kolo->xCircle, nowe_kolo->yCircle, kolka.back()->xCircle, kolka.back()->yCircle) < 2 * PROMIEN)
			{
				cout << "jestem tu 2" << endl;
				if (static_cast<float>(odleglosc(nowe_kolo->xCircle, 0, kolka.back()->xCircle, 0)) < 1.5 * static_cast<float>( PROMIEN))
				{
					cout << "jestem tu 3" << endl;
					if (kolka.back()->xCircle < 700)
						nowe_kolo->xCircle += 30;
					else
						nowe_kolo->xCircle -= 30;
				}
				else if (static_cast<float>(odleglosc(0, nowe_kolo->yCircle, 0, kolka.back()->yCircle)) < 1.5 * static_cast<float>( PROMIEN))
				{
					cout << "jestem tu 4" << endl;
					if (kolka.back()->yCircle < 500)
						nowe_kolo->yCircle += 30;
					else
						nowe_kolo->yCircle -= 30;
				}
			}
			while (odleglosc(nowe_kolo->xCircle, nowe_kolo->yCircle, kolka.back()->xCircle, kolka.back()->yCircle) > 4 * PROMIEN)
			{
				cout << "jestem tu 20 " << endl;
				if (static_cast<float>(odleglosc(nowe_kolo->xCircle, 0, kolka.back()->xCircle, 0)) > 2.8 * static_cast<float>( PROMIEN))
				{
					cout << "jestem tu 21 " << endl;
					if (nowe_kolo->xCircle - kolka.back()->xCircle > 0)
						nowe_kolo->xCircle -= 10;
					else
						nowe_kolo->xCircle += 10;
				}
				else if (static_cast<float>(odleglosc(0, nowe_kolo->yCircle, 0, kolka.back()->yCircle)) > 2.8 * static_cast<float>( PROMIEN))
				{
					cout << "jestem tu 22 " << endl;
					if (nowe_kolo->yCircle - kolka.back()->yCircle > 0)
						nowe_kolo->yCircle -= 10;
					else
						nowe_kolo->yCircle += 10;
				}
			}
		}
                
                nowe_kolo->promien = PROMIEN;
                nowe_kolo->czasKolka = TIME;
                nowe_kolo->kolor.set(ofRandom(255), ofRandom(255), ofRandom(255));
                kolka.push_back(nowe_kolo);
                roznica=FALSE;
            }
            //dodawanie nowego kolka je¿eli ró¿nica > próg
        }
    
    

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
		{
			ofSetColor(kolka[i]->kolor);
			ofDrawCircle(kolka[i]->xCircle, kolka[i]->yCircle, kolka[i]->promien);
		}
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

