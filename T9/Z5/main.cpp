#include <iostream>
#include <iomanip>
class Sat
{
	int s;
	//static bool DaLiJeIspravno(int h, int m, int s);
public:
	static bool DaLiJeIspravno(int h, int m, int s);
	Sat &Postavi(int h, int m, int s)
	{
		if(!DaLiJeIspravno(h,m,s)) throw std::domain_error("Neispravno vrijeme");
		Sat::s=h*3600+m*60+s;
		return *this;
	}
	Sat& PostaviNormalizirano(int h, int m, int s);
	Sat &Sljedeci()
	{
		s++;
		*this=PostaviNormalizirano(s/3600, (s%3600)/60, (s%3600)%60);
		return *this;
	}
	Sat &Prethodni()
	{
		s--;
		return PostaviNormalizirano(s/3600, (s%3600)/60, (s%3600)%60);
	}
	Sat &PomjeriZa(int sekunde)
	{
		s+=sekunde;
		return *this=PostaviNormalizirano(s/3600, (s%3600)/60, (s%3600)%60);
	}
	void Ispisi() const
	{
		//PostaviNormalizirano()
		std::cout<< std::setfill('0') <<std::setw(2) << s/3600 << ":" <<std::setw(2)<< (s%3600)/60 << ":" << std::setw(2) << (s%3600)%60;
	}
	int DajSate() const
	{
		return s/3600;
	}
	int DajMinute() const
	{
		return (s%3600)/60;
	}
	int DajSekunde() const
	{
		return (s%3600)%60;
	}
	friend int BrojSekundiIzmedju(Sat s1, Sat s2);
	static int Razmak(Sat s1, Sat s2);
};
Sat& Sat::PostaviNormalizirano(int h, int m, int s)
{
	while(s<0) {
		s+=60;
		m--;
	}
	while(m<0) {
		m+=60;
		h--;
	}
	while(h<0) {
		h+=24;
	}
	/*s=s%60;
	int pomocna=s/60;
	m=pomocna+m;
	pomocna=m/60;
	m=m%60;
	h=(h+pomocna)%24;
	s=s%60;
	m=(m+pomocna)%60;
	pomocna=(m+pomocna)/60;
	h=(pomocna+h)%24;*/
	int sek=s%60;
	int min=(s/60+m)%60;
	int sati=((m+s/60)/60+h)%24;
	Sat::s=sek+min*60+sati*3600;
	return *this;

}
bool Sat::DaLiJeIspravno(int h, int m, int s)
{
	if(h<0 || h>23 || m<0 || m>59 || s<0 || s>59) return false;
	return true;
}
int BrojSekundiIzmedju(Sat s1, Sat s2)
{
	return s1.s-s2.s;
}
int Sat::Razmak(Sat s1, Sat s2)
{
	return s1.s-s2.s;
}
int main ()
{
	Sat s1;
	s1.Postavi(23, 59, 59);
	s1.Sljedeci();
	s1.Ispisi();
	Sat s2;
	try {
		s2.Postavi(18, 34, 999);
	} catch(std::domain_error d) {
		std::cout << d.what();
	}
	std::cout << "post norm " << std::endl;
	s2.PostaviNormalizirano(80, 70, 15).Ispisi();
	std::cout << "     ";
	s2.Ispisi();
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
