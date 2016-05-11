//
//  efefte.hpp
//  p2sem2vol2
//
//  Created by Iga on 06.05.2016.
//  Copyright © 2016 Iga Slotwinska. All rights reserved.
//

#ifndef efefte_hpp
#define efefte_hpp

#include <complex>
#include <iostream>
#include <valarray>
#include "ofMain.h"


const unsigned int rozmiar = 1024;

//const double PI = 3.141592653589793238460;

typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
void fft1(CArray& x);
double fft2(Complex x[]);
void ifft(CArray& x);

#endif /* efefte_hpp */
