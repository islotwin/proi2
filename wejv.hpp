//
//  wejv.hpp
//  p2sem2vol2
//
//  Created by Iga on 04.05.2016.
//  Copyright � 2016 Iga Slotwinska. All rights reserved.
//
#pragma once

#ifndef wejv_hpp
#define wejv_hpp

#include <iostream>
#include <fstream>
#include <string>
#include "listaWynikow.hpp"

lista * czytajPlik (std::string);
class czytajPlika
{
    unsigned long int cos=0, temp=0, hz=0;
    int kanal=0, bajt=0;
    unsigned long znacznik=20, rozmiar=0;// licz=0;
    
public:
    std::string tytul;
    czytajPlika (std::string nazwa){tytul="/Users/iga/Desktop/"+nazwa +".wav";}
    std::ifstream plik;
    bool blad=0;
    void otworz ();
    void zamknij();
    lista * czytaj ();
};
#endif /* wejv_hpp */
