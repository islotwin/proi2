//
//  listaWynikow.cpp
//  p2sem2vol2
//
//  Created by Iga on 10.05.2016.
//  Copyright � 2016 Iga Slotwinska. All rights reserved.
//
#include "listaWynikow.hpp"

void lista::dodajElement( double wart)
{
    if(poczatek==NULL)
    {
        poczatek = new wezel;
        poczatek->wartosc=wart;
        koniec=poczatek;
    }
    else
    {
        koniec->nastepny= new wezel;
        koniec->nastepny->wartosc=wart;
        koniec=koniec->nastepny;
    }
    wielkoscListy++;
}

double lista::pobierzElement()
{
    double wart=0;
    wezel *temp;
    if(poczatek!=NULL)
    {
        wart=poczatek->wartosc;
        temp=poczatek->nastepny;
        delete poczatek;
        poczatek=temp;
    }
    return wart;
}

lista::~lista()
{
    while(poczatek!=NULL)
        pobierzElement();
}
