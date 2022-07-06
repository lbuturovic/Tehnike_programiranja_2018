//TP 2017/2018: ZSR 1, Zadatak 1
#include <iostream>
#include <list>
template <typename Tip>
std::list<Tip> SortirajListu (std::list<Tip> l){
	std::list<Tip> l2; /*l2(l.size());*/
	auto it1=l.begin();
	for(int i=0; i<l.size();i++){
		auto it2=l2.begin();
		while(it2!=l2.end()&& *it2<*it1) it2++;
		l2.insert(it2,*it1);
		it1++;
	}
	return l2;
}
int main ()
{
	int n;
	std::cout << "Koliko ima elemenata: ";
	std::cin>> n;
	std::list<int> lista (n);
	std::list<std::string> ls{"Mujo", "Suljo", "Haso", "Hrvoje", "Ivan", "Ante", "Milutin", "Dragan", "Zoran"};
	std::cout << "Unesite elemente: ";
	for(auto &x: lista) std::cin>> x;
	auto l2=SortirajListu(ls);
	std::cout << "Sortirana lista: ";
	for(auto x:l2) std::cout << x << " ";
	return 0;
}