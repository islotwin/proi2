#include "ofApp.h"
#include "osu.h"
#include "menu.h"
#include "kwadrat.h"

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
wyswietlMenu w_menu;
Kolo osu;
Kwadrat spadanie;

void ofApp::setup()
{
    //verdana.load("verdana.ttf", 14);
    //verdana_Big.load("verdana.ttf", 24);
}

//--------------------------------------------------------------
void ofApp::update() {
    w_menu.update();
    osu.update();
    spadanie.update();

}


//--------------------------------------------------------------
void ofApp::draw() {
    w_menu.draw();
    osu.draw();
    spadanie.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    w_menu.keyPressed(key);
    osu.keyPressed(key);
    spadanie.keyPressed(key);
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
    osu.mousePressed(x,y,button);
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
