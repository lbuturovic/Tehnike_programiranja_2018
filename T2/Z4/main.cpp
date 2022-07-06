//TP 2017/2018: Tutorijal 2, Zadatak 4
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
    double Re, Im;
    do {

        std::cout << "R" << i+1 << " = ";
        std::cin >> Re;
        std::cout << "X" << i+1 << " = ";
        std::cin >> Im;
        std::cout << std::endl;
        z=std::complex<double>(Re,Im);
        zbir+=1./z;
        i++;
    } while(i!=n);
    zbir=1./zbir;
    std::cout << "Paralelna veza ovih elemenata ima R = " << zbir.real()
              << " i X = " << zbir.imag() << ".";
    return 0;
}
