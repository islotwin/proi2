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
#include "ofMain.h"


const unsigned int rozmiar = 1024;


typedef std::complex<double> Complex;
double fft2(Complex x[]);

#endif /* efefte_hpp */
