//TP 2018/2019: Zadaća 4, Zadatak 5
#include <iostream>
#include<string>
#include<algorithm>
#include <map>
class Student
{
    int ind;
    std::string god;
    std::string imeip;
    std::string adr;
    std::string br;
    static bool JeLiBroj(char a);
    static void Namjesti(std::string &ime);
public:
    Student(int indeks, std::string godina, std::string ime, std::string adresa, std::string broj);
    int DajIndeks()const;
    std::string DajGodinuStudija()const;
    std::string DajImePrezime() const;
    std::string DajAdresu() const;
    std::string DajTelefon()const;
    void Ispisi()const;

};
bool Student::JeLiBroj(char a)
{
    if(a>='0' && a<='9') return true;
    return false;
}
void Student::Namjesti(std::string &ime)
{
    bool razmak=false;
    int i=0;
    int j=0;
    while(ime.at(j)==' ') {
        j++;
    }
    while(j<ime.size()) {
        if(ime.at(j)!=' ') {
            razmak=false;
            ime[i]=ime[j];
            i++;
            j++;

        } else if(ime.at(j)==' ') {
            j++;
            if(!razmak) {
                ime[i]=' ';
                i++;
                razmak=true;
            }

        }
    }
    ime.resize(i);
    if(ime.at(ime.size()-1)==' ') ime.resize(i-1);
}
Student::Student(int indeks, std::string godina, std::string ime, std::string adresa, std::string broj)
{
    if(indeks<10000 || indeks>99999) throw std::domain_error ("Neispravni parametri");
    if(godina!="1" && godina!="2" && godina!="3" && godina!="1/B"
            && godina!="2/B" && godina!="3/B" && godina!="1/M" && godina!="2/M" && godina!="1/D"
            && godina!="2/D" && godina!="3/D") throw std::domain_error("Neispravni parametri");
    Namjesti(ime);
    Namjesti(adresa);
    int i=1;
    int j=0;
    int k=0;
    if(!JeLiBroj(broj.at(0)) || !JeLiBroj(broj.at(broj.size()-1))) throw std::domain_error("Neispravni parametri");
    while(i!=broj.size()-1) {
        if(!JeLiBroj(broj.at(i)) && broj.at(i)!='-' && broj.at(i)!='/' ) throw std::domain_error("Neispravni parametri");
        if(broj.at(i)=='/' || broj.at(i)=='-') {
            if(!JeLiBroj(broj.at(i-1)) || !JeLiBroj(broj.at(i+1))) throw std::domain_error("Neispravni parametri");
            if(broj.at(i)=='/') {
                j++;
            } else k++;
            if(k>j) throw std::domain_error("Neispravni parametri");
        }
        i++;
    }
    if(k!=1 || j!=1) throw std::domain_error("Neispravni parametri");
    ind=indeks;
    imeip=ime;
    adr=adresa;
    br=broj;
    if(godina=="1") god="1/B";
    else if(godina=="2") god="2/B";
    else if(godina=="3") god="3/B";
    else god=godina;
}
std::string Student::DajImePrezime() const
{
    return imeip;
}
std::string Student::DajAdresu() const
{
    return adr;
}
std::string Student::DajGodinuStudija() const
{
    return god;
}
std::string Student::DajTelefon() const
{
    return br;
}
int Student::DajIndeks()const
{
    return ind;
}

void Student::Ispisi()const
{
    std::cout << "Broj indeksa: " << ind << std::endl
              <<"Godina studija: " << god << std::endl
              <<"Ime i prezime: " << imeip << std::endl
              <<"Adresa: " << adr << std::endl
              <<"Telefon: " << br << std::endl;
}
class Laptop
{
    int ev_broj;
    std::string naziv;
    std::string karakteristike;
    Student* kod_koga_je ;
public:
    Laptop(int evidencija, std::string naz, std::string kar)
    {
        if(evidencija<0) throw std::domain_error("Neispravni parametri");
        ev_broj=evidencija;
        naziv=naz;
        karakteristike=kar;
        kod_koga_je=nullptr;
    }
    int DajEvidencijskiBroj() const
    {
        return ev_broj;
    }
    std::string DajNaziv() const
    {
        return naziv;
    }
    std::string DajKarakteristike() const
    {
        return karakteristike;
    }
    Laptop Zaduzi(Student &st);
    Laptop Razduzi ();
    bool DaLiJeZaduzen() const
    {
        if(kod_koga_je==nullptr) return false;
        return true;
    }
    Student& DajKodKogaJe() const
    {
        if(kod_koga_je==nullptr) throw std::domain_error("Laptop nije zaduzen");
        return *kod_koga_je;
    }
    Student* DajPokKodKogaJe() const
    {
        return kod_koga_je;
    }
    void Ispisi() const;
};
Laptop Laptop::Zaduzi(Student &st)
{
    if(kod_koga_je!=nullptr) throw std::domain_error ("Laptop vec zaduzen");
    kod_koga_je=&st;
    return *this;
}
Laptop Laptop::Razduzi()
{
    if(kod_koga_je!=nullptr) kod_koga_je=nullptr;
    return *this;
}
void Laptop::Ispisi() const
{
    std::cout << "Evidencijski broj: " << ev_broj << std::endl
              << "Naziv: " << naziv << std::endl
              << "Karakteristike: " << karakteristike << std::endl;
}
class Administracija
{
    std::map<int,Student*> studenti;
    std::map<int,Laptop*> laptopi;
public:
    Administracija() { };
    Administracija(const Administracija &adm);
    Administracija(Administracija&& a);
    ~Administracija();
    Administracija& operator=(Administracija v);
    

    void RegistrirajNovogStudenta(int indeks, std::string godina, std::string ime, std::string adresa, std::string broj)
    {
        if(studenti.count(indeks)) throw std::domain_error ("Student s tim indeksom vec postoji");
        Student* pok=new Student(indeks, godina, ime, adresa, broj);
        studenti[indeks]=pok;
    }
    void RegistrirajNoviLaptop(int evidencija, std::string naz, std::string kar)
    {
        if(laptopi.count(evidencija)) throw std::domain_error("Laptop s tim evidencijskim brojem vec postoji");
        Laptop* lt=new Laptop(evidencija, naz, kar);
        laptopi.insert({evidencija,lt});
    }
    Student& NadjiStudenta(int indeks);
    Student NadjiStudenta(int indeks) const ;
    Laptop& NadjiLaptop(int evidencija);
    Laptop NadjiLaptop(int evidencija) const;
    void IzlistajLaptope() const;
    void IzlistajStudente() const;
    void ZaduziLaptop(int indeks, int evidencija);
    int NadjiSlobodniLaptop() const;
    void RazduziLaptop(int evidencija);
    void PrikaziZaduzenja() const;
};
Administracija::Administracija(const Administracija &adm)
{
    for(auto it=adm.studenti.begin(); it!=adm.studenti.end(); it++) {
        Student* pok=new Student(*(it->second));
        studenti[it->first]=pok;
    }
    for(auto it=adm.laptopi.begin(); it!=adm.laptopi.end(); it++) {
        Laptop* pok=new Laptop(*(it->second));
        laptopi[it->first]=pok;
    }
}
Administracija::~Administracija()
{
    for(auto it=studenti.begin(); it!=studenti.end(); it++) {
        delete it->second;
    }
    for(auto it=laptopi.begin(); it!=laptopi.end(); it++) {
        delete it->second;
    }
}
Administracija::Administracija(Administracija&& a){
    std::swap(laptopi,a.laptopi);
    std::swap(studenti,a.studenti);
    for(auto it=a.laptopi.begin();it!=a.laptopi.end();it++)
    it->second=nullptr;
    for(auto it=a.studenti.begin();it!=a.studenti.end();it++)
    it->second=nullptr;
}
Administracija& Administracija::operator=(Administracija v)
{
    std::swap(laptopi,v.laptopi);
    std::swap(studenti, v.studenti);
    return *this;
}
/*Administracija& Administracija::operator =(Administracija&& a)
{
    std::swap(laptopi,a.laptopi);
    std::swap(studenti,a.studenti);
    return *this;
}*/
Student& Administracija::NadjiStudenta(int indeks)
{
    if(!(studenti.count(indeks))) throw std::domain_error("Student nije nadjen");
    return *(studenti[indeks]);
}
Student Administracija::NadjiStudenta(int indeks) const
{
    if(!(studenti.count(indeks))) throw std::domain_error("Student nije nadjen");
    auto it=studenti.begin();
    for(it=studenti.begin(); it!=studenti.end(); it++)
        if((it->first)==indeks) break;
    return *(it->second);

}
Laptop& Administracija::NadjiLaptop(int evidencija)
{
    if(!(laptopi.count(evidencija))) throw std::domain_error("Laptop nije nadjen");
    return *(laptopi[evidencija]);
}
Laptop Administracija::NadjiLaptop(int evidencija) const
{
    if(!(laptopi.count(evidencija))) throw std::domain_error("Laptop nije nadjen");
    auto it=laptopi.begin();
    for(it=laptopi.begin(); it!=laptopi.end(); it++) {
        if((it->first)==evidencija) break;
    }
    return *(it->second);
}
void Administracija::IzlistajStudente() const
{
    for(auto it=studenti.begin(); it!=studenti.end(); it++) {
        (it->second)->Ispisi();
        std::cout << std::endl;
    }
}
void Administracija::IzlistajLaptope() const
{
    for(auto it=laptopi.begin(); it!=laptopi.end(); it++) {
        (it->second)->Ispisi();
        if((it->second)->DajPokKodKogaJe()!=nullptr) std::cout << "Zaduzio(la): " <<
                    (it->second)->DajPokKodKogaJe()->DajImePrezime() << " (" << (it->second)->DajPokKodKogaJe()->DajIndeks() <<")";
        std::cout << std::endl;
    }
}
void Administracija::ZaduziLaptop(int indeks, int evidencija)
{
    if(!studenti.count(indeks)) throw std::domain_error ("Student nije nadjen");
    if(!laptopi.count(evidencija)) throw std::domain_error ("Laptop nije nadjen");
    if(NadjiLaptop(evidencija).DaLiJeZaduzen()) throw std::domain_error ("Laptop vec zaduzen");
    Student* st=studenti[indeks];
    for(auto it=laptopi.begin(); it!=laptopi.end(); it++)
        if((it->second)->DajPokKodKogaJe()==st) throw std::domain_error("Student je vec zaduzio laptop");
    laptopi[evidencija]->Zaduzi(*st);
}
int Administracija::NadjiSlobodniLaptop() const
{
    for(auto it=laptopi.begin(); it!=laptopi.end(); it++) {
        if(it->second->DaLiJeZaduzen()==false) return it->first;
    }
    throw std::domain_error("Nema slobodnih laptopa");
}
void Administracija::RazduziLaptop(int evidencija)
{
    if(!laptopi.count(evidencija)) throw std::domain_error ("Laptop nije nadjen");
    if(!NadjiLaptop(evidencija).DaLiJeZaduzen()) throw std::domain_error ("Laptop nije zaduzen");
    laptopi[evidencija]->Razduzi();
}
void Administracija::PrikaziZaduzenja() const
{
    bool zaduzenja=false;
    for(auto it=laptopi.begin(); it!=laptopi.end(); it++)
        if(it->second->DajPokKodKogaJe()!=nullptr) {
            std::cout << "Student " << it->second->DajKodKogaJe().DajImePrezime() << " (" << it->second->DajPokKodKogaJe()->DajIndeks() <<
                      ") zaduzio/la laptop broj " << it->first << std::endl;
            zaduzenja=true;
        }
    if(!zaduzenja) std::cout << "Nema zaduzenja" << std::endl;
}



int main ()
{
    Administracija l;
    for(;;) {
        int n;
        std::cout << "Broj opcije:" << std::endl <<
                  "- 1 za unos studenta," << std::endl<<
                  "- 2 za unos laptopa," << std::endl<<
                  "- 3 za pretragu studenta po broju indeksa," << std::endl <<
                  "- 4 za pretragu laptopa po evidencijskom broju," << std::endl <<
                  "- 5 za izlistavanje studenata," << std::endl <<
                  "- 6 za izlistavanje laptopa," << std::endl <<
                  "- 7 za zaduzenje laptopa, " << std::endl <<
                  "- 8 za razduzenje laptopa, " << std::endl <<
                  "- 9 za pretragu slobodnog laptopa, " << std::endl <<
                  "-10 za prikaz zaduzenja," << std::endl <<
                  "- 0 za kraj" << std::endl;
        std::cout << "Unesite broj opcije: ";
        std::cin >> n;
        if(n==0) break;
        if(n<0 || n>10) std::cout << "Pogresna opcija. Ponovite unos." << std::endl;
        if(n==1) {
            std::cout << "Unesite indeks, godinu, ime, adresu i broj telefona studenta (ENTER poslije svakog unosa): ";
            int indeks;
            std::string godina, ime, adresa, broj;
            std::cin >> indeks;
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            std::getline(std::cin, godina);
            std::getline(std::cin, ime);
            std::getline(std::cin, adresa);
            std::getline(std::cin, broj);
            try {
                l.RegistrirajNovogStudenta(indeks, godina, ime, adresa, broj);
            } catch(std::domain_error d) {
                std::cout << d.what() << std::endl;
            }
        }
        if(n==2) {
            std::cout << "Unesite evidencijski broj, naziv i karakteristike laptopa(ENTER poslije svakog unosa): ";
            int ev;
            std::string naziv, kar;
            std::cin >> ev;
            std::getline(std::cin, naziv);
            std::getline(std::cin, kar);
            try {
                l.RegistrirajNoviLaptop(ev,naziv,kar);
            } catch(std::domain_error d) {
                std::cout << d.what() << std::endl;
            }
        }
        if(n==3) {
            std::cout << "Unesite broj indeksa: ";
            int indeks;
            std::cin>>indeks;
            try {
                l.NadjiStudenta(indeks).Ispisi();

            } catch(std::domain_error d) {
                std::cout << d.what() << std::endl;
            }
        }
        if(n==4) {
            std::cout << "Unesite evidencijski broj laptopa: ";
            int ev;
            std::cin >> ev;
            std::cin.clear();
            std::cin.ignore(1000,'\n');
            try {
                l.NadjiLaptop(ev).Ispisi();
            } catch(std::domain_error d) {
                std::cout << d.what() << std::endl;
            }
        }
        if(n==5) {
            std::cout << "Lista studenata: " << std::endl;
            l.IzlistajStudente();
        }
        if(n==6) {
            std::cout << "Lista laptopa: " << std::endl;
            l.IzlistajLaptope();
        }
        if(n==7) {
            std::cout << "Unesite indeks studenta i evidencijski broj laptopa: ";
            int indeks, ev;
            std::cin >> indeks >> ev;
            try {
                l.ZaduziLaptop(indeks, ev);
            } catch(std::domain_error d) {
                std::cout << d.what() << std::endl;
            }
        }
        if(n==8) {
            std::cout << "Unesite evidencijski broj laptopa: ";
            int ev;
            std::cin >> ev;
            try {
                l.RazduziLaptop(ev);
            } catch(std::domain_error d) {
                std::cout << d.what() << std::endl;
            }
        }
        if(n==9) {
            try {
                std::cout << "Slobodni laptop je sa evidencijskim brojem " << l.NadjiSlobodniLaptop() << "." << std::endl;

            } catch(std::domain_error d) {
                std::cout << d.what() << std::endl;
            }
        }
        if(n==10) {
            std::cout << "Zaduzenja:" << std::endl;
            l.PrikaziZaduzenja();
        }

    }
    return 0;
}
