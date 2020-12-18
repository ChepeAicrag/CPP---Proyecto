#include <DFT.hpp>
#include <iostream>
#include <vector>
#include <complex>
#include <math.h>

using namespace std;

vector <complex<double>> DFT :: calculoDFT(const vector<complex<double>> &signal){
    complex <double> suma; 
    int k, n, N = signal.size();
    vector<complex<double>> dft;
    for(k = 0; k < N; k++){
        suma = complex <double> (0, 0);
        for(n = 0; n < N; n++){
            double ang = (2 * M_PI * k * n) / N;
            complex<double> w (cos(ang), - sin(ang));
            suma += signal[n] * w;
        }
        dft.push_back(suma);    
    }
    return dft;
}