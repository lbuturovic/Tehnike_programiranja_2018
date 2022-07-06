/*
    TP 16/17 (Tutorijal 11, Zadatak 3)
	Autotestove napisao Haris Hasic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: hhasic2@etf.unsa.ba.

	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <cstring>
#include <iomanip>
class Tim
{
	char ime_tima[20];
	int broj_odigranih;
	int broj_pobjeda;
	int broj_nerijesenih;
	int broj_poraza;
	int broj_datih;
	int broj_primljenjih;
	int broj_poena;
public:
	Tim(const char ime[]);
	void ObradiUtakmicu(int broj_datih, int broj_primljenjih);
	const char* DajImeTima() const
	{
		return ime_tima;
	}
	int DajBrojPoena() const
	{
		return broj_poena;
	}
	int DajGolRazliku() const
	{
		return broj_datih-broj_primljenjih;
	}
	void IspisiPodatke() const;

};
Tim::Tim(const char ime[])
{
	broj_odigranih=0;
	broj_pobjeda=0;
	broj_nerijesenih=0;
	broj_odigranih=0;
	broj_poraza=0;
	broj_datih=0;
	broj_primljenjih=0;
	broj_poena=0;
	if(std::strlen(ime)>19) throw std::range_error ("Predugacko ime tima");
	std::strcpy(ime_tima,ime);
}
void Tim::ObradiUtakmicu(int broj_datih, int broj_primljenjih)
{
	if(broj_datih<0 || broj_primljenjih<0) throw std::range_error("Neispravan broj golova");
	Tim::broj_datih+=broj_datih;
	Tim::broj_primljenjih+=broj_primljenjih;
	broj_odigranih++;
	if(broj_datih==broj_primljenjih) {
		broj_nerijesenih++;
		broj_poena++;
	} else if(broj_datih>broj_primljenjih) {
		broj_pobjeda++;
		broj_poena+=3;
	} else broj_poraza++;

}
void Tim::IspisiPodatke() const
{

	std::cout << std::setw(20) << std::left << ime_tima << std::setw(4) << std::right
	          << broj_odigranih << std::setw(4) <<  broj_pobjeda << std::setw(4)
	          << broj_nerijesenih <<std::setw(4) << broj_poraza <<std::setw(4) << broj_datih << std::setw(4) << broj_primljenjih <<std::setw(4) << broj_poena << std::endl;
}
int main ()

{
	Tim L("Lejla");
	Tim D("Diana");
	L.ObradiUtakmicu(4,3);
	D.ObradiUtakmicu(8,2);
	D.ObradiUtakmicu(3,2);
	L.ObradiUtakmicu(1,3);
	std::cout << "gol razlika L: " << L.DajGolRazliku() << std::endl;
	std::cout << "poeni D: " << D.DajBrojPoena() << std::endl;
	L.IspisiPodatke();
	D.IspisiPodatke();
	
	return 0;
}
