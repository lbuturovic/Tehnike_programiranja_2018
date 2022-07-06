/* 
    TP 16/17 (Tutorijal 7, Zadatak 6)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <list>
template <typename Tip>
void SortirajListu (std::list<Tip> &l){
	std::list<Tip> l2; /*l2(l.size());*/
	auto it1=l.begin();
	for(int i=0; i<l.size();i++){
		auto it2=l2.begin();
		while(it2!=l2.end()&& *it2<*it1) it2++;
		l2.insert(it2,*it1);
		it1++;
	}
	l=l2;
}
int main ()
{
	int n;
	std::cout << "Koliko ima elemenata: ";
	std::cin>> n;
	std::list<int> lista (n);
	std::cout << "Unesite elemente: ";
	for(auto &x: lista) std::cin>> x;
	SortirajListu(lista);
	std::cout << "Sortirana lista: ";
	for(auto x:lista) std::cout << x << " ";
	return 0;
}