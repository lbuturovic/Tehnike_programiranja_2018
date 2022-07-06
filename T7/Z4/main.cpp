/* 
    TP 16/17 (Tutorijal 7, Zadatak 4)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <memory>
typedef std::shared_ptr<std::string> Pok;
int main ()
{
	std::cout << "Koliko zelite recenica: ";
	std::unique_ptr<Pok[]> rec;
		int n;
		std::cin >> n;
		std::cout << "Unesite recenice: " << std::endl;
		std::cin.ignore(1000,'\n');
		try{
		rec=std::unique_ptr<Pok[]>(new Pok[n]);
		/*std::vector<std::string> rec(n);*/
		/*std::cout << "Unesite recenice: " << std::endl;*/
		/*std::vector<std::string> rec(n);*/
		/*for(int i=0; i<n;i++)
		rec[i]=nullptr;*/
	
			int brojac=0;
			for(int i=0; i<n; i++) {
				std::string pomocna;
			/*	std::getline(std::cin,pomocna);   zasto se ne moze unijeti pomocna
			i onda ona upisati u zagradu--------------------| (pada cetvrti test)*/
				rec[i]= std::make_shared <std::string>(std::string());
				std::getline(std::cin, *rec[i]);
				/*rec[i]= pomocna;*/
				/*std::cout << rec[i];*/
			
			}
			/*std::cout << "Sortirane recenice: " << std::endl;*/
			std::sort(rec.get(), rec.get()+n, [] ( Pok a, Pok b){return *a<*b; }  );
			std::cout << "Sortirane recenice: " << std:: endl;
			  for(int i=0; i<n; i++) {
				std::cout << *rec[i] << std::endl;
			} 
		/*	for(int i=0; i<n;i++) delete [] rec[i];
			delete [] rec; */
		/*} catch (...) { */
			/*for(int i=0; i<n; i++) delete [] rec[i];
			delete [] rec;*/
		/*	throw;
		} */
	} catch(...) {
		std::cout << "Problemi s memorijom!";
	}
	


	return 0;
}
