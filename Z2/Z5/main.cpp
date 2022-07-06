/* TP, 2018/2019
*/
#include <iostream>
#include <algorithm>
#include <deque>
template <typename ItTip, typename Funkcija>
bool ZaSve (ItTip poc, ItTip iza_kr, Funkcija krit )
{
    while(poc!=iza_kr) {
        if(!krit(*poc)) return false;

        poc++;
    }

    return true;

}
template<typename ItTip, typename Funkcija>
bool MakarJedan(ItTip poc, ItTip iza_kr, Funkcija krit)
{
    while(poc!=iza_kr) {
        if(krit(*poc)) return true;
        poc++;
    }

    return false;
}
template <typename ItTip, typename Funkcija>
auto Akumuliraj (ItTip poc, ItTip iza_kr, Funkcija f, typename std::remove_reference<decltype(*poc)>::type a=0)->typename std::remove_reference<decltype(*poc)>::type
{
    /*ItTip pom=poc;
    int br=0;
    while(poc!=iza_kr){
        poc++;
        br++;
    }
    poc=pom;*/
    if(poc==iza_kr) return a;
    typename std::remove_reference<decltype(*poc)>::type m=f(a,*poc);
    poc++;
    while(poc!=iza_kr) {
        m=f(m,*poc);
        poc++;
    }

    return m;
}
int main ()
{
    std::cout << "Unesite string: ";
    std::string str;
    std::getline(std::cin, str);
    if(ZaSve(str.begin(),str.end(), [] (char c) {
    return ((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9'));
    })) std::cout << "Uneseni string sadrzi samo slova i cifre";
    else std::cout << "Uneseni string sadrzi i druge znakove osim slova i cifara";
    std::cout << std::endl;
    std::cout << "Unesite niz od 10 brojeva: ";
    int niz[10];
    std::for_each(niz,niz+10, [] (int &br) {
        std::cin >> br;
    });
    if(MakarJedan(niz, niz+10, [](int a) {
    int pom=a;
        int s=0;
        do {
            s+=pom%10;
            pom=pom/10;
        } while(pom!=0);
        return (a%s==0);

    })) std::cout << "U nizu ima brojeva djeljivih sa sumom svojih cifara";
    else std::cout <<"U nizu nema brojeva djeljivih sa sumom svojih cifara";
    std::deque<double> d(10);
    std::cout << std::endl << "Unesite dek od 10 elemenata: ";
    std::for_each(d.begin(),d.end(), [] (double &m) {
        std::cin>>m;
    });
    double s=Akumuliraj(d.begin(),d.end(), [] (double a, double b) {
        return a+b;
    });
    double p=Akumuliraj(d.begin(),d.end(), [](double a, double b) {
        return a*b;
    },1);
    std::cout << std::endl;
    std::cout << "Suma deka: " << s << std::endl;
    std::cout <<"Produkt deka: " << p << std::endl;
    std::cout << "Najveci elemenat deka: ";
    std::cout << Akumuliraj(d.begin(),d.end(), [](double a, double b) {
        if(a>=b) return a;
        return b;
    },d.at(0));
    std::cout << std::endl <<"Najmanji elemenat deka: " << Akumuliraj(d.begin(),d.end(), [](double a, double b) {
        if(a<=b) return a;
        return b;
    },d.at(0));
    return 0;
}
