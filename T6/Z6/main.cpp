/* 
    TP 2018/2019: Tutorijal 6, Zadatak 6
	
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
	int suma=0;
	for(int i=0; i<redovi;i++)
	suma+=m[i].size();
	try {
		p= new typename std::remove_reference<decltype(m[0][0])>::type* [redovi];

		p[0]=nullptr;
		p[0]=  new typename std::remove_reference <decltype(m[0][0])>::type [suma];
		for(int i=1; i<redovi;i++) p[i]=p[i-1]+m[i-1].size();
		for(int i=0; i<redovi; i++) {
			for(int j=0; j<m[i].size(); j++)
				p[i][j]=m[i][j];
		}
		}
	 catch(...) {
		delete [] p[0];
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
	delete [] p[0];
	delete [] p;
	}
	catch (...) {
		std::cout<<"Nedovoljno memorije";
	}
	return 0;
}
