//TP 2017/2018: Tutorijal 3, Zadatak 5
#include <iostream>
#include <deque>
std::deque<int> IzdvojiElemente (std::deque<int> v, bool parni)
{

    std::deque<int> novivektor;
    bool parnipom;
    for(int i=v.size()-1;i>=0;i--) {

        int sumcifara=0;
        int x=v.at(i);
        do {

            sumcifara+=x%10;
            x=x/10;


        } while(x!=0);
        if(sumcifara%2==0) parnipom=true;
        else parnipom=false;
        if(parnipom==parni) novivektor.push_front(v.at(i));


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
    std::deque<int> a;
    std::cout << "Unesite elemente: ";
    int element;
    for(int i=0; i<n; i++) {

        std::cin >> element;
        a.push_back(element);
    }
    std::deque<int> b = IzdvojiElemente(a,true);
    std::deque<int> c = IzdvojiElemente(a,false);

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
