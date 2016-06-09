#include "menu.h"

void wyswietlMenu::draw(){
    ofColor colorOne(225, 225, 225);
    ofColor colorTwo(133, 136, 137);
    ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_LINEAR);

    if (menu==1){
        ofSetColor(225);
        verdana_Big.drawString("Wybierz typ gry", 200, 200);
        verdana.drawString("kliknij 1. OSU", 220, 250);
        verdana.drawString("kliknij 2. Spadajace kolka", 220, 300);
        ofSetHexColor(0xffffff);
    }
    if (menu==2){
        ofSetColor(225);
        verdana_Big.drawString("Wybierz piosenke", 200, 200);
        verdana.drawString("kliknij 1. Crazy", 220, 250);
        verdana.drawString("kliknij 2. Kongos", 220, 300);
        verdana.drawString("kliknij 3. Amy", 220, 350);
        verdana.drawString("kliknij 4. Paul", 220, 400);
        ofSetHexColor(0xffffff);
    }
    if (menu==3){
        ofSetColor(225);
        verdana.drawString("Trwa wczytywanie piosenki \"" + ofToString(tytul) + "\" ...", 500, 400);
        ofSetHexColor(0xffffff);
    }
    if (menu==5){
        ofSetColor(225);
        verdana_Big.drawString("Koniec gry ", 400, 300);
        verdana_Big.drawString("Twoj wynik: " + ofToString(wynik) + "",400,400);
        verdana.drawString("Nacisnij dowolny klawisz, aby zakonczyc gre",500,700);
        
        ofSetHexColor(0xffffff);
    }

}

void wyswietlMenu::update(){
    if (menu==3){
        try
        {
        czytajPlika pliczek(tytul);
        
        tab = pliczek.czytaj(); //jezeli tab=>NULL to blad
        if (tab==NULL)
        {
            std::string blad="Nie odnaleziono piosenki";
            throw blad;
        }
        song.load("/Users/iga/Desktop/"+tytul + ".wav");
        song.play();
        menu=0;
        }
        catch(std::string blad)
        {
            menu=1;
            z_osu=0;
            z_kwadr=0;
            for (int i=0; i<20000; i++)
            {
                ofSetColor(225);
                verdana.drawString(blad, 500, 450);
                ofSetHexColor(0xffffff);
                
            }
        }
    }
    if (menu==5)
    {
        song.stop();
    }
    if (menu==4)
    {
        //song.stop();
        //czekanie
        ofExit();
    }
}

void wyswietlMenu::keyPressed(int key){
    znak=key;
    if ( menu==1 && ( key=='1'||key=='2') )
    {
        menu=2;
        (key=='1')? z_osu =1: z_kwadr=1;
    }
    else if ( menu==2 && ( (key=='1')||(key=='2')||(key=='3')||(key=='4')) )
    {
        if (znak == '1'){
            tytul = "nagranie";
            start = 0;
            znak = NULL;
            menu=3;
        }
        else if (znak == '2'){
            tytul = "kongos";
            start= 0;
            znak = NULL;
            menu=3;
            
        }
        else if (znak == '3'){
            tytul = "duffy";
            start = 0;
            znak = NULL;
            menu=3;
        }
        else if (znak == '4'){
            tytul = "paul";
            start = 0;
            znak = NULL;
            menu=3;
        }
    }
    else if ( menu==5 )
    {
        menu=4;
    }

}
   