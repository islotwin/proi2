#pragma once

#ifndef efefte_hpp
#define efefte_hpp

#include <complex>
#include <iostream>
#include "ofMain.h"


typedef std::complex<double> Complex;
class efefte
{
public:
    const static unsigned int rozmiar = 1024;
    double fft2(Complex x[]);
    
};
#endif /* efefte_hpp */
