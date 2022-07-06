/* 
    TP 16/17 (Tutorijal 10, Zadatak 3)
	Autotestove pisala Nina Slamnik. Za sva pitanja,
	sugestije i primjedbe poslati mail na:
	nslamnik1@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <cmath>
class Vektor3d {
	double koordinate[3];
	mutable int brojispisa=0;
public:
	Vektor3d (){
		koordinate[0]=0;
		koordinate[1]=0;
		koordinate[2]=0;
	}
	Vektor3d(double a, double b, double c){
		koordinate[0]=a;
		koordinate[1]=b;
		koordinate[2]=c;
	}
	Vektor3d(const Vektor3d& v){
		koordinate[0]=v.koordinate[0];
		koordinate[1]=v.koordinate[1];
		koordinate[2]=v.koordinate[2];
		brojispisa=0;
	}
	void Postavi (double x, double y, double z) {
		koordinate[0]=x; koordinate[1]=y, koordinate[2]=z;
	}
	Vektor3d &PostaviX(double x){ 
		koordinate[0]=x;
		return *this;
		
	}
	Vektor3d &PostaviY(double y){
		koordinate[1]=y;
		return *this;
		
	}
	Vektor3d &PostaviZ(double z){
		koordinate[2]=z;
		return *this;
	}
	void Ocitaj (double &x, double &y, double &z) const {
		x=koordinate[0], y=koordinate[1], z=koordinate[2];
	}
	void Ispisi() const {
		std::cout << "{" << koordinate[0] <<"," << koordinate[1] << "," << koordinate[2] << "}";
		brojispisa++;
	}
	int DajBrojIspisa() const { return brojispisa;}
	double DajX() const { return koordinate[0];}
	double DajY() const { return koordinate[1];}
	double DajZ() const { return koordinate[2];}
	double DajDuzinu() const { return sqrt(koordinate[0]*koordinate[0]+koordinate[1]*koordinate[1]
	+koordinate[2]*koordinate[2]); }
	Vektor3d &PomnoziSaSkalarom(double s){
		koordinate[0]*=s; koordinate[1]*=s; koordinate[2]*=s;
		return *this;
	}
	Vektor3d &SaberiSa(const Vektor3d &v) {
		koordinate[0]+=v.koordinate[0];
		koordinate[1]+=v.koordinate[1];
		koordinate[2]+=v.koordinate[2];
		return *this;
	}
	friend Vektor3d ZbirVektora (const Vektor3d &v1, const Vektor3d &v2);
};
  Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2){
  	Vektor3d v3;
  	v3.koordinate[0]=v1.koordinate[0]+v2.koordinate[0];
  	v3.koordinate[1]=v1.koordinate[1]+v2.koordinate[1];
  	v3.koordinate[2]=v1.koordinate[2]+v2.koordinate[2];
  	return v3;
  	
  }
int main ()
{
	Vektor3d vektor;
	vektor.Postavi(2, 7, 7);
	vektor.PomnoziSaSkalarom(2);
	Vektor3d v2;
	v2.PostaviX(2.1).PostaviY(3.3).PostaviZ(4.5);
	vektor.SaberiSa(v2);
	Vektor3d v3=ZbirVektora(vektor, v2);
	v3.DajDuzinu();
	v3.Ispisi(); std::cout << std::endl;
	vektor.Ispisi();
	double a, b, c;
	vektor.Ocitaj(a, b, c);
	std::cout << a << ", " << b << ", " << c << std::endl;
	vektor.Ispisi();
	std::cout << "Broj ispisa vekora je " << vektor.DajBrojIspisa() << ", a za v3 je " << v3.DajBrojIspisa();
	return 0;
}
