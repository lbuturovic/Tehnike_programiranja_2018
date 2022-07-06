//TP 2017/2018: Tutorijal 2, Zadatak 1
#include <iostream>
#include <vector>
#include <limits>
#include <cmath>
bool DaLiJeProst (int n)
{
    if (n<=1) return false;
    int i;
    for(i=2; i<=std::sqrt(n); i++) {

        if(n%i==0) return false;

    }
    return true;
} //2147483647
std::vector<int> ProstiBrojeviUOpsegu (int a, int b)
{
    std::vector<int> v;
    int i;
    for(i=a; i<=b; i++) {

        if(DaLiJeProst(i)) v.push_back(i);
        if(i==b) break;

    }

    return v;
}

int main ()
{
    std::cout << "Unesite pocetnu i krajnju vrijednost: ";
    int a, b;
    std::cin >> a >> b;
    std::vector<int> v;
    v=ProstiBrojeviUOpsegu(a,b);
    int i;
    if(v.size()==0) {
        std::cout << "Nema prostih brojeva u rasponu od " << a << " do " << b <<"!";
        return 0;
    }
    std::cout << "Prosti brojevi u rasponu od " << a <<" do " << b << " su:";
    for(i=0; i<v.size(); i++) {

        std::cout << " " << v.at(i);
        if(i!=v.size()-1) std::cout << ",";
        else std::cout << std::endl;
    }


    return 0;
}
