#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	/*ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());*/
    ofFmodSoundPlayer song;
    clock_t time, czasPiosenki;
    lista * tab;
    Complex test[rozmiar];
    song.load("/Users/iga/Desktop/paul.wav");
    int i,j;
    int czas=0, czasp=0, opoznienie=10;
    double fftAktualne=0.0, fftPoprzednie=0.0, prog=80000;
    std::cout.setf ( std::ios::fixed );
    czasPiosenki=clock();
    tab=czytajPlik();
    czasPiosenki=clock()-czasPiosenki;
    std::cout<<((float)czasPiosenki)/CLOCKS_PER_SEC<<std::endl;
    song.play();
    czasPiosenki=clock();
  //  std::cout<<song.getPositionMS()<<std::endl;
    for( j=0; j+rozmiar<tab->wielkoscListy; j+=rozmiar)
    {
        //std::cout<<j<<" "<<((float)czasPiosenki)/CLOCKS_PER_SEC<<std::endl;
            for ( i=0; i<rozmiar; i++)
            {
                test[i].real(tab->pobierzElement());
                test[i].imag(0);
            }
      //  time = clock()-czasPiosenki;
        // std::cout<<"N = "<<data.size()<<std::endl;
        // forward fft
            fftPoprzednie=fftAktualne;
            fftAktualne=fft2(test);
            time=clock()-czasPiosenki;
        //czas=ofSoundPlayer::getPositionMS()
            opoznienie--;
            if(opoznienie<=0 && ((fftAktualne-fftPoprzednie)>prog))
            {
                std::cout<<" boom ";
                //std::cout<<fftPoprzednie<<"  "<<fftAktualne<<std::endl;
                opoznienie=10;
              //  std::cout<<((float)time)/CLOCKS_PER_SEC<<" sek"<<std::endl;
              //  std::cout<<czasp<<" "<<czas<<std::endl;
            }
        do{
            czasp=czas;
            czas=song.getPositionMS();
            if (czasp>czas) return 0;
        }        while(czasp==czas );

       // ofSoundUpdate();
    }
    
/*    i=0;
    while (j<tab.size())
    {
        test[i]=tab[j];
        j++;
        i++;
    }
    
    while (i<rozmiar)
    {
        test[i]=0;
        i++;
    }
    
    time = clock();
    CArray data(test, rozmiar);
   //   std::cout<<((float)time)/CLOCKS_PER_SEC<<" sek"<<std::endl;
    fft2(data);
    time=clock()-time;
*/
    /*std::cout.unsetf ( std::ios::fixed );
     std::cout << "fft" << std::endl;
     for (int i = 0; i < data.size(); ++i)
     {
     std::cout << data[i] << std::endl;
     }
     
     // inverse fft
     ifft(data);
     
     std::cout << std::endl << "ifft" << std::endl;
     for (int i = 0; i < data.size(); ++i)
     {
     std::cout << data[i] << std::endl;
     }*/
/*    while (song.isPlaying())
    {}
*/

    return 0;

}
