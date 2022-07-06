//TP 2017/2018: Tutorijal 3, Zadatak 2
#include <iostream>
#include <vector>
std::vector<int> IzdvojiElemente (std::vector<int> v, bool parni)
{

    std::vector<int> novivektor;
    bool parnipom;
    for(int clan : v) {

        int sumcifara=0;
        int x=clan;
        do {

            sumcifara+=x%10;
            x=x/10;


        } while(x!=0);
        if(sumcifara%2==0) parnipom=true;
        else parnipom=false;
        if(parnipom==parni) novivektor.push_back(clan);


    }

    return novivektor;

}

int main ()
{
    int n;
    std::cout << "Koliko zelite unijeti elemenata: ";
    std::cin >> n;
    if(n<=0) {
        std::cout << "Broj elemenata mora biti veci od 0!";
        return 0;
    }
    std::vector<int> a;
    std::cout << "Unesite elemente: ";
    int element;
    for(int i=0; i<n; i++) {

        std::cin >> element;
        a.push_back(element);
    }
    std::vector<int> b = IzdvojiElemente(a,true);
    std::vector<int> c = IzdvojiElemente(a,false);

    for(int i=0; i<b.size(); i++) {
        if(i!=b.size()-1) std::cout << b.at(i) << ",";
        else std:: cout << b.at(i);
    }
    std::cout << std::endl;
    for(int i=0; i<c.size(); i++) {
        if(i!=c.size()-1) std::cout << c.at(i) << ",";
        else std::cout << c.at(i);
    }

    return 0;
}
