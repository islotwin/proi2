#include "ofApp.h"
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
    odleglosc = sqrt(((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)));
    return odleglosc;
}
//--------------------------------------------------------------
void ofApp::setup()
{
    tab=czytajPlik();
    verdana.load("verdana.ttf", 14);
    song.load("/Users/iga/Desktop/paul.wav");
    song.play();
}

//--------------------------------------------------------------
void ofApp::update(){
    opoznienieP=opoznienie;
    if((j+rozmiar)<tab->wielkoscListy)
    {
        for ( i=0; i<rozmiar; i++)
        {
            test[i].real(tab->pobierzElement());
            test[i].imag(0);
        }
        
        fftPoprzednie=fftAktualne;
        fftAktualne=fft2(test);
        opoznienie--;
        
        if(opoznienie<=0 && ((fftAktualne-fftPoprzednie)>prog))//tu bedzie if klik==true, koniec gry :(
        {
            klik=TRUE;
            opoznienie=35;
        }
        
        do{
            czasp=czas;
            czas=song.getPositionMS();
            if (czasp>czas) ofExit();
        }        while(czasp==czas );

    }
    else
    {
     //   for(opoznienie=1000; opoznienie>0;opoznienie--){}
        ofExit();
    }
    //exit do poprawy - juz powinno byc ok
    j+=rozmiar;
    if(opoznienie==35)
    {
        xCircle=(int)fftAktualne%(1024-(opoznienie+50));
        yCircle=(int)fftAktualne%(768-(opoznienie+50));
        if(xCircle<(opoznienie+50))
        {
            xCircle+=opoznienie+50;
        }
        if(xCircle>(1024-(opoznienie+50)))
        {
            xCircle-=opoznienie+50;
        }
        if(yCircle<(opoznienie+50))
        {
            yCircle+=opoznienie+50;
        }
        if(yCircle>(768-(opoznienie+50)))
        {
            yCircle-=opoznienie+50;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(225);
    verdana.drawString("score: "+ofToString(wynik)+"", 30, 35);

    ofSetHexColor(0xffffff);
    
    if(opoznienie>(-50))
        ofDrawCircle(xCircle, yCircle, opoznienie+50);
    //koleczka np modulo rozmiar okienka - jakies brzegowe wartosci (50+20)

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
if(odleglosc(xCircle, yCircle, x, y)<=(opoznienie+50) && klik)
{
    wynik++;
    klik=FALSE;
}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
