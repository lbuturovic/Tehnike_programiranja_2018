/* 
    TP 16/17 (Tutorijal 11, Zadatak 5)
	Autotestove napisao Haris Hasic. Sve primjedbe/zalbe, sugestije
	i pitanja slati na mail: hhasic2@etf.unsa.ba.
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <cstring>
#include <iomanip>
#include <initializer_list>
#include <algorithm>
#include <vector>
#include <memory>
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
	//Tim(const Tim& t) {} //kad postavim kopiracuji konst pise pri ispisu da tim nije nadjen, dakle nije stvoren
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
class Liga
{
	//int broj_timova;
	
	std::vector<std::shared_ptr<Tim>> timovi;
	static bool KriterijSortiranja(std::shared_ptr<Tim> tim1, std::shared_ptr<Tim> tim2);
public:
	explicit Liga();
	explicit Liga(std::initializer_list<Tim> lista_timova);
	~Liga();
	Liga(const Liga &l);
	Liga(Liga &&l);
	//Liga &operator = (Liga l);
	Liga &operator = (const Liga &l);
	Liga &operator = (Liga &&l);
	void DodajNoviTim(const char ime_tima[]);
	void RegistrirajUtakmicu(const char tim1[], const char tim2[], int rezultat1, int rezultat2);
	void IspisiTabelu();

};
Liga::Liga() = default;
Liga::~Liga()
{ }
//sekvencijski konstruktor (in. lista)
Liga::Liga(std::initializer_list<Tim> lista_timova) : timovi(lista_timova.size())
{
	int i=0;
	//std::copy(lista_timova.begin(),lista_timova.end(),*timovi);
	for(auto p=lista_timova.begin(); p!=lista_timova.end(); p++){
		timovi[i]=std::make_shared<Tim>(*p);
		i++;
	}
}
// r-vr konst
Liga::Liga(Liga &&l)=default;

Liga::Liga(const Liga &l) : timovi(l.timovi.size()) //napravi vektor timovi koji ima duzinu kao timovi od l
{

	try {
		for(int i=0; i<l.timovi.size(); i++)
		timovi.at(i)=std::make_shared<Tim>(*l.timovi.at(i));

	} catch(...) {
		
		throw;
	}

}
// kopirajuci op dodjele
Liga& Liga::operator= (const Liga &l)
{	timovi.resize(l.timovi.size());
	for(int i=0; i<l.timovi.size(); i++){
		timovi.at(i)=std::make_shared<Tim>(*l.timovi.at(i));
	}
	
	return *this;
} 

Liga &Liga::operator = (Liga && l)
{
	
	timovi=std::move(l.timovi);
	return *this;
}
void Liga::DodajNoviTim(const char ime_tima[])
{
	
	for(int i=0; i<timovi.size(); i++)
		if(std::strcmp(timovi[i]->DajImeTima(),ime_tima)==0) throw std::logic_error("Tim vec postoji");
	std::shared_ptr<Tim> novitim=nullptr;
	try {
		novitim= std::make_shared<Tim>(ime_tima);
		timovi.push_back(novitim);
		//broj_timova++;
	} catch(...) {
		//delete novitim;
	}
	//novitim=nullptr;
}
void Liga::RegistrirajUtakmicu(const char tim1[], const char tim2[], int rezultat1, int rezultat2)
{
	bool nadjen=false;
	for(int i=0; i<timovi.size(); i++) {
		if(std::strcmp(timovi[i]->DajImeTima(),tim1)==0) nadjen=true;
	}
	if(!nadjen) throw std::logic_error("Tim nije nadjen");
	nadjen=false;
	for(int i=0; i<timovi.size(); i++) {
		if(std::strcmp(timovi[i]->DajImeTima(),tim2)==0) {
			nadjen=true;
			break;
		}
	}
	if(!nadjen) throw std::logic_error ("Tim nije nadjen");
	if(rezultat1<0 || rezultat2<0) throw std::range_error("Neispravan broj golova");
	for(int i=0; i<timovi.size(); i++) {
		if(std::strcmp(timovi[i]->DajImeTima(),tim1)==0) (*timovi[i]).ObradiUtakmicu(rezultat1, rezultat2);
		if(std::strcmp(timovi[i]->DajImeTima(),tim2)==0) (*timovi[i]).ObradiUtakmicu(rezultat2, rezultat1);
	}
}
bool Liga::KriterijSortiranja(std::shared_ptr<Tim> tim1, std::shared_ptr<Tim> tim2)
{
	bool jednaki=false;
	if(tim1->DajBrojPoena()==tim2->DajBrojPoena()) jednaki=true;
	if(tim1->DajBrojPoena()>tim2->DajBrojPoena()) return true;
	if(jednaki && tim1->DajGolRazliku()>tim2->DajGolRazliku()) return true;
	if(jednaki && tim1->DajGolRazliku()<tim2->DajGolRazliku()) return false;
	if(jednaki && std::strcmp(tim1->DajImeTima(),tim2->DajImeTima())>0) return false;
	if(jednaki && std::strcmp(tim1->DajImeTima(), tim2->DajImeTima())<=0) return true;
	return false;
}
void Liga::IspisiTabelu()
{
	std::sort(timovi.begin(), timovi.end(), KriterijSortiranja);
	for(int i=0; i<timovi.size(); i++) (timovi[i]->IspisiPodatke());
}
int main ()
{
	Liga liga{"Celik","Borac", "Jedinstvo", "Zeljeznicar", "Zrinjski","Sarajevo"};
	while(1){
	char prvi[20], drugi[20];
	liga.IspisiTabelu();	
	std::cout << "Unesite ime prvog tima (ENTER za kraj): ";
	std::cin.getline(prvi,20);
	if(std::strcmp(prvi,"")==0) break;
	std::cout << "Unesite ime drugog tima: ";
	std::cin.getline(drugi,20);
	if(std::strcmp(drugi,"")==0) break;	
	int g1, g2;
	std::cout << "Unesite broj postignutih golova za oba tima: ";	
	std::cin>>g1;
	std::cin >>g2;
	try {
		liga.RegistrirajUtakmicu(prvi, drugi, g1, g2);
	}
	catch(std::logic_error l){
		std::cout << l.what();
	}
	catch(std::range_error r){
		std::cout << r.what();
	}
	catch(...){
		
	}
	}
	
	return 0;
}
