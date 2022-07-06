//TP 2017/2018: Tutorijal 2, Zadatak 3
#include <iostream>
#include <complex>
int main ()
{
    std::cout << "Unesite broj elemenata: "<< std::endl;
    int n;
    std::cin >> n;
    int i=0;
    std::complex<double> z,zbir;
    zbir=std::complex<double> (0,0);
    do {

        std::cout << "Z_" << i+1 << " = ";
        std::cin >> z;

        zbir+=1./z;
        i++;



    } while(i!=n);
    zbir=1./zbir;
    std::cout << std::endl <<"Paralelna veza ovih elemenata ima impedansu Z_ = " << zbir <<".";
    return 0;
}
