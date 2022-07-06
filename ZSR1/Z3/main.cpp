//TP 2017/2018: ZSR 1, Zadatak 3
/*Napišite program koji traži da se sa tastature unese neki podatak, a koji u zavisnosti od toga kakav 
je uneseni podatak ispisuje jedan od sljedećih pet k
omentara:
Uneseni podatak je prirodan broj.
Uneseni podatak je cijeli broj, ali nije prirodan.
Uneseni podatak je realan broj, ali nije cijeli.
Uneseni podatak nije broj.
Obavezno  testirajte  sve  navedene  slučajeve.
Uputa:   Prvo   probajte   unijeti 
podatak   u   realnu 
promjenljivu,  a  zatim  testirajte  ispravnost  ulaznog  toka.  Ukoliko  tok  nije  ispravan,  podatak  nije 
broj. Cijelost broja ćete testirati ispitivanjem da li se odsjecanjem decimala (tj. konverzijom u 
cjelobrojnu vrijenost) zadržava ista vrijed
nost*/
#include <iostream>

int main ()
{
    double br;
    std::cout <<"Unesite broj: ";
    std::cin >> br;
    if(!std::cin) {
       
        return 0;}
    int pom=(int) br;
    if(pom==br && pom>0) {
        
        std::cout << "Uneseni podatak je prirodan broj.";
        return 0;
    }
    if(pom==br && pom<=0) {
        
        std::cout <<"Uneseni podatak je cijeli broj, ali nije prirodan.";
        return 0;
    }
    std::cout << "Uneseni podatak je realan broj, ali nije cijeli.";
	return 0;
}
