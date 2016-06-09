#pragma once

#ifndef listaWynikow_hpp
#define listaWynikow_hpp

#include <stdio.h>

class lista
{
public:
    struct wezel
    {
        double wartosc;
        wezel *nastepny=NULL;
    };
    wezel *poczatek=NULL;
    wezel *koniec=NULL;
    unsigned long wielkoscListy=0;
    lista() {}
    ~lista();
    void dodajElement( double wartosc);
    double pobierzElement();
};

#endif /* listaWynikow_hpp */
