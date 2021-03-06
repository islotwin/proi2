#include "menu.h"

void wyswietlMenu::draw(){

    if (menu==1){
        ofSetColor(225);
        verdana.drawString("Wybierz typ gry", 500, 200);
        verdana.drawString("kliknij 1. OSU", 500, 250);
        verdana.drawString("kliknij 2. Spadajace kolka", 500, 300);
        ofSetHexColor(0xffffff);
    }
    if (menu==2){
        ofSetColor(225);
        verdana.drawString("Wybierz piosenke", 500, 200);
        verdana.drawString("kliknij 1. Crazy", 500, 250);
        verdana.drawString("kliknij 2. Kongos", 500, 300);
        verdana.drawString("kliknij 3. Amy", 500, 350);
        verdana.drawString("kliknij 4. Paul", 500, 400);
        verdana.drawString("tytul " + ofToString(tytul) + " start " + ofToString(start) + "", 500, 450);
        ofSetHexColor(0xffffff);
    }
    if (menu==3){
        ofSetColor(225);
        verdana.drawString("Trwa wczytywanie piosenki \"" + ofToString(tytul) + "\" ...", 500, 400);
        ofSetHexColor(0xffffff);
    }
    if (menu==4){
        ofSetColor(225);
        verdana.drawString("Koniec gry ", 500, 400);
        verdana.drawString("Twoj wynik: " + ofToString(wynik) + "",500,500);
        ofSetHexColor(0xffffff);
    }

}

void wyswietlMenu::update(){
    if (menu==3){
        tab = czytajPlik(tytul); //jezeli tab==0 to blad
        song.load(tytul + ".wav");
        song.play();
        menu=0;
    }
    if (menu==4){
        song.stop();
        //czekanie
        ofExit();
    }
}

void wyswietlMenu::keyPressed(char key){
    if( menu==1 && (key=='1'||key=='2') )
    if ( menu==1 && ( key=='1'||key=='2') ){
        menu=2;
        key=='1'? z_osu =1: z_kwadr=1;
    }
    if ( menu==2 && ( key=='1'||key=='2'||key=='3'||key=='4') ){
        if (znak == '1'){
            tytul = "/Users/iga/Desktop/bbking";
            start = 0;
            znak = NULL;
        }
        else if (znak == '2'){
            tytul = "/Users/iga/Desktop/kongos";
            start=0;
            znak = NULL;
        }
        else if (znak == '3'){
            tytul = "/Users/iga/Desktop/duffy";
            start = 0;
            znak = NULL;
        }
        else if (znak == '4'){
            tytul = "/Users/iga/Desktop/paul";
            start = 0;
            znak = NULL;
        }
    }

}
   