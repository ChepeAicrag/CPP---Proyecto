#include <FFT.hpp>

#include <iostream>
#include <vector>
#include <complex>
#include <math.h>

using namespace std;
using Complex = complex<double>;

// Recibe la señal y le aplica 
vector<complex<double>> FFT ::calculoFFT(const vector<complex<double>> &x)
{
    vector<complex<double>> output2(x);
    vector<complex<double>> output;
    //output = fft(output2);
    return fft(output2);
}

// Retorna vector de los valores de tiempo de la señal DIT
vector<complex<double>> FFT ::fft(vector<complex<double>> &x)
{

    /* 

    Intento de calculo de frecuencia 

    int N = x.size();
    if(N == 1) return x;
    int p = N / 2;

    vector<complex<double>> even(p,0);
    vector<complex<double>> odd(p,0);

    for (int i = 0; i != p; i++){
        even[i] = x[ 2 * i ];
        odd[i] = x[ 2 * i + 1];
    }
    vector <complex<double>> feven(p, 0);
    feven = fft(even);
    vector <complex<double>> fodd(p, 0);
    fodd = fft(odd);
    
    vector<complex<double>> output(N, 0);

    for (int i = 0; i < N; i++){
        output[i] = feven[i] + fodd[i] * w_n_k(N, i);
        output[i+p] = feven[i] - fodd[i] * w_n_k(N, i);
    }
    return output;
    */

    int n = 1 << log2n;
    for (unsigned int i = 0; i < n; ++i)
        A[bitReverse(i, log2n)] = a[i];
    const complex<double> J(0, 1);
    for (int s = 1; s <= log2n; ++s)
    {
        int m = 1 << s, m2 = m >> 1;
        Complex w(1, 0), wm = exp(-J * (M_PI / m2));
        for (int j = 0; j < m2; ++j)
        {
            for (int k = j; k < n; k += m)
            {
                Complex t = w * A[k + m2];
                Complex u = A[k];
                A[k] = u + t;
                A[k + m2] = u - t;
            }
            w *= wm;
        }
    }
}

// Retorna el calculo del factor de acuerdo a N y a K
complex<double> FFT ::w_n_k(int N, int k)
{
    return complex<double>(cos(2 * M_PI * k / N), -sin(2 * M_PI * k / N));
}

// Retorna el inverso de bits de un determinado numero
unsigned int FFT ::bitReverse(unsigned int x, int log2n)
{
    int n = 0;
    for (int i = 0; i < log2n; i++)
    {
        n <<= 1;
        n |= (x & 1);
        x >>= 1;
    }
    return n;
}