//TP 2018/2019: Tutorijal 14, Zadatak 2
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
class Spremnik {
    protected:
    double tezina;
    std::string naziv;
    public:
    Spremnik(double t, const char n[100]) : tezina(t), naziv(n) {}
    virtual ~Spremnik(){};
    double DajTezinu() const { return tezina; }
    virtual double DajUkupnuTezinu() const=0;
    virtual void Ispisi() const=0;
    virtual Spremnik* DajKopiju() const=0;
};
class Sanduk: public Spremnik{
    int broj;
    double tez; //pojedinacna tezina
    public:
    Sanduk(double t1, const char naziv [100], int br, double t2) : Spremnik(t1,naziv),
    broj(br), tez(t2){}
    double DajUkupnuTezinu() const override{
        return tezina+tez*broj;
    }
    void Ispisi() const override{
        std::cout << "Vrsta spremnika: Sanduk" << std::endl <<
        "Sadrzaj: " << naziv << std::endl <<
        "Vlastita tezina: " << tezina << " kg" << std::endl <<
        "Ukupna tezina: " << DajUkupnuTezinu() << " kg" << std::endl;
    }
    Spremnik* DajKopiju() const override{
        return new Sanduk(*this);
    }
};
class Bure: public Spremnik{
    double tez;
    public:
    Bure(double t1, const char naziv [100], double t2) : Spremnik(t1,naziv), tez(t2){}
    double DajUkupnuTezinu()  const override{
        return tezina+tez;
    }
    void Ispisi() const override{
        std::cout << "Vrsta spremnika: Bure" << std::endl <<
        "Sadrzaj: " << naziv << std::endl <<
        "Vlastita tezina: " << tezina << " kg" << std::endl <<
        "Ukupna tezina: " << DajUkupnuTezinu() << " kg" << std::endl;
    }
    Spremnik* DajKopiju() const override {
        return new Bure(*this);
    }
};
class Skladiste{
    int kapacitet,br;
    Spremnik** spremnici;
    public:
    explicit Skladiste(int kap): br(0),kapacitet(kap),
        spremnici(new Spremnik*[kap]{}) {}
    ~Skladiste();
    Skladiste(const Skladiste&s);
    Skladiste(Skladiste &&s) : spremnici(s.spremnici), br(s.br), kapacitet(s.kapacitet){}
    Skladiste& operator=(Skladiste s){
        std::swap(spremnici, s.spremnici);
        return *this;
    }
    Spremnik* DodajSanduk(double t1, const char naziv[100], int br, double t2);
    Spremnik*DodajBure(double t1, const char naziv [100], double t2);
    Spremnik& DajNajtezi();
    Spremnik& DajNajlaksi();
    int BrojPreteskih(int a) const;
    void IzlistajSkladiste() const;
    void UcitajIzDatoteke(std::string ime);
    
};
void Skladiste::UcitajIzDatoteke(std::string ime){
    std::ifstream ulazni_tok(ime);
    std::ifstream ulazni_tok2(ime);
    if(!ulazni_tok) throw std::logic_error("Trazena datoteka ne postoji");
    for(int i=0; i<br; i++) delete spremnici[i];
    br=0;
    char slovo;
    char razmak;
    bool problem=true;
    char pomocna [100];
    std::string str;
    while(std::getline(ulazni_tok,str)){
        std::getline(ulazni_tok2,str);
        slovo=str[0];
        razmak=str[1];
        if (str[2]==' ') throw std::logic_error("Datoteka sadrzi besmislene podatke");
        for(int i=2; i<str.size();i++)
        pomocna[i-2]=str.at(i);
        if((slovo!='B' && slovo!='S') || razmak!=' ') throw std::logic_error("Datoteka sadrzi besmislene podatke");
            std::string pomocni;
            std::getline(ulazni_tok2,pomocni);
            int i=0;
            if(pomocni.at(pomocni.size()-1)==' ' || pomocni.at(0)==' ') throw std::logic_error("Datoteka sadrzi besmislene podatke");
            while(i!=pomocni.size()){
                if(pomocni.at(i)==' ' && pomocni.at(i+1)==' ') throw std::logic_error("Datoteka sadrzi besmislene podatke");
                i++;
            }
      if(slovo=='B'){
          double t1;
          double t2;
          if(ulazni_tok>>t1 >> t2){
              DodajBure(t1,pomocna,t2);
          }
          else if(ulazni_tok.bad()) throw std::logic_error("Problem pri citanju datoteke");
          else throw std::logic_error("Datoteka sadrzi besmislene podatke");
      }
      if(slovo=='S'){
          double t1;
          double t2;
          int b;
          if(ulazni_tok>>t1>>b>>t2){
              DodajSanduk(t1,pomocna,b,t2);
          }
          else if(ulazni_tok.bad()) throw std::logic_error("Problem pri citanju datoteke");
          else throw std::logic_error("Datoteka sadrzi besmislene podatke");
      }
      ulazni_tok.ignore(1000,'\n');
      //ulazni_tok2.ignore(1000,'\n');
}
if(ulazni_tok.bad()) throw std::logic_error("Problem pri citanju datoteke");
if(!ulazni_tok.eof()) throw std::logic_error("Datoteka sadrzi besmislene podatke");
}
void Skladiste::IzlistajSkladiste() const {
    std::vector<Spremnik*> sp(br);
    for(int i=0; i<br; i++)
    sp.at(i)=spremnici[i];
    std::sort(sp.begin(),sp.end(),[](Spremnik* s1, Spremnik* s2){
        return s1->DajUkupnuTezinu()>s2->DajUkupnuTezinu();
    });
    for( Spremnik* s: sp) s->Ispisi();
}
int Skladiste::BrojPreteskih(int a) const{
    int broj=0;
    for(int i=0; i<br; i++)
    if(spremnici[i]->DajUkupnuTezinu()>a) broj++;
    return broj;
}
Spremnik& Skladiste::DajNajlaksi(){
    Spremnik* najlaksi=spremnici[0];
    for(int i=0; i<br; i++)
    if((spremnici[i]->DajTezinu())<najlaksi->DajTezinu()) najlaksi=spremnici[i];
    return *najlaksi;
}
Spremnik& Skladiste::DajNajtezi(){
    Spremnik* najtezi=spremnici[0];
    for(int i=0; i<br; i++)
    if((spremnici[i]->DajTezinu())>najtezi->DajTezinu()) najtezi=spremnici[i];
    return *najtezi;
}
Skladiste::~Skladiste(){
    for(int i=0; i<br; i++)
    delete spremnici[i];
    delete[] spremnici;
}
Skladiste::Skladiste(const Skladiste &s) : spremnici(new Spremnik*[s.kapacitet]{}),
kapacitet(s.kapacitet), br(s.br) {
    try{
        for(int i=0; i<s.br;i++)
        spremnici[i]=s.spremnici[i]->DajKopiju();
    }
    catch(...){
        for(int i=0; i<s.br;i++)
        delete spremnici[i];
        delete[] spremnici;
    }
}
Spremnik* Skladiste::DodajBure(double t1, const char naziv [100], double t2){
    if(br>=kapacitet) throw std::domain_error ("Popunjeno skladiste");
    Spremnik* s=new Bure(t1,naziv,t2);
    spremnici[br]=s;
    br++;
    return spremnici[br-1];
}
Spremnik* Skladiste::DodajSanduk(double t1, const char naziv [100], int broj, double t2){
    if(br>=kapacitet) throw std::domain_error ("Popunjeno skladiste");
    spremnici[br]=new Sanduk(t1, naziv, broj, t2);
    br++;
    return spremnici[br-1];
}

int main ()
{
    try{
        Skladiste sk(10);
        sk.UcitajIzDatoteke("ROBA.TXT");
        sk.IzlistajSkladiste();
    }
    catch(std::logic_error l){
        std::cout << l.what();
    }
	return 0;
}