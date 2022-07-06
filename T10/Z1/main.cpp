/* 
    TP 16/17 (Tutorijal 10, Zadatak 1)
	Autotestove pisala Nina Slamnik. Za sva pitanja,
	sugestije i primjedbe poslati mail na:
	nslamnik1@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <stdexcept>
class StedniRacun{
	double racun;
	public:
	StedniRacun(){ racun=0;}
	StedniRacun(double x) {
		if(x<0) throw std::logic_error ("Nedozvoljeno pocetno stanje");
		racun=x;}
	StedniRacun& Ulozi(double x){
		//if(x<0) throw std::logic_error("Transakcija odbijena");
		
		racun=racun+x;
		if(racun<0) throw std::logic_error("Transakcija odbijena");
		//racun=x;
		return *this;
	}
	StedniRacun& Podigni(double x){
		if(x>racun) throw std::logic_error("Transakcija odbijena");
		racun-=x;
		return *this;
	} 
   double DajStanje() const {
		return racun;
	}
	StedniRacun& ObracunajKamatu(double x){
		if(x<0) throw std::logic_error("Nedozvoljena kamatna stopa");
		racun=racun+(x/100)*racun;
		return *this;
	}
};
int main ()
{
	
	StedniRacun s(1000);
	try{
	StedniRacun s2(-1000);
		
	}
	catch(std::logic_error l) {
		std::cout << l.what();
	}
	s.Ulozi(500).Podigni(250);
	s.ObracunajKamatu(10);
	std::cout << s.DajStanje() << std::endl;
   const StedniRacun m(77);
	std::cout <<m.DajStanje();
	return 0;
}