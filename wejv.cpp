
#include "wejv.hpp"

void czytajPlika::otworz()
{
    plik.open(tytul, std::ios::in | std::ios::binary);
    if(!plik.is_open())
    {
        blad=1;
        //  throw blad;
    }
}

void czytajPlika::zamknij()
{
    plik.close();
}

lista * czytajPlika::czytaj()
{
    try
    {
        otworz();
        if(blad)
            throw blad;
    }
    catch (bool blad)
    {
        return NULL;
    }
   /* otworz();
    if(blad)
    {return NULL;}*/
    plik.seekg(20);
    plik.read((char *)&cos, 2);
    //cout<<"pcm "<<cos<<std::endl;
    if(cos !=1)
        return NULL;
    znacznik+=2;
    plik.read((char *)&kanal, 2);
    znacznik+=2;
    plik.read((char *)&hz, 2);
    znacznik+=2;
    plik.read((char *)&cos, 2);
    znacznik+=2;
    plik.seekg(34);
    znacznik=34;
    plik.read((char *)&bajt, 2);
    znacznik+=2;
    bajt/=8;
    while (1)
    {
        cos=0;
        plik.read((char *)&cos, 1);
        znacznik++;
        if(cos==100)
        {
            plik.read((char *)&cos, 1);
            znacznik++;
            if(cos==97)
            {
                plik.read((char *)&cos, 1);
                znacznik++;
                if(cos==116)
                {
                    plik.read((char *)&cos, 1);
                    znacznik++;
                    if(cos==97)
                    {
                        break;
                    }
                }
            }
        }
    }
    plik.read((char *)&rozmiar, 4);
    znacznik+=4;
    znacznik=0;
    cos=0; //dlaczego musi byc wyzerowany??
    lista * tab= new lista;
    if(kanal==1)
    {
        while (znacznik<rozmiar)
        {
            plik.read((char *)&cos, bajt);
            tab->dodajElement(cos);
            znacznik++;
        }
    }
    else
    {
        while (znacznik<rozmiar)
        {
            cos=0;
            plik.read((char *)&cos, bajt);
            temp=cos;
            plik.read((char *)&cos, bajt);
            cos=(cos+temp)/2;
            tab->dodajElement(cos);
            znacznik+=2;
        }
    }
    
    zamknij();
    return tab;
    
}
