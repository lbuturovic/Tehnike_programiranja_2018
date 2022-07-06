/* 
    TP 16/17 (Tutorijal 7, Zadatak 7)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <set>
#include <string>
template < typename Tip>
std::set<Tip> Unija (std::set <Tip> s1, std::set<Tip> s2){
	std::set<Tip> s3;
	auto it=s1.begin();
	for(int i=0; i<s1.size();i++){
		s3.insert(*it);
		it++;
	}
	it=s2.begin();
	for(int i=0; i<s2.size();i++){
		s3.insert(*it);
		it++;
	}
	return s3;
}
template <typename Tip>
std::set<Tip> Presjek(std::set<Tip> s1, std::set<Tip> s2){
	auto it1=s1.begin();
	auto it2=s2.begin();
	std::set<Tip> s3;
	for(int i=0; i<s1.size();i++){
		it2=s2.begin();
		for(int j=0; j<s2.size();j++){
			if(*it1==*it2) s3.insert(*it1);
			it2++;
		}
		it1++;
	}
	
	    return s3;
}
int main ()
{
 /*	std::set<std::string> s1;
	std::set<std::string> s2;
	std::cout << "Unesite 5 stringova: ";
	auto p=s1.begin();
	for(int i=0; i<5; i++) {
		std::string s;
		std::getline(std::cin, s);
		*p=s;
		p++;}
	std::cout << "Unesite jos 5 stringova: ";
	p=s2.begin();
	for(int i=0; i<5; i++) {
		std::string s;
		std::getline(std::cin, s);
		*p=s;
		p++;}
	std::cout << "Unija unesenih stringova je: ";
	for(auto x: Unija(s1,s2)) std::cout << x << " ";
	std::cout<< std::endl;
	"Presjek unesenih stringova je: ";
	for(auto x: Presjek(s1, s2)) std::cout << x << " "; */
	
	return 0;
}