/* 
    TP 16/17 (Tutorijal 13, Zadatak 2)
	Autotestove pisala Ivona Ivkovic. Sva pitanja, sugestije, prijave gresaka
	slati na mail iivkovic2@etf.unsa.ba
	
	Vrsit ce se provjera na prepisivanje tutorijala (na kraju semestra)
*/
#include <iostream>
#include <string>
#include <vector>
class ApstraktniStudent{
	protected:
	std::string ime;
	std::string prezime;
	int indeks;
	int polozeni;
	double prosjek;
	public:
	ApstraktniStudent(std::string i, std::string p, int in) : ime(i), prezime(p), indeks(in), polozeni(0), prosjek(5) {}
	virtual~ApstraktniStudent() {};
	std::string DajIme() const{ return ime;}
	std::string DajPrezime ()const{ return prezime;}
	int DajBrojIndeksa() const{ return indeks;}
	int DajBrojPolozenih() const{ return polozeni;}
	double DajProsjek() const{ return prosjek;}
	void RegistrirajIspit(int ocjena);
	void PonistiOcjene() {
		prosjek=5;
		polozeni=0;
	}
	virtual void IspisiPodatke () const;
	virtual ApstraktniStudent* DajKopiju() const=0;
	
};
class StudentBachelor : public ApstraktniStudent{
	
	public:
	StudentBachelor(std::string i, std::string p, int in) : ApstraktniStudent(i,p,in){ indeks=in; polozeni=0; prosjek=5;}
	~StudentBachelor()override {};
	 void IspisiPodatke () const override;
	 StudentBachelor* DajKopiju() const override {
	 	return new StudentBachelor(*this);
	 }
	
};
class StudentMaster : public ApstraktniStudent{
	int zavrsen;
	public:
	StudentMaster(std::string i, std::string p, int in, int z) : ApstraktniStudent(i,p,in){ indeks=in; polozeni=0; prosjek=5; zavrsen=z;}
	~StudentMaster() override {};
	 void IspisiPodatke () const override;
	 StudentMaster* DajKopiju() const override {
	 	return new StudentMaster(*this);
	 }
	
};

void ApstraktniStudent::RegistrirajIspit(int ocjena){
	if(ocjena<5 || ocjena>10) throw std::domain_error ("Neispravna ocjena");
	if(ocjena!=5) {
		double pr=prosjek*polozeni;
		polozeni++;
	prosjek=(pr+ocjena)/polozeni;
	//	std::cout << prosjek << "      ";
	}
}
void ApstraktniStudent::IspisiPodatke() const {
	
	std::cout << "Student " << ime << " " << prezime << "," << std::endl << " sa brojem indeksa " << indeks << ", ima prosjek " << prosjek << "." << std::endl;
}
void StudentBachelor::IspisiPodatke() const {
	
	std::cout << "Student bachelor studija " << ime << " " << prezime << ", sa brojem indeksa " << indeks << "," << std::endl << "ima prosjek " << prosjek << "." << std::endl;
}
void StudentMaster::IspisiPodatke() const {
	
	std::cout << "Student master studija " << ime << " " << prezime << ", sa brojem indeksa " << indeks << "," << std::endl << "zavrsio bachelor studij godine " << zavrsen <<
	",ima prosjek " << prosjek << "." << std::endl;
}
class Fakultet {
	std::vector<ApstraktniStudent*> studenti;
	public:
	Fakultet (){}
	~Fakultet(){
		for(int i=0; i<studenti.size(); i++)
		delete studenti[i];
	}
	Fakultet(const Fakultet& f): studenti(f.studenti.size()){
		for(int i=0; i<studenti.size();i++){
			studenti.at(i)=f.studenti.at(i);
		}
	}
};
int main ()
{
	return 0;
}