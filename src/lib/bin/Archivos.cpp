#include <Archivos.hpp>

#include <fstream>
#include <vector>
#include <complex>
#include <string>

using namespace std;

void Archivos ::save(vector<complex<double>> output, string name)
{
    fstream file;
    file.open(name, fstream ::out);
    file << "Parte real \t\t Parte imaginaria" << endl;
    for (int i = 0; i < output.size(); i++)
        file << output[i].real() << "\t" << output[i].imag() << endl;
    file.close();
}
