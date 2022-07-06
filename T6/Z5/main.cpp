/*
    TP 2018/2019: Tutorijal 6, Zadatak 5

	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja
	i sugestije saljite na mail: khodzic2@etf.unsa.ba

	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak

*/
#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <type_traits>
template <typename Kontejner1>
auto KreirajDinamickuKopiju2D (Kontejner1 m)->typename std::remove_reference<decltype(m[0][0])>::type**
{
	typename std::remove_reference<decltype(m[0][0])>::type**  p;
	int redovi=m.size();
	
	try {
		p= new typename std::remove_reference<decltype(m[0][0])>::type* [redovi];
		for(int i=0; i<redovi; i++) p[i]=nullptr;
		for(int i=0; i<redovi; i++) p[i]=new typename std::remove_reference<decltype(m[0][0])>::type [m[i].size()];
		for(int i=0; i<redovi; i++) {
			for(int j=0; j<m[i].size(); j++)
				p[i][j]=m[i][j];
		}
	} catch(...) {
		for(int i=0; i<redovi; i++) delete [] p[i];
		delete [] p;
		throw;
	}

	return p;
}
int main ()
{
	try{
	int n;
	std::cout << "Unesite broj redova kvadratne matrice: ";
	std::cin >> n;
	std::vector<std::deque<int>> m(n,std::deque<int>(n));
	std::cout << "Unesite elemente matrice: ";
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++)
			std::cin >> m[i][j];
	}
	int **p=KreirajDinamickuKopiju2D(m);
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			std::cout << p[i][j] << " ";
		}
		std::cout << std::endl;
	}
	for(int i=0; i<n; i++) delete [] p[i];
	delete [] p;
	}
	catch (...) {
		std::cout<<"Nedovoljno memorije";
	}
	return 0;
}
