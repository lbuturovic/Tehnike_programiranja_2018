/*
    TP 16/17 (Tutorijal 10, Zadatak 4)
	Autotestove pisala Nina Slamnik. Za sva pitanja,
	sugestije i primjedbe poslati mail na:
	nslamnik1@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <cmath>
#include <iomanip>
const double epsilon=0.000001;
class Ugao
{
	int s,m,ss;
	//int sek; //stepeni,minute,sekunde;
public:
	Ugao(double radijani=0)
	{
		//Ugao::radijani=radijani;
		Postavi(radijani);
		//Ugao::radijani=radijani;
	}
	Ugao(int stepeni, int minute, int sekunde)
	{
		Postavi(stepeni,minute,sekunde);
	}
	void Postavi(int stepeni, int minute, int sekunde);
	void Postavi(double radijani);
	int DajStepene() const
	{
		return s;

		
	}
	int DajMinute() const
	{
		
		
		return m;
	}
	int DajSekunde() const
	{
		
		return ss;
	}
	double DajRadijane() const
	{
		double sekunde=ss+m*60+s*3600;
		return sekunde*4*atan(1)/(180*3600);
	}
	void Ispisi() const{
		std::cout << std::setprecision(5) << std::fixed <<DajRadijane() ;
	}
	void IspisiKlasicno() const {
		std::cout << DajStepene() <<"deg " << DajMinute()<< "min " << DajSekunde() << "sec";
	}
//	void IspisiKlasicno() const;
	void OcitajKlasicneJedinice(int &a, int &b, int &c) const{
		a=DajStepene();
		b=DajMinute();
		c=DajSekunde();
	}
	Ugao& SaberiSa(Ugao u);
	Ugao& PomnoziSa(double x);
	friend Ugao ZbirUglova(const Ugao &u1, const Ugao &u2);
	friend Ugao ProduktUglaSaBrojem(const Ugao &u, double x);
};


/*void Ugao::OcitajKlasicneJedinice(int &a, int &b, int &c){
	a=DajStepene();
	b=DajMinute();
	c=DajSekunde();
}*/
void Ugao::Postavi(int stepeni, int minute, int sekunde)
{
	//if(stepeni>=360) stepeni=
	while (sekunde<0) {
		sekunde+=60;
		minute--;
	}
	while (minute<0) {
		minute+=60;
		stepeni--;

	}
	while(stepeni<0) {
		stepeni+=360;
	}
	//std::cout << "S:" << stepeni << "m:" << minute << "sek: " << sekunde;
	ss =sekunde%60;   //std::cout << "s:" << s1;
	m=(sekunde/60+minute)%60; //std::cout << "m:" << m1;
	s=((minute+sekunde/60)/60+stepeni)%360; //std::cout << "h: " << h1 << "...";
	//long double stt =(h1+m1/60.+s1/3600.)*3600+epsilon;
	//std::cout << sek << std::endl;
	//=(minute+sekunde/60)%60;
	//std::cout << (float)sek*4*atan(1)/64800;
	
	//Ugao::radijani=((stt*4*atan(1))/(180*3600));
	//Postavi(radijani);
//	std::cout <<"  " << radijani << std::endl;
//std::cout << sek*4.84813681*0.000001;
	//Ugao::radijani=sek*4.84813681*0.000001;
	
	//Ugao::stepeni=Ugao::stepeni+
	//Ugao::radijani=uglovi*4*atan(1)/180;
}

void Ugao::Postavi(double radijani)
{
	
	while(radijani>=8*atan(1)){
		radijani=radijani-8*atan(1);
	}
	while (radijani<0) {
		radijani+=8*atan(1);
	}
	radijani=radijani*180/(4*atan(1))+epsilon;
		s=int(radijani);
		m=int((radijani-s)*3600)/60;
		ss=int((radijani-s)*3600)%60+epsilon;
	//Ugao::radijani=radijani;
	/*if(radijani>0){
		Ugao::radijani=radijani;
		if(radijani<=8*atan(1))  //radijani=(radijani/(2*4*atan(1)));
		Ugao::radijani=radijani;
		return;
	} */
/*	double rad=(radijani*180)/(4*atan(1));
	//std::cout << " U stepenima: " << rad << std::endl;
	while(rad<0){
	rad+=360;
	}
	int st1=int(rad); //std::cout << st1 << std::endl;
	int m1=int((rad-st1)*3600)/60; //std::cout << m1 << std::endl;
	int s1=int((rad-st1)*3600)%60; //std::cout << s1 << std::endl;
	//std::cout << std::endl;
	//std::cout << st1 << std::endl << m1  << s1;
	Postavi(st1, m1, s1);
//	std::cout << st << std::endl;
/*	while(radijani<0) {
		radijani+=8*atan(1);
	} //sad imam stepene
	
	radijani=radijani*180/(4*atan(1));
	int st1=int(radijani);
	int m1=int((radijani-st1)*3600)/60;
	int s1=int((radijani-st1)*3600)%60;
	Postavi(st1,m1,s1); */
}
Ugao& Ugao::PomnoziSa(double x){
	 double rad=DajRadijane()*x;
	Postavi(rad);
	return *this;
}
Ugao& Ugao::SaberiSa(Ugao u){
	//radijani=radijani+x;
	//double rad=radijani;
	double rad=DajRadijane()+u.DajRadijane();
	Postavi (rad);
	
	return *this;
}
/*Ugao& Ugao::SaberiSa(double x){
	radijani=radijani+x;
	double=radijani;
	Postavi(double);
	return *this;
}*/
Ugao ZbirUglova(const Ugao& u1, const Ugao& u2){
	Ugao u3;
	double rad=u1.DajRadijane()+u2.DajRadijane();
	u3.Postavi(rad);
	return u3;
}
Ugao ProduktUglaSaBrojem(const Ugao& u1, double x){
	Ugao u3;
	double rad=u1.DajRadijane()*x;
	u3.Postavi(rad);
	return u3;
}
int main ()
{
	Ugao u(90, 0, 0);

u = ProduktUglaSaBrojem(u, 5);
u.Ispisi(); std::cout << std::endl;
auto m=ZbirUglova(u,8);
m.IspisiKlasicno(); std::cout << std::endl;
ProduktUglaSaBrojem(u, -5).IspisiKlasicno(); std::cout << std::endl;
	return 0;
}
