/* 
    TP 2018/2019: Tutorijal 5, Zadatak 3 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <deque>
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
	
	int n;
	std::cout << "Unesite broj elemenata: ";
	std::cin >> n;
	std::deque<int> br(n);
	std::cout << "Unesite elemente: ";
	std::for_each(br.begin(), br.end(), [](int &x){	std::cin >> x;});
	std::cout <<"Najveci element deka je " << *(std::max_element(br.begin(), br.end(),[](int a, int b){return(a<b);} )) << std::endl;
	int min=*(std::min_element(br.begin(),br.end(), [](int a, int b){	return(a<b);}));
	std::cout <<"Najmanji element deka se pojavljuje " << std::count(br.begin(), br.end(), min) << " puta u deku"<< std::endl;
	std::cout <<"U deku ima " << std::count_if(br.begin(), br.end(), [] (int x){return(int(sqrt(x))==sqrt(x));} ) << " brojeva koji su potpuni kvadrati" << std::endl;

	std::deque<int>::iterator m=std::min_element(br.begin(), br.end(), [](int a, int b){	if(a<0) a=-1*a; if(b<0) b=-1*b;	return((int)log10(a)<(int)log10(b));} );
	std::cout <<"Prvi element sa najmanjim brojem cifara je " << *m << std::endl;
	std::deque<int> novi(n);
	std::cout << "Elementi koji nisu trocifreni su: ";
	auto pom=std::remove_copy_if(br.begin(), br.end(), novi.begin(), [] (int x){	return ((x>=100 && x<1000) || (x>-1000 && x<=-100));});
	std::for_each(novi.begin(),pom, [] (int x){	std::cout << x<< " ";} );
	return 0;
}