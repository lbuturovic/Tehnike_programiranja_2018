//TP 2018/2019: Zadaća 5, Zadatak 3
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>
#include<fstream>
class Spremnik
{
protected:
    double tezina;
    std::string naziv;
public:
    Spremnik(double t, std::string n) : tezina(t), naziv(n) {}
    virtual ~Spremnik() {};
    double DajTezinu() const
    {
        return tezina;
    }
    virtual double DajUkupnuTezinu() const=0;
    virtual void Ispisi() const=0;
    virtual std::shared_ptr<Spremnik> DajKopiju() const=0;

};

class Sanduk :public Spremnik
{
    //double tezina;
    //std::string naziv;
    std::vector<double> tezine;
public:
    std::shared_ptr<Spremnik> DajKopiju() const override
    {
        return std::make_shared<Sanduk> (*this);
    }
    // za ovo se poziva konstruktor kopije
    Sanduk(double t, std::string n, std::vector<double> tez) : Spremnik(t, n), tezine(tez) {}
    double DajUkupnuTezinu() const override;
    //double DajTezinu()
    void Ispisi() const override;
};
void Sanduk::Ispisi() const
{
    std::cout << "Vrsta spremnika: Sanduk" << std::endl <<
              "Sadrzaj: " << naziv << std::endl <<
              "Tezine predmeta: ";
    for (double x : tezine) {
        std::cout << x << " ";
    }
    std::cout << "(kg)" << std::endl <<
              "Vlastita tezina: " << tezina << " (kg)" << std::endl <<
              "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
}
double Sanduk::DajUkupnuTezinu() const
{
    double s=tezina;
    for(int i=0; i<tezine.size(); i++)
        s+=tezine.at(i);
    return s;
}

class Vreca: public Spremnik
{
    //double tezina;
    //std::string naziv;
    double pohrtez;
public:
    Vreca(double t, std::string n, double tez) : Spremnik(t, n), pohrtez(tez) {}
    std::shared_ptr<Spremnik> DajKopiju() const override
    {
        return std::make_shared<Vreca> (*this);
    }
    double DajUkupnuTezinu() const override
    {
        return tezina + pohrtez;
    }
    void Ispisi() const override;

};
void Vreca::Ispisi() const
{
    std::cout << "Vrsta spremnika: Vreca" << std::endl <<
              "Sadrzaj: " << naziv << std::endl <<
              "Vlastita tezina: " << tezina << " (kg)"<< std::endl <<
              "Tezina pohranjene materije: " << pohrtez << " (kg)" << std::endl <<
              "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
}
class Bure: public Spremnik
{
    //double tezina;
    //std::string naziv;
    double gustina;
    double zapremina;
public:
    Bure(double t, std::string n, double gustina, double zapremina) : Spremnik(t, n), gustina(gustina),
        zapremina(zapremina) {}
    std::shared_ptr<Spremnik> DajKopiju() const override
    {
        return std::make_shared<Bure> (*this);
    }
    double DajUkupnuTezinu() const override
    {
        return tezina+(zapremina*gustina)/1000;
    }
    void Ispisi() const override;
};
void Bure::Ispisi() const
{
    std::cout << "Vrsta spremnika: Bure" << std::endl <<
              "Sadrzaj: " << naziv << std::endl <<
              "Vlastita tezina: " << tezina << " (kg)"<< std::endl <<
              "Specificna tezina tecnosti: " << gustina << " (kg/m^3)" << std::endl <<
              "Zapremina tecnosti: " << zapremina << " (l)" << std::endl <<
              "Ukupna tezina: " << DajUkupnuTezinu() << " (kg)" << std::endl;
}
class Skladiste
{
    std::vector<std::shared_ptr<Spremnik>> spremnici;
public:
    Skladiste () { }
    Skladiste (const Skladiste &s); // kopirajuci konst
    Skladiste (Skladiste &&s); // pomjerajuci operator
    Skladiste& operator =(Skladiste s)  //operator dodjele
    {
        std::swap(spremnici,s.spremnici);
        return *this;
    }
    Spremnik* DodajSanduk(double t, std::string n, std::vector<double> tezine);
    Spremnik* DodajBure(double t, std::string n, double gustina, double zapremina);
    Spremnik* DodajVrecu(double t, std::string n, double tez);
    Spremnik* DodajSpremnik(Spremnik* s, bool dinamicki);
    void BrisiSpremnik(Spremnik* s);
    Spremnik& DajNajlaksi();
    Spremnik& DajNajtezi(); //ne smiju se moci pozvati nad const objektima
    int BrojPreteskih(int a) const;
    void IzlistajSkladiste() const;
    void UcitajIzDatoteke(std::string ime);
};
void Skladiste::UcitajIzDatoteke(std::string ime)
{
    std::ifstream ulazni_tok(ime);
    std::ifstream ulazni_tokp(ime);
    if(!ulazni_tok) throw std::logic_error("Trazena datoteka ne postoji");
    for(int i=0; i<spremnici.size();i++){
        BrisiSpremnik(spremnici.at(i).get());
    }
    //while(!ulazni_tok.eof()) {
        char slovo;
        char razmak;
        bool problem=true;
        std::string naziv;
        std::string str;
        while(std::getline(ulazni_tok,str)){
            std::getline(ulazni_tokp,str);
        slovo=str[0];
        razmak=str[1];
        naziv=str.substr(2,str.size()-2);
        //else if(znak2!='\n') throw std::logic_error("Datoteka sadrzi besmislene podatke");
        if((slovo!='B' && slovo!='V' && slovo!='S') || razmak!=' ' || str[2]==' ') throw std::logic_error("Datoteka sadrzi besmislene podatke");
        std::string pomocni;
        std::getline(ulazni_tokp,pomocni);
        int i=0;
        if(pomocni.at(0)<'0' || pomocni.at(0)>'9' || pomocni.at(pomocni.size()-1)<'0' || pomocni.at(pomocni.size()-1)>'9') throw std::logic_error("Datoteka sadrzi besmislene podatke");
        while(i!=pomocni.size()){
            if(pomocni.at(i)==' ' && pomocni.at(i+1)==' ') throw std::logic_error("Datoteka sadrzi besmislene podatke");
            i++;
        }
        if(slovo=='B') {
            double zap;
            double tez;
            double gus;
            if(ulazni_tok >> tez >> gus >> zap) {
                if(ulazni_tok.peek()!='\n' && ulazni_tok.peek()!=EOF) throw std::logic_error("Datoteka sarzi besmislene podatke");
                DodajBure(tez,naziv,gus,zap);
            } else if(ulazni_tok.bad()) throw std::logic_error("Problem pri citanju datoteke");
            else  throw std::logic_error("Datoteka sadrzi besmislene podatke");
            // spremnici.push_back(std::make_shared<Spremnik>(tez,naziv,tezine));
        }
        problem=true;
        if(slovo=='S') {
            double br;
            double tez;
            int b;
            std::vector<double> tezine;
            ulazni_tok >> tez >> b;
            while(ulazni_tok >> br) {
                //if(razmak!=' ') throw std::logic_error("Datoteka sadrzi besmislene podatke");
                tezine.push_back(br);
                if(ulazni_tok.peek()=='\n') break;
                problem=false;
            }
            if(ulazni_tok.bad()) throw std::logic_error("Problem pri citanju datoteke");
            else if(problem || b!=tezine.size()) throw std::logic_error("Datoteka sadrzi besmislene podatke");
            DodajSanduk(tez,naziv,tezine);
        }
        if(slovo=='V') {
            double tez2;
            double tez1;
            if(ulazni_tok >> tez1 >> tez2) {
                if(ulazni_tok.peek()!='\n' && ulazni_tok.peek()!=EOF) throw std::logic_error("Datoteka sadrzi besmislene podatke");
                DodajVrecu(tez1,naziv,tez2);
            } else if(ulazni_tok.bad()) throw std::logic_error("Problem pri citanju datoteke");
            else throw std::logic_error("Datoteka sadrzi besmislene podatke");
            // spremnici.push_back(std::make_shared<Spremnik>(tez,naziv,tezine));
        }
        ulazni_tok.ignore(10000,'\n');
    }
    if(ulazni_tok.bad()) throw std::logic_error("Problem pri citanju datoteke");
    if(!ulazni_tok.eof()) throw std::logic_error("Datoteka sadrzi besmislene podatke");
}
void Skladiste::IzlistajSkladiste() const
{
    std::vector<std::shared_ptr<Spremnik>> sp=spremnici; //pomocni vektor za sortirani ispis
    std::sort(sp.begin(),sp.end(), [] (std::shared_ptr<Spremnik> s1, std::shared_ptr<Spremnik> s2) {
        return s1->DajUkupnuTezinu()>s2->DajUkupnuTezinu();
    });
    for(std::shared_ptr<Spremnik> s: sp) s->Ispisi();
}
int Skladiste::BrojPreteskih(int a) const
{
    return std::count_if(spremnici.begin(), spremnici.end(), [a](std::shared_ptr<Spremnik> s) {
        return s->DajUkupnuTezinu()>a;
    });
}
Spremnik& Skladiste::DajNajtezi()
{
    if(spremnici.size()==0) throw std::range_error("Skladiste je prazno");
    auto it=std::max_element(spremnici.begin(), spremnici.end(), [](std::shared_ptr<Spremnik> s1, std::shared_ptr<Spremnik> s2) {
        return (s2->DajTezinu()>s1->DajTezinu());
    });
    return **it;
}
Spremnik& Skladiste::DajNajlaksi()
{
    if(spremnici.size()==0) throw std::range_error("Skladiste je prazno");
    auto it=std::min_element(spremnici.begin(), spremnici.end(), [](std::shared_ptr<Spremnik> s1, std::shared_ptr<Spremnik> s2) {
        return (s2->DajTezinu()>s1->DajTezinu());
    });
    return **it;
}
void Skladiste::BrisiSpremnik(Spremnik* s)
{
    bool nadjen=false;
    for(int i=0; i<spremnici.size(); i++) {
        if(spremnici.at(i).get()==s) {
            spremnici.at(i)==nullptr;
            nadjen=true;
        }
    }
    if(nadjen) {
        std::remove(spremnici.begin(),spremnici.end(),nullptr);
        spremnici.resize(spremnici.size()-1);
    }
}
Spremnik* Skladiste::DodajSpremnik(Spremnik* s, bool dinamicki)
{
    // std::shared_ptr<Spremnik> p(s);
    if (dinamicki==true) {
        spremnici.push_back(std::shared_ptr<Spremnik>(s));
        return s;
    }
    std::shared_ptr<Spremnik> k=s->DajKopiju();
    spremnici.push_back(k);
    return k.get();
}
Spremnik* Skladiste::DodajSanduk(double t, std::string n, std::vector<double> tezine)
{
    std::shared_ptr<Spremnik> p=std::make_shared<Sanduk>(t,n,tezine);
    spremnici.push_back(p);
    return p.get();
}
Spremnik* Skladiste::DodajBure(double t, std::string n, double gustina, double zapremina)
{
    std::shared_ptr<Spremnik> p=std::make_shared<Bure>(t,n,gustina,zapremina);
    spremnici.push_back(p);
    return p.get();
}
Spremnik* Skladiste::DodajVrecu(double t, std::string n, double tez)
{
    std::shared_ptr<Spremnik> p=std::make_shared<Vreca>(t,n,tez);
    spremnici.push_back(p);
    return p.get();
}
Skladiste::Skladiste(const Skladiste &s)
{
    //spremnici=new std::vector<std::shared_ptr<Spremnik>>;
    for(int i=0; i< s.spremnici.size(); i++)
        spremnici.push_back(s.spremnici.at(i)->DajKopiju());
}
Skladiste::Skladiste(Skladiste &&s) : spremnici(s.spremnici)
{
    //s.spremnici=nullptr;
}
int main ()
{
    try{
        Skladiste moje;
        moje.UcitajIzDatoteke("ROBA.TXT");
        moje.IzlistajSkladiste();
    }
    catch(std::logic_error l){
        std::cout << l.what();
    }
    return 0;
}
