//TP 2016/2017: Tutorijal 1, Zadatak 1
#include <iostream>
#include <cmath>
int main ()
{
    int a, b, c;
    std::cout << "Unesite duzinu, sirinu i dubinu bazena u metrima: ";
    std::cin >> a >> b >> c;
    int d;
    std::cout << "Unesite sirinu plocice u centimetrima: " << std::endl;
    std::cin >> d;
    int pod=a*b*10000;
    int d2=d*d;
    int strana1=a*c*10000;
    int strana2=b*c*10000;
    if(pod%d2!=0 || strana1%d2!=0 || strana2%d2!=0 || (a*100)%d!=0 || (b*100)%d!=0 || (c*100)%d!=0)
    {
        
        std::cout <<"Poplocavanje bazena dimenzija " << a <<"x" << b << "x" << c << "m sa plocicama dimenzija " << d << "x" << d <<"cm" << std::endl <<"nije izvodljivo bez lomljenja plocica!";
        return 0;

    }
    int plocice;
    plocice=2*(strana1/d2 + strana2/d2) + pod/d2;
    std::cout << "Za poplocavanje bazena dimenzija " << a <<"x" << b << "x" << c << "m sa plocicama dimenzija " << d << "x" << d <<"cm" <<std::endl << "potrebno je " << plocice << " plocica.";
	return 0;
}