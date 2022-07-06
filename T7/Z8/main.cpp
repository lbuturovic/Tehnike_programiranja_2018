/* 
    TP 16/17 (Tutorijal 7, Zadatak 8)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
std::string IzvrniBezRazmaka (std::string s){
	std::string s2;
	std::remove_copy(s.rbegin(),s.rend(),std::back_inserter(s2),' ');
	
	return s2;
}
int main ()
{
	std::cout << "Unesite recenicu: ";
	std::string s;
	std::getline(std::cin, s);
	std::cout << "Izvrnuta recenica bez razmaka: " << IzvrniBezRazmaka(s);
	return 0;
}