#include <iostream>

#include <vector>
#include <complex>

using namespace std;

class FFT
{

public:

    vector<complex<double>> calculoFFT(const vector<complex<double>> &);
    vector<complex<double>>  fft(vector<complex<double>> &a);
    complex<double> w_n_k(int, int);
    unsigned int bitReverse(unsigned int, int);
};