/* 
    TP 16/17 (Tutorijal 9, Zadatak 4)
	
	Testove pisao Kenan Ekinovic. Za sva pitanja, sugestije
	i zalbe obratiti se na mail: kekinovic1@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <iomanip>
class Sat{
	int h, m, s;
	//static bool DaLiJeIspravno(int h, int m, int s);
public:
	static bool DaLiJeIspravno(int h, int m, int s);
	Sat &Postavi(int h, int m, int s){
		if(!DaLiJeIspravno(h,m,s)) throw std::domain_error("Neispravno vrijeme");
		Sat::h=h; Sat::m=m; Sat::s=s;
		return *this;
	}
	Sat& PostaviNormalizirano(int h, int m, int s);
	Sat &Sljedeci(){
		s++;
		PostaviNormalizirano(h,m,s);
		return *this;
	}
	Sat &Prethodni(){
		s--;
		*this=PostaviNormalizirano(h,m,s);
		return *this;
	}
	Sat &PomjeriZa(int sekunde){
		s+=sekunde;
		return PostaviNormalizirano(h,m,s);
		//return *this;
	}
	void Ispisi() const {
		std::cout<< std::setfill('0') <<std::setw(2) << h << ":" <<std::setw(2)<< m << ":" << std::setw(2) << s;
	}
	int DajSate() const{ return h;}
	int DajMinute() const{return m;}
	int DajSekunde() const{return s;}
	friend int BrojSekundiIzmedju(Sat s1, Sat s2);
	static int Razmak(Sat s1, Sat s2);
};
 Sat& Sat::PostaviNormalizirano(int h, int m, int s){
	if(DaLiJeIspravno(h, m, s)){
		//Sat::h=h; Sat::m=m; Sat::s=s;
		return *this;}
	else {
		while(s<0){
			s+=60;
			m--;
		}
		while(m<0){
			m+=60;
			h--;
		}
		while(h<0){
			h+=24;
		}
	Sat::s=s%60; Sat::m=(s/60+m)%60; Sat::h=((m+s/60)/60+h)%24; 
	
	//int pomocna=s/60;
	//Sat::m=(m+pomocna)%60;
	//pomocna=(m+pomocna)/60;
	//Sat::h=(pomocna+h)%24;
	
		return *this;
	}
}
bool Sat::DaLiJeIspravno(int h, int m, int s){
	if(h<0 || h>23 || m<0 || m>59 || s<0 || s>59) return false;
	return true;
}
int BrojSekundiIzmedju(Sat s1, Sat s2){
	int sekunde1=s1.s+s1.m*60+s1.h*3600;
	int sekunde2=s2.s+s2.m*60+s2.h*3600;
	return sekunde1-sekunde2;
}
int Sat::Razmak(Sat s1, Sat s2){
	int sekunde1=s1.s+s1.m*60+s1.h*3600;
	int sekunde2=s2.s+s2.m*60+s2.h*3600;
	return sekunde1-sekunde2;
}
int main ()
{
	Sat s1;
	s1.Postavi(23, 59, 59);
	s1.Sljedeci();
	s1.Ispisi();
	Sat s2;
	try{
	s2.Postavi(18, 34, 999);}
	catch(std::domain_error d){
		std::cout << d.what();
	}
	s2.PostaviNormalizirano(18, 34, 999);
	std::cout <<std::endl << BrojSekundiIzmedju(s1, s2) << std::endl;
	//std::cout << Sat::BrojSekundiIzmedju(s1, s2);
	s2.PomjeriZa(4);
	s1.Postavi(12, 12, 12).Sljedeci().Prethodni();
	std::cout << std:: endl << " trebaju biti sve 12-ke: " << s1.DajSate() << ";" << s1.DajMinute() << ";" << s1.DajSekunde() << std::endl;
	s2.Ispisi();
	std::cout << std::endl;
	s1.Ispisi();
	
	s1.Prethodni().Sljedeci();
	
	s1.Postavi(10,10,10);
  s2.Postavi(10,10,15);
  std::cout << BrojSekundiIzmedju(s2, s1) << " "
            << Sat::Razmak(s2, s1) << std::endl;
  std::cout << BrojSekundiIzmedju(s1, s2) << " "
            << Sat::Razmak(s1, s2) << std::endl;
	
	return 0;
}