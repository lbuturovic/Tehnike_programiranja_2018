//TP 2017/2018: Tutorijal 2, Zadatak 2
#include <iostream>
#include <vector>
bool TestPerioda(std::vector<double> v, int p)
{
    if(p<=0) return false;
    if(p>=v.size()) return false;
    int i;
    for(i=0; i<v.size()-p; i++) {
        if(v[i]!=v[i+p]) return false;
    }

    return true;
}

int OdrediOsnovniPeriod (std::vector<double> v)
{

    int i;
    int j=1;
    for(i=1; i<v.size(); i++) {

        if(v[i]==v[0] && TestPerioda(v,i)) {

            return i;
        }


    }



    return 0;
}
int main ()
{
    std::vector<double> v;
    double broj;
    std::cout << "Unesite slijed brojeva (0 za kraj): ";
    do {

        std::cin >> broj;
        if(broj!=0) v.push_back(broj);
    } while(broj!=0);

    if(!OdrediOsnovniPeriod(v)) {
        std::cout << "Slijed nije periodican!";
        return 0;
    }
    std::cout << "Slijed je periodican sa osnovnim periodom " << OdrediOsnovniPeriod(v) <<".";

    return 0;
}
