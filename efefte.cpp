//
//  efefte.cpp
//  p2sem2vol2
//
//  Created by Iga on 06.05.2016.
//  Copyright © 2016 Iga Slotwinska. All rights reserved.
//

#include "efefte.hpp"

// Cooley-Tukey FFT (in-place, breadth-first, decimation-in-frequency)
// Better optimized but less intuitive
double fft2(Complex x[])
{
    // DFT
    double wynik=0;
    unsigned int N = rozmiar, k = N, n, a, b, l;
    unsigned int m = (unsigned int)log2(N);
    unsigned int zakres=512;
    double thetaT = 3.14159265358979323846264338328L / N;
    Complex phiT = Complex(cos(thetaT), sin(thetaT)), T, t;
    while (k > 1)
    {
        n = k;
        k >>= 1;
        phiT = phiT * phiT;
        T = 1.0L;
        for ( l = 0; l < k; l++)
        {
            for (a = l; a < N; a += n)
            {
                b = a + k;
                t = x[a] - x[b];
                x[a] += x[b];
                x[b] = t * T;
            }
            T *= phiT;
        }
    }
    for (a = 0; a < N; a++)
    {
        b = a;
        b = (((b & 0xaaaaaaaa) >> 1) | ((b & 0x55555555) << 1));
        b = (((b & 0xcccccccc) >> 2) | ((b & 0x33333333) << 2));
        b = (((b & 0xf0f0f0f0) >> 4) | ((b & 0x0f0f0f0f) << 4));
        b = (((b & 0xff00ff00) >> 8) | ((b & 0x00ff00ff) << 8));
        b = ((b >> 16) | (b << 16)) >> (32 - m);
        if (b > a)
        {
            Complex t = x[a];
            x[a] = x[b];
            x[b] = t;
        }
    }
    for (a=0; a<zakres; a++) {
        wynik+=(abs(x[a])/zakres);
    }
    return wynik;
}
