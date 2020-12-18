#include <iostream>

#include <vector>
#include <complex>

using namespace std;

class FFT
{

public:

    vector<complex<double>> calculoFFT(const vector<complex<double>> &);
    void  fft(vector<complex<double>> &a, vector<complex<double>> &b, int);
    unsigned int bitReverse(unsigned int, int);
};