//TP 2018/2019: Tutorijal 8, Zadatak 6
#include <iostream>
template<typename TipElemenata>
struct Cvor {
    TipElemenata element;
    Cvor* veza;
};
template <typename TipElemenata>
Cvor<TipElemenata>*KreirajPovezanuListu(TipElemenata zavrsni)
{
    Cvor<TipElemenata>* pocetak=nullptr, *prethodni;
    for(;;) {

        TipElemenata varijabla;
        std::cin>>varijabla;
        if(varijabla==zavrsni) break;
        Cvor<TipElemenata>* novi;
        novi= new Cvor<TipElemenata> {varijabla, nullptr};
        if(!pocetak) pocetak=novi;
        else prethodni->veza=novi;
        prethodni=novi;

    }

    return pocetak;
}
template<typename TipElemenata>
int BrojElemenata(Cvor<TipElemenata> *pocetak)
{
    int duzina=0;
    for(Cvor<TipElemenata>* p=pocetak; p!=nullptr; p=p->veza)
        duzina++;
    return duzina;
}
template<typename TipElemenata>
TipElemenata SumaElemenata(Cvor<TipElemenata> *pocetak)
{
    TipElemenata suma={};
    for(Cvor<TipElemenata>* p=pocetak; p!=nullptr; p=p->veza) {
        suma+=p->element;
    }
    return suma;
}
template<typename TipElemenata>
int BrojVecihOd(Cvor<TipElemenata> *pocetak, TipElemenata prag)
{
    int brojac=0;
    for(Cvor<TipElemenata> *p=pocetak; p!=nullptr; p=p->veza) {
        if((p->element) > prag) brojac++;
    }
    return brojac;
}
template<typename TipElemenata>
void UnistiListu(Cvor<TipElemenata>* pocetak){
    Cvor<TipElemenata>* pomocni;

    for(Cvor<TipElemenata> *p=pocetak; p!=nullptr; p=pomocni){
        pomocni=p->veza;
        delete p;
        p=pomocni;
    }
}
int main ()
{
    std::cout << "Unesite slijed brojeva (0 za kraj): ";
    auto l =KreirajPovezanuListu<double>(0);
    double prosjek=SumaElemenata(l)/BrojElemenata(l);
    std::cout << "U slijedu ima " << BrojVecihOd(l, prosjek) << " brojeva vecih od njihove aritmeticke sredine";
    UnistiListu(l);
    return 0;
}
