/* 
    TP 16/17 (Tutorijal 7, Zadatak 3)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
/*#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
int main ()
{
	std::cout << "Koliko zelite recenica: ";
	std::string** rec=nullptr;
		int n;
		std::cin >> n;
		try{
		/*std::vector<std::string> rec(n);
		std::cin.ignore(100000,'\n');
		std::cout << "Unesite recenice: " << std::endl;
		//std::vector<std::string> rec(n);
		rec = new std::string*[n]{};
		//for(int i=0; i<n;i++)
		//rec[i]=nullptr;
		try {
			int brojac=0;
			for(int i=0; i<n; i++) {
				//std::string pomocna;
				//std::getline(std::cin,pomocna);
				rec[i]= new std::string;
				std::getline(std::cin, *rec[i]);
				/*std::cout << rec[i];
				brojac++;
			
			}
		}
		catch(...){
			for(int i=0; i<n; i++) delete [] rec[i];
			delete [] rec;
			rec=nullptr;
			return 0;
			//throw;
		}
			//std::cout << "Sortirane recenice: " << std::endl;
			std::sort(rec, rec+n, [] ( std::string* a, std::string* b){return *a<*b; }  );
			std::cout << "Sortirane recenice: " << std:: endl;
			  for(int i=0; i<n; i++) {
				std::cout << *rec[i] << std::endl;
			} 
			//for(int i=0; i<n;i++) delete [] rec[i];
			//delete [] rec;
		}
	 catch(...) {
		std::cout << "Problemi s memorijom!";
		return 0;
	}
	
for(int i=0; i<n;i++) delete [] rec[i];
			delete [] rec;

	return 0;
}   */

#include <iostream>
#include <cstring>
#include <algorithm>
int main ()
{
	std::cout << "Koliko zelite recenica: ";
	std::string** rec=nullptr;
	int n;
	try{
	//	int n;
		std::cin >> n;
		std::cin.ignore(100000,'\n');
		std::cout << "Unesite recenice: " << std::endl;
		rec = new std::string*[n]{};
		//for(int i=0; i<n;i++)
		//rec[i]=nullptr;
		try {
			int brojac=0;
			for(int i=0; i<n; i++) {
				//char pomocna[1000];
				//std::cin.getline(pomocna, sizeof pomocna);
				rec[i]= new std::string;
				brojac++;
				std::getline(std::cin, *rec[i]);
			}
			
			std::cout << "Sortirane recenice: " << std::endl;
			std::sort(rec, rec+n, [] ( std::string* a, std::string* b){return *a<*b; }  );
			
			  for(int i=0; i<n; i++) {
				std::cout << *rec[i] << std::endl;
			} 
			for(int i=0; i<n;i++) delete rec[i];
			delete [] rec;
		} catch (...) {
			for(int i=0; i<n; i++) delete  rec[i];
			delete [] rec;
			throw;
		}
	} catch(...) {
		std::cout << "Problemi s memorijom!";
	}
	

//for(int i=0; i<n;i++) delete [] rec[i];
		//	delete [] rec;
	return 0;
}
