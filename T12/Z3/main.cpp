/* 
    TP 16/17 (Tutorijal 12, Zadatak 3)
	Autotestove napisao Kerim Hodzic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: khodzic2@etf.unsa.ba.
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
enum Dani {Ponedjeljak, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};
Dani &operator ++(Dani &d) {
return d = Dani((int(d) + 1) % 7);
}
Dani operator ++(Dani &d, int) {
Dani pomocni = d; ++d; return pomocni;
}
std::ostream & operator << (std::ostream &t, const Dani &d){
	
	if(d==0) t << "Ponedjeljak";
	if(d==1) t << "Utorak";
	if(d==2) t << "Srijeda";
	if(d==3) t << "Cetvrtak";
	if(d==4) t << "Petak";
	if(d==5) t << "Subota";
	if(d==6) t << "Nedjelja";
	return t;
}
int main ()
{
	return 0;
}