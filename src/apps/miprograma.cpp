#include <iostream>

#include <Archivos.hpp>
#include <DFT.hpp>
#include <FFT.hpp>

#include <vector>
#include <complex>
#include <math.h>

using namespace std;

int main(){
    // Instancia para el calculo clase DFT
    DFT dft;

    // Instancia para el calculo de la FFT 
    FFT fft;

    // Instancia para generar archivos
    Archivos archivo; 

    // Variables qie simulan los paramaetros de la señal
    double fs = 512 , N = 2*fs, ts = 1/fs, i = 0;

    // Vector de complejos que sera la señal
    vector<complex<double>> signal; 


    while(i < 2){
    
        //Señal que se simula:  0.5sen(10x)+sen(20x)+1.5sen(30x)
        complex <double> t (0.5*sin(10*i)+sin(20*i)+1.5*sin(30*i));

        // Agregamos el elemento al vector de la señal
        signal.push_back(t);

        // Incremento de la variable para las muestras
        i += ts;     
    }

    // Calculo de la DFT
    vector<complex<double>> output = dft.calculoDFT(signal);
    
    // Almacenamiento de la DFT calculada 
    archivo.save(output, "output.txt");

    // Aviso de DFT calculada
    cout << "DFT - Calculated" << endl;

    // Calculo de la FFT
    vector<complex<double>> output2 = fft.calculoFFT(signal);
    
    // Almacenamiento de la FFT calculada 
    archivo.save(output2, "output2.txt");
    
    // Aviso de DFT calculada
    cout << "FFT - Calculated" << endl;
    
    return 0;
}