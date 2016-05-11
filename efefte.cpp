//
//  efefte.cpp
//  p2sem2vol2
//
//  Created by Iga on 06.05.2016.
//  Copyright © 2016 Iga Slotwinska. All rights reserved.
//

#include "efefte.hpp"
/*
// Cooley–Tukey FFT (in-place, divide-and-conquer)
// Higher memory requirements and redundancy although more intuitive
void fft1(CArray& x)
{
    const size_t N = x.size();
    if (N <= 1) return;
    
    // divide
    CArray even = x[std::slice(0, N/2, 2)];
    CArray  odd = x[std::slice(1, N/2, 2)];
    
    // conquer
    fft1(even);
    fft1(odd);
    
    // combine
    for (size_t k = 0; k < N/2; ++k)
    {
        Complex t = std::polar(1.0, -2 * PI * k / N) * odd[k];
        x[k    ] = even[k] + t;
        x[k+N/2] = even[k] - t;
    }
}
*/

// Cooley-Tukey FFT (in-place, breadth-first, decimation-in-frequency)
// Better optimized but less intuitive
double fft2(Complex x[])
{
    // DFT
    double wynik=0;
    unsigned int N = rozmiar, k = N, n, a,b;
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
        for (unsigned int l = 0; l < k; l++)
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
    // Decimate
    for (a = 0; a < N; a++)
    {
        b = a;
        // Reverse bits
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
    //// Normalize (This section make it not working correctly)
    //Complex f = 1.0 / sqrt(N);
    //for (unsigned int i = 0; i < N; i++)
    //	x[i] *= f;
    for (a=0; a<zakres; a++) {
        wynik+=(abs(x[a])/zakres);
    }
    return wynik;
}
/*
// inverse fft (in-place)
void ifft(CArray& x)
{
    // conjugate the complex numbers
    x = x.apply(std::conj);
    
    // forward fft
    fft2( x );
    
    // conjugate the complex numbers again
    x = x.apply(std::conj);
    
    // scale the numbers
    x /= x.size();
}
*/