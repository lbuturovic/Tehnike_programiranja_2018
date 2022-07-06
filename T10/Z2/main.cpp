/* 
    TP 16/17 (Tutorijal 10, Zadatak 2)
	Autotestove pisala Nina Slamnik. Za sva pitanja,
	sugestije i primjedbe poslati mail na:
	nslamnik1@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <iomanip>
#include <cmath>
class Krug{
	double r;
	public:
	explicit Krug(double x){ if(x<=0) throw std::domain_error ("Neispravan poluprecnik");
		r=x;}
	void Postavi(double x){
		if(x<=0) throw std::domain_error ("Neispravan poluprecnik");
		r=x;}
double DajPoluprecnik() const {
		return r;
	}
	double DajObim() const {
		return 2*r*4*atan(1);
	}
	double DajPovrsinu() const{
		return r*r*4*atan(1);
	}
	void Skaliraj(double x){
		if(x<=0) throw std::domain_error ("Neispravan faktor skaliranja");
		r=r*x;
		//return *this;
	}
	void Ispisi() const {
		std::cout << std::fixed << std::setprecision(5) << "R=" << DajPoluprecnik() <<
		" O=" << DajObim()  << " P=" << DajPovrsinu();
	}
	
};
class Valjak{
	Krug baza;
	double visina;
	public:
	Valjak(double x, double h): baza(x){
		if(x<=0) throw std::domain_error ("Neispravan poluprecnik");
		if(h<=0) throw std::domain_error("Neispravna visina");
		visina=h;
	}
	void Postavi(double x, double h){
		if(x<=0) throw std::domain_error ("Neispravan poluprecnik");
		if(h<=0) throw std::domain_error("Neispravna visina");
		baza.Postavi(x);
		visina=h;
		//double b=x*x*4*atan(1);
		//baza=x;
	}
	Krug DajBazu() const {
		return baza;// .DajPoluprecnik()*baza.DajPoluprecnik()*4*atan(1);
	}
	double DajPoluprecnikBaze() const{
		return baza.DajPoluprecnik();
	}
	double DajPovrsinu() const {
		return visina*baza.DajObim()+2*baza.DajPovrsinu();
	}
	double DajZapreminu() const {
		return visina*baza.DajPovrsinu();
	}
	double DajVisinu() const {
		return visina;
	}
	void Skaliraj(double x){
		if(x<=0) throw std::domain_error ("Neispravan faktor skaliranja");
		visina=visina*x;
		double n=baza.DajPoluprecnik()*x;
		baza.Postavi(n);
	}
	void Ispisi() const {
		std::cout << std::fixed << std::setprecision(5) << "R=" << baza.DajPoluprecnik()<<
		" H=" << DajVisinu()  << " P=" << DajPovrsinu() << " V=" << DajZapreminu();
	}
};
int main ()
{
	return 0;
}