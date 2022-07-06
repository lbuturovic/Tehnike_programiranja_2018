/*
    TP 2018/2019: Tutorijal 6, Zadatak 2

	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja
	i sugestije saljite na mail: khodzic2@etf.unsa.ba

	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak

*/
#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <type_traits>
template <typename Itertip >
auto KreirajIzvrnutiNiz (Itertip pocetak, Itertip izakraja)-> typename std::remove_reference<decltype(*pocetak)>::type*
{

	typename std::remove_reference<decltype(*pocetak)>::type* poc;
	int n=0;
	Itertip pom1=pocetak;
	while(pom1!=izakraja) {
		pom1++;
		n++;
	}

	try {

		poc = new typename std::remove_reference<decltype(*pocetak)>::type [n];

	}

	catch(...) {
		throw;
	}
	for(int i=n-1; i>=0; i--) {

		poc[i]=*pocetak;
		pocetak++;
	}

	return poc;
}
int main ()
{
	std::cout << "Koliko zelite elemenata: ";
	int n;
	std::cin >> n;
	try {
		std::vector<double> v(n) ;
		std::cout << "Unesite elemente: ";
		for(int i=0; i<n; i++) {
			std::cin >> v.at(i);
		}
		double* a;
		a=KreirajIzvrnutiNiz(v.begin(),v.end());
		std::cout << "Kreirani niz: ";
		for(int i=0; i<n; i++)
			std::cout << a[i] << " ";
		delete [] a;
	} catch(...) {
		std::cout << "Nedovoljno memorije!";
	}
	return 0;
}
