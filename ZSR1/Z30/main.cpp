//TP 2017/2018: ZSR 1, Zadatak 30
#include <iostream>
#include<cmath>
#include <limits>
bool DaLiJeProst (int n)
{
    if (n<=1) return false;
    int i;
    for(i=2; i<=std::sqrt(n); i++) {

        if(n%i==0) return false;

    }
    return true;
}
    int main () {
        int m;
        std::cout << "Unesite prirodan broj: ";
        std::cin >> m;
        int brojac=0;
        int i;
        for(i=2; i<=std::numeric_limits<int>::max(); i++) {

            if(DaLiJeProst(i)) brojac++;
            if(brojac==m) {

                std::cout<< i;
                return 0;
            }



        }
        return 0;
    }
