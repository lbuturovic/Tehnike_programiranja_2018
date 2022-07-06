/*
    TP 16/17 (Tutorijal 11, Zadatak 2)
	Autotestove napisao Haris Hasic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: hhasic2@etf.unsa.ba.

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/

#include <iostream>
#include <stdexcept>
class StedniRacun
{
	static int aktivni;
	static int stvoreni;
	double racun;
public:
	StedniRacun()
	{
		racun=0;
		aktivni++;
		stvoreni++;
	}
	StedniRacun(double x)
	{
		if(x<0) throw std::logic_error ("Nedozvoljeno pocetno stanje");
		racun=x;
		aktivni++;
		stvoreni++;
	}
	StedniRacun(const StedniRacun &s)
	{
		stvoreni++;
		aktivni++;
	}
	~StedniRacun()
	{
		aktivni--;
	}
	StedniRacun& Ulozi(double x)
	{
		//if(x<0) throw std::logic_error("Transakcija odbijena");

		x=racun+x;
		if(x<0) throw std::logic_error("Transakcija odbijena");
		racun=x;
		//racun=racun+x;
		//racun=x;
		return *this;
	}
	StedniRacun& Podigni(double x)
	{
		if(x>racun) throw std::logic_error("Transakcija odbijena");
		racun-=x;
		return *this;
	}
	double DajStanje() const
	{
		return racun;
	}
	StedniRacun& ObracunajKamatu(double x)
	{
		if(x<0) throw std::logic_error("Nedozvoljena kamatna stopa");
		racun=racun+(x/100)*racun;
		return *this;
	}
	static int DajBrojKreiranih()
	{
		return stvoreni;
	}
	static int DajBrojAktivnih()
	{
		return aktivni;
	}
};
int StedniRacun::aktivni=0;
int StedniRacun::stvoreni=0;

int main ()
{

	StedniRacun s(1000);
	try {
		StedniRacun s2(-1000);

	} catch(std::logic_error l) {
		std::cout << l.what();
	}
	s.Ulozi(500).Podigni(250);
	s.ObracunajKamatu(10);
	std::cout << s.DajStanje() << std::endl;
	const StedniRacun m(77);
	std::cout <<m.DajStanje();
	return 0;
}
