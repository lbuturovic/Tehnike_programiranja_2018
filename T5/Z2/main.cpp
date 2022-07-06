/* 
    TP 2018/2019: Tutorijal 5, Zadatak 2
	
	Autotestove pisala Nina Slamnik. Prijave gresaka, sugestije i pitanja
	mozete slati na mail nslamnik1@etf.unsa.ba.
	
	NAPOMENA: Tutorijal 5 sadrzi veliki broj ZABRANA, tipa zabrana
			  da se koristi indeksiranje niz[i] ili simulacija indeksiranja
			  npr. *(niz + i); dalje, da su zabranjene for petlje i slicno.
			  
			  To ce tutori rucno pregledati u toku tutorijala te ako
			  student bude PREKRSIO BAREM JEDNU ZABRANU, smatrace se da
			  za taj zadatak NIJE PROSAO NITI JEDAN AUTOTEST!
*/
#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <iomanip>
template <typename Tip1, typename Tip2>
void Razmijena(Tip1 &a, Tip2 &b){
	Tip1 pom=a;
	a=b;
	b=pom;
}
template <typename IterTip1, typename IterTip2>
IterTip2 RazmijeniBlokove (IterTip1 p1, IterTip1 p2, IterTip2 p3){
	while(p1!=p2){
		Razmijena(*p1, *p3);
		p1++;
		p3++;
	}
	
	return p3;
}
int main ()
{

	return 0;
}