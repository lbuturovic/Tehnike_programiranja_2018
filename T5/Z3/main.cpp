/* 
    TP 2018/2019: Tutorijal 5, Zadatak 3 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
void Unos (int &x){
	std::cin >> x;
}
void Ispis(int x){
	std::cout << x<< " ";
}
bool Veci (int a, int b){
	
	return(a<b);
}
bool Manji (int a, int b){
	
	return(a<b);
}
bool Jednaki (int x, int min){
	return (x==min);
}
bool PKvadrat(int x){
	
	return(int(sqrt(x))==sqrt(x));
	
}
bool BrojCifara(int a, int b){
	if(a<0) a=-1*a;
	if(b<0) b=-1*b;
	return(log10(a)<log10(b));
}
bool Trocifren(int x){
	
	return ((x>=100 && x<1000) || (x>-1000 && x<=-100));
}
int main ()
{
	int br[1000];
	int n;
	std::cout << "Unesite broj elemenata (max. 1000): ";
	std::cin >> n;
	std::cout << "Unesite elemente: ";
	std::for_each(br, br+n, Unos);
	std::cout <<"Najveci element niza je " << *(std::max_element(br, br+n,Veci)) << std::endl;
	int min=*(std::min_element(br,br+n, Manji));
	std::cout <<"Najmanji element niza se pojavljuje " << std::count(br, br+n, min) << " puta u nizu"<< std::endl;
	std::cout <<"U nizu ima " << std::count_if(br, br+n, PKvadrat) << " brojeva koji su potpuni kvadrati" << std::endl;
	auto m=std::min_element(br, br+n, BrojCifara);
	std::cout <<"Prvi element sa najmanjim brojem cifara je " << *m << std::endl;
	int niz[1000];
	std::cout << "Elementi koji nisu trocifreni su: ";
	auto pom=std::remove_copy_if(br, br+n,niz, Trocifren);
	std::for_each(niz,pom, Ispis );
	return 0;
}