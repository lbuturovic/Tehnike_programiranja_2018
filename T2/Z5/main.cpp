#include <iostream>
#include <complex>
int main ()
{
    std::cout << "Unesi broj elemenata: "<< std::endl;
    int n;
    std::cin >> n;
    int i=0;
    std::complex<double> zk,zbir;
    zbir=std::complex<double> (0,0);
    double z, fi;
    double const PI=4*atan(1.);
    do {

        std::cout << "Z" << i+1 << " = ";
        std::cin >> z;
        std::cout << "fi" << i+1 << " = ";
        std::cin >> fi;
        fi=fi*PI/180;
        std::cout << std::endl;
        zk=std::polar(z,fi);
        zbir+=1./zk;
        i++;
    } while(i!=n);
    zbir=1./zbir;
    std::cout << "Paralelna veza ovih elemenata ima Z = " << std::abs(zbir)
              << " i fi = " << std::arg(zbir)*(180./PI) << ".";
    return 0;
}
