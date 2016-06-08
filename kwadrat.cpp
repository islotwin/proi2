#include "kwadrat.h"

Kwadrat::Kwadrat() {
}

void Kwadrat::setup() {
	verdana.load("verdana.ttf", 14);
	verdana_Big.load("verdana.ttf", 24);
}

void Kwadrat::update() {
    if (menu == 0 && z_kwadr==1)//spadajace kolka
        //moglyby wychodzic od srodka i strrzalkami by sie je klikalo (gora-dol-prawo-lewo)
    {
        if(pierwszyraz)
        {
            temp=(POZIOM_LINII+WYSOKOSC)/PREDKOSC;
            for(i=0; i<temp*rozmiar;i++)
            {
                tab->pobierzElement();
            }
            pierwszyraz=FALSE;
            temp=0;
        }
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
            (fftAktualne<fftPoprzednie)? roznica=TRUE :NULL ;
            if(!proba)
            {
                roznica=FALSE;
            }
            if (((fftAktualne - fftPoprzednie) > prog) /*&& (bazax.size() < MAX_KOL)*/)//dodawanie nowego kolka je¿eli ró¿nica > próg
            {
                //progi 280000 40000 500000 590000
              //  if (bazax.empty() || (opoznienie <= 0))//je¿eli jest wiêcej ni¿ MAX_KOL to nie dodaje
                proba=(bazax.empty() || (bazay.back()>=0 && roznica==TRUE));
                //roznica porownuje fftaktualne z fftpoprzednie - zeby nie tworzyl nowej nutki, jesli dzwiek tylko wzrasta - np jakas dluzsza nuta - trzeba ocenic jak to lapie i ewentualnie wrocic do opoznienie
                //majac ta roznice wlasciwie nie korzystam z MAX_KOL - w spadajacych kolkach
                //osu jest bez zmian
                if (proba)
                {
                    temp=(int)fftAktualne;
                    if(temp<=400000)
                    {temp=278-(SZEROKOSC/2);}
                    else if (temp <=450000)
                    {temp=434-(SZEROKOSC/2);}
                    else if (temp<=500000)
                    {temp=590-(SZEROKOSC/2);}
                    else
                    {temp=746-(SZEROKOSC/2);}
                    bazax.push_back(temp);
                    bazay.push_back(-WYSOKOSC); //-WYSOKOSC
                    bazar.push_back(WYSOKOSC);
                    opoznienie=10;
                    roznica=FALSE;
                }
            }

            for (int i = 0; i < bazay.size(); i++)//przesuwanie wszystkich kó³
                bazay[i] = bazay[i] + PREDKOSC;//musi sie zgrac z piosenka bedac dopiero na bazay~400
                                                //400/PREDKOSC ~26 => ok 26  razy musi sie zrobic fft
                                                //omijam 26*rozmiar fft
            for (int i = 0; i<bazax.size(); i++)//usuwanie tych które juz przelecialy
                if (bazay[i] > POZIOM_LINII)
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

void Kwadrat::draw() {
	if (z_kwadr=1 && menu==0){
        ofSetColor(225);
        verdana_Big.drawString("score: " + ofToString(wynik) + "", 30, 35);
        ofSetHexColor(0xffffff);//wyswietlanie tekstow

        ofDrawLine(200, 0, 200, 768);
        ofDrawLine(356, 0, 356, 768);
        ofDrawLine(512, 0, 512, 768);
        ofDrawLine(668, 0, 668, 768);
        ofDrawLine(824, 0, 824, 768);
        ofDrawLine(0, POZIOM_LINII-(WYSOKOSC), 1024, POZIOM_LINII-(WYSOKOSC));
        ofDrawLine(0, POZIOM_LINII, 1024, POZIOM_LINII);
        ofDrawLine(0, POZIOM_LINII+(WYSOKOSC), 1024, POZIOM_LINII+(WYSOKOSC));

        verdana_Big.drawString("1", 278-10, POZIOM_LINII+50);
        verdana_Big.drawString("2", 434-10, POZIOM_LINII+50);
        verdana_Big.drawString("3", 590-10, POZIOM_LINII+50);
        verdana_Big.drawString("4", 746-10, POZIOM_LINII+50);

        for (int i = 0; i < bazax.size(); i++)
            ofDrawRectangle(bazax[i], bazay[i], SZEROKOSC, bazar[i]);
    }
}

void Kwadrat::keyPressed(int key){
    if (z_kwadr == 1 && !(kwadraty.empty()))
    {
        temp=0;
        if(key=='1')
            {temp=278-(SZEROKOSC/2);}
        else if (key== '2')
            {temp=434-(SZEROKOSC/2);}
        else if (key=='3')
            {temp=590-(SZEROKOSC/2);}
        else if (key=='4')
            {temp=746-(SZEROKOSC/2);}

     //   for (int i = 0; i<bazax.size(); i++)
     //   {
        if(temp==bazax[0] &&( (POZIOM_LINII-bazay[0])<=WYSOKOSC))
           // if (odleglosc(bazax[0], bazay[0], POZIOM_LINII, bazay[0]) <= WYSOKOSC && menu == 0)
        {
            rysuj_Plusa =bazax.front();
            kwadraty.erase(bazax.begin());
            wynik++;
            //dodajodejmij = 5;
        }
        else if (menu == 0)
        {
                //wynik--;
            dodajodejmij = -1;
        }
      //  }
    }
}
