/*
    TP 2018/2019: Tutorijal 6, Zadatak 1

	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja
	i sugestije saljite na mail: khodzic2@etf.unsa.ba

	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak

*/
#include <iostream>
#include <limits>
#include <cmath>
template <typename TipElementa>
TipElementa *GenerirajStepeneDvojke(int n)
{

	if (n<=0) throw std::domain_error("Broj elemenata mora biti pozitivan");
	TipElementa max=std::numeric_limits<TipElementa>::max();
	/*TipElementa min=std::numeric_limits<TipElementa>::min();*/
	if(powl(2,n-1)>max) throw std::overflow_error ("Prekoracen dozvoljeni opseg");
     // pitanje: kako bi najjednostavnije napravila gen fju sa pow za svaki tip
	 TipElementa *pok= new TipElementa [n];
	for(int i=0; i<n; i++) {
		pok[i]=pow(2,i);

	} /*catch(std::bad_alloc) {
		throw std::runtime_error ("Alokacija nije uspjela");
	}*/

	return pok;
}


int main ()
{
	int n;
	std::cout << "Koliko zelite elemenata: ";
	std::cin >> n;
	int max=std::numeric_limits<int>::max();
	int min=std::numeric_limits<int>::min();
	if(n>max && n<min) {
		std::cout << "Prekoracen dozvoljeni opseg";
		return 0;
	}
	try {
		int* niz(GenerirajStepeneDvojke<int>(n));
		for(int i=0; i<n; i++) {
			std::cout << (int)niz[i] << " ";

		}
		delete [] niz;
	} catch (std::domain_error d) {
		std::cout << "Izuzetak: " << d.what();

	} catch (std::overflow_error o) {
		std::cout << "Izuzetak: " << o.what();
	} /*catch(std::runtime_error r) {

			std::cout << r.what();
		}*/

	return 0;
}
