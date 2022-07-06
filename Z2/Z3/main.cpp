/* TP, 2018/2019
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
template <typename ItTip1, typename ItTip2, typename ItTip3>
ItTip3 SimetricnaRazlikaBlokova (ItTip1 p1, ItTip1 p2, ItTip2 p3, ItTip2 p4, ItTip3 p5)
{


    ItTip1 poc=p1;
    ItTip3 p6=p5;
    while(p1!=p2) {

        if(std::find(p3,p4,*p1)==p4) {

            if(std::find(p5,p6,*p1)==p6) {
                *p6=*p1;
                p6++;
            }
        }

        p1++;
    }
    p1=poc;
    while(p3!=p4) {
        if(std::find(p1, p2, *p3)==p2) {

            if(std::find(p5,p6,*p3)==p6) {
                *p6=*p3;
                p6++;
            }
        }


        p3++;
    }



    return p6;
}

int main ()
{
    int n;
    int niz [100];
    std::cout << "Unesite broj elemenata niza";
    std::cin >> n;
    std::cout<< std::endl;
    std::cout << "Unesite elemente niza";
    for(int i=0; i<n; i++) {
        std::cin>> niz[i];
    }
    std::cout << std::endl << "Unesite broj elemenata deka";
    int n2;
    std::cin>>n2;
    std::deque<int> d;
    int a;
    std::cout << std::endl;
    std::cout << "Unesite elemente deka";
    for(int i=0; i<n2; i++) {
        std::cin>> a;
        d.push_back(a);
    }
    std::vector<int> v(n2+n);
    auto kraj=SimetricnaRazlikaBlokova(niz, niz+n, d.begin(),d.end(), v.begin());
    v.resize(kraj-v.begin());
    std::cout << std::endl;
    if(v.size()==0) {
        std::cout << "Blokovi nemaju simetricnu razliku"; }
    else {
        std::cout << "Simetricna razlika blokova je:";
        for(int i=0; i<v.size(); i++) {
            std::cout <<" " << v.at(i);
        }
    }
    return 0;
}
