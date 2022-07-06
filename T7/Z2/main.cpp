/* 
    TP 16/17 (Tutorijal 7, Zadatak 2)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <cstring>
#include <algorithm>
int main ()
{
	std::cout << "Koliko zelite recenica: ";
	char** rec=nullptr;
	try{
		int n;
		std::cin >> n;
		std::cin.ignore(100000,'\n');
		std::cout << "Unesite recenice: " << std::endl;
		rec = new char*[n];
		for(int i=0; i<n;i++)
		rec[i]=nullptr;
		try {
			int brojac=0;
			for(int i=0; i<n; i++) {
				char pomocna[1000];
				std::cin.getline(pomocna, sizeof pomocna);
				rec[i]= new char [std::strlen(pomocna)+1];
				brojac++;
				std::strcpy(rec[i],pomocna);
			}
			
			std::cout << "Sortirane recenice: " << std::endl;
			std::sort(rec, rec+n, [] ( const char* a, const char* b){return strcmp(a,b)<0; }  );
			
			  for(int i=0; i<n; i++) {
				std::cout << rec[i] << std::endl;
			} 
			for(int i=0; i<n;i++) delete [] rec[i];
			delete [] rec;
		} catch (...) {
			for(int i=0; i<n; i++) delete [] rec[i];
			delete [] rec;
			throw;
		}
	} catch(...) {
		std::cout << "Problemi s memorijom!";
	}
	


	return 0;
}
