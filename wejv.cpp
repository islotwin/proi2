
//
//  wejv.cpp
//  p2sem2vol2
//
//  Created by Iga on 04.05.2016.
//  Copyright © 2016 Iga Slotwinska. All rights reserved.
//

#include "wejv.hpp"

lista *  czytajPlik (string tytul)
{   std::ifstream plik;
    plik.open(tytul +".wav", std::ios::in | std::ios::binary);
              plik.seekg(0);
              unsigned long int cos=0, temp=0, hz=0;
              int kanal=0, bajt=0;
              unsigned long znacznik=0, rozmiar=0;// licz=0;
              plik.seekg(20);
              znacznik=20;
              plik.read((char *)&cos, 2);
              //cout<<"pcm "<<cos<<std::endl;
              if(cos !=1)
              return NULL;
              znacznik+=2;
              plik.read((char *)&kanal, 2);
              //cout<<"kanaly "<<kanal<<std::endl;
              znacznik+=2;
              plik.read((char *)&hz, 2);
              //cout<<"Hz "<<hz<<std::endl;
              znacznik+=2;
              plik.read((char *)&cos, 2);
              znacznik+=2;
              plik.seekg(34);
              znacznik=34;
              plik.read((char *)&bajt, 2);
              znacznik+=2;
              bajt/=8;
              //cout<<"bajty "<<bajt<<std::endl;

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
              //cout<<znacznik<<" "<<rozmiar<<std::endl;
              znacznik=0;
              cos=0; //dlaczego musi byc wyzerowany??
              lista * tab= new lista;
              if(kanal==1)
              {
                  while (znacznik<rozmiar)
                  {
                      plik.read((char *)&cos, bajt);
                      tab->dodajElement(cos);
                      //   tab.push_back(0);
                      // tab.push_back(complex <double> (cos, 0));
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
                      // tab.push_back(0);
                      // tab.push_back(complex <double> (cos, 0));
                      znacznik+=2;
                  }
              }
              //cout<<"tab"<<tab[384*2+88];
              plik.close();
              return tab;
              }
