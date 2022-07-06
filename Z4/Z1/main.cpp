//TP 2018/2019: Zadaća 4, Zadatak 1
#include <iostream>
#include <utility>
#include <cmath>
#include <set>
#include <memory>
#include <algorithm>
#include <vector>
const double epsilon=0.0000001;
typedef std::pair<double,double> Tacka;
class Trougao
{
    Tacka p;
    Tacka d;
    Tacka t;
    static double racun (Tacka t1, Tacka t2, Tacka t3)
    {
        return t1.first*(t2.second-t3.second)-t2.first*(t1.second-t3.second)+t3.first*(t1.second-t2.second);
    }
    void ProvjeraIndeksa(int indeks) const
    {
        if(indeks <1 || indeks >3) throw std::range_error ("Nekorektan indeks");
    }

    /*void SkalirajTacku(Tacka &t, Tacka c, double k)
    {
        t.first=c.first+k*(t.first-c.first);
        t.second=c.second+k*(t.second-c.second);
    }*/
public:
    Trougao (const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3);
    void Postavi(int indeks, const Tacka &t);
    static int Orijentacija (const Tacka &t1, const Tacka &t2, const Tacka &t3);
    Tacka DajTjeme (int indeks) const
    {
        ProvjeraIndeksa(indeks);
        if(indeks==1) return p;
        if(indeks==2) return d;
        return t;
    }
    double DajStranicu(int indeks) const;
    double DajUgao (int indeks) const;
    Tacka DajCentar () const;
    double DajObim () const;
    double DajPovrsinu () const;
    bool DaLiJePozitivnoOrijentiran() const;
    bool DaLiJeUnutra (const Tacka &t) const;
    void Ispisi () const;
    void Transliraj (double delta_x, double delta_y);
    void Centriraj (const Tacka &t);
    void Rotiraj (const Tacka &t, double ugao);
    void Skaliraj (const Tacka &t, double faktor);
    void Rotiraj(double ugao);
    void Skaliraj(double faktor);
    friend bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2);
    friend bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2);
};
void Trougao::Postavi(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    if(fabs(racun(t1,t2,t3))<epsilon) throw std::domain_error("Nekorektne pozicije tjemena");
    p=t1;
    d=t2;
    t=t3;
}
Trougao::Trougao(const Tacka &t1,const Tacka &t2, const Tacka &t3)
{
    Postavi(t1, t2, t3);
}
void Trougao::Postavi(int indeks, const Tacka &t )
{
    ProvjeraIndeksa(indeks);
    if(indeks==1) {
        if(fabs(racun(t,d,Trougao::t))<epsilon)  throw std::domain_error ("Nekorektne pozicije tjemena");
        p=t;

    } else if(indeks==2) {
         if(fabs(racun(p,t,Trougao::t))<epsilon) throw std::domain_error("Nekorektne pozicije tjemena");
        d=t;

    } else {
        if(fabs(racun(p,d,t))<epsilon) throw std::domain_error ("Nekorektne pozicije tjemena");
        Trougao::t=t;
    }

}
void Trougao::Ispisi() const
{
    std::cout << "((" << p.first <<"," << p.second << "),(" << d.first
              << "," << d.second << "),(" << t.first << "," << t.second << "))";
}
int Trougao::Orijentacija(const Tacka &t1, const Tacka &t2, const Tacka &t3)
{
    if(fabs(racun(t1, t2, t3))<epsilon) return 0;
    if(racun(t1,t2,t3)>0) return 1;
    return -1;
}
double Trougao::DajStranicu(int indeks) const
{
    ProvjeraIndeksa(indeks);
    if(indeks==1) return sqrt((d.first-t.first)*(d.first-t.first)+(d.second-t.second)*(d.second-t.second));
    if(indeks==2) return sqrt((p.first-t.first)*(p.first-t.first)+(p.second-t.second)*(p.second-t.second));
    return sqrt((p.first-d.first)*(p.first-d.first)+(p.second-d.second)*(p.second-d.second));
}

double Trougao::DajUgao(int indeks) const
{
    ProvjeraIndeksa(indeks); // ne treba jer u DuzinaStranice ima provjera indeksa
    // a*a=b*b+c*c-2abcos(<)(b,c))
    int b,c;
    if(indeks==1) {
        b=2;
        c=3;
    } else if(indeks==2) {
        b=1;
        c=3;
    } else {
        b=1;
        c=2;
    }
    double ugao=acos((-pow(DajStranicu(indeks),2)+pow(DajStranicu(b),2)+pow(DajStranicu(c),2))/(2*DajStranicu(b)*DajStranicu(c)));
    return ugao;

}
Tacka Trougao::DajCentar() const
{
    //if (fabs(racun(p,d,t))<epsilon)
    Tacka centar;
    centar.first=(p.first+d.first+t.first)/3;
    centar.second=(p.second+d.second+t.second)/3;
    return centar;
}
double Trougao::DajObim() const
{

    return DajStranicu(1)+DajStranicu(2)+DajStranicu(3);
}
double Trougao::DajPovrsinu() const
{
    return 0.5*fabs(racun(p,d,t));
}
bool Trougao::DaLiJePozitivnoOrijentiran() const
{
    return Orijentacija(p,d,t);
}
bool Trougao::DaLiJeUnutra(const Tacka &t) const
{
    int o=Orijentacija(t,p,d);
    if(o==0) return false;
    if(Orijentacija(t,d,Trougao::t)==o
            && Orijentacija(t,Trougao::t,p)==o) return true;
    return false;
}
void Trougao::Transliraj(double delta_x, double delta_y)
{
    p.first+=delta_x;
    p.second+=delta_y;
    d.first+=delta_x;
    d.second+=delta_y;
    t.first+=delta_x;
    t.second+=delta_y;
}
void Trougao::Centriraj(const Tacka &t)
{
    double razlikax=t.first-DajCentar().first;
    double razlikay=t.second-DajCentar().second;
    Transliraj(razlikax, razlikay);
}
void Trougao::Rotiraj(const Tacka &t, double ugao)
{
    Tacka pom;
    Tacka pom1, pom2, pom3; //pomocne tacke
    for(int i=1; i<4; i++) {
        pom.first=t.first+(DajTjeme(i).first-t.first)*cos(ugao)-(DajTjeme(i).second-t.second)*sin(ugao);
        pom.second=t.second+(DajTjeme(i).first-t.first)*sin(ugao)+(DajTjeme(i).second-t.second)*cos(ugao);
        if(i==1) pom1=pom;
        if(i==2) pom2=pom;
        if(i==3) pom3=pom;
        //Postavi(i,pom);
    }
    Postavi(pom1,pom2,pom3);
}
void Trougao::Rotiraj( double ugao)
{
    Rotiraj(DajCentar(),ugao);
}
void Trougao::Skaliraj(const Tacka &t, double faktor)
{
    if(fabs(faktor)<epsilon) throw std::domain_error ("Nekorektan faktor skaliranja");
    std::vector<Tacka> pom(3);
    for(int i=1; i<4; i++) {
        pom.at(i-1).first=t.first+faktor*(DajTjeme(i).first-t.first);
        pom.at(i-1).second=t.second+faktor*(DajTjeme(i).second-t.second);
    }
    Postavi(pom.at(0),pom.at(1),pom.at(2));
}
void Trougao::Skaliraj(double faktor)
{
    Skaliraj(DajCentar(),faktor);
}
bool DaLiSuIdenticni(const Trougao &t1, const Trougao &t2)
{
    Tacka pom=t1.DajTjeme(1);
    bool nadjena=false;
    int i;
    for(i=1; i<4; i++){
        if(fabs(t2.DajTjeme(i).first-pom.first)<epsilon && fabs(t2.DajTjeme(i).second-pom.second)<epsilon) {
            nadjena=true;
            break;
        }
    }
    if(!nadjena) return false;
    int a,b;
    if(i==1){
        a=2;
        b=3;
    }
    else if(i==2){
        a=1;
        b=3;
    }
    else {
        a=1;
        b=2;
    }
    pom=t1.DajTjeme(2);
    nadjena=false;
    if(fabs(pom.first-t2.DajTjeme(a).first)<epsilon && fabs(pom.second-t2.DajTjeme(a).second)<epsilon){
        if(fabs(t1.DajTjeme(3).first-t2.DajTjeme(b).first)< epsilon && fabs(t1.DajTjeme(3).second-t2.DajTjeme(b).second)<epsilon) return true;
    }
    if(fabs(pom.first-t2.DajTjeme(b).first)<epsilon && fabs(pom.second-t2.DajTjeme(b).second)<epsilon){
        if(fabs(t1.DajTjeme(3).first-t2.DajTjeme(a).first)<epsilon && fabs(t1.DajTjeme(3).second-t2.DajTjeme(a).second)<epsilon) return true;
    }
    return false;
}
bool DaLiSuPodudarni(const Trougao &t1, const Trougao &t2)
{
    Trougao t11=t1;
    Trougao t22=t2;
    bool pronadjen=false;
    std::set<double> pom;
    //int indeks2;
    int i;
    for(i=1; i<4; i++) {
        if((fabs(t11.DajUgao(1)-t22.DajUgao(i))<epsilon)) {
            t22.Transliraj(-t22.DajTjeme(i).first,-t22.DajTjeme(i).second);
            //indeks2=i;
            pronadjen=true;
            break;
        }
    }

    if(!pronadjen) return false;
    t11.Transliraj(-t11.p.first,-t11.p.second);
    // pomjeram za -x koordinatu i za -y koordinatu
    double ref1=t11.DajStranicu(2);
    // double ref11=t11.DajStranicu(3);
    int m,n;
    if(i==1) {
        m=2;
        n=3;
    } else if(i==2) {
        m=1;
        n=3;
    } else {
        m=1;
        n=2;
    }
    int a;
    double ref2=t22.DajStranicu(m);
    double ref22=t22.DajStranicu(n);
    int b;
    if(fabs(ref1-ref2)<epsilon) {
        a=n;
        b=m;
    } else if(fabs(ref1-ref22)<epsilon) {
        a=m;
        b=n;
    } else return false;
    double ugao1cos=acos(t11.DajTjeme(3).first/t11.DajStranicu(2));
    double ugao2cos=acos(t22.DajTjeme(a).first/t22.DajStranicu(b));
    double ugao1=atan(t11.DajTjeme(3).second/t11.DajTjeme(3).first);
    double ugao2=atan(t22.DajTjeme(a).second/t22.DajTjeme(a).first);
    if(fabs(ugao1)<epsilon) ugao1=ugao1cos;
    if(fabs(ugao2)<epsilon) ugao2=ugao2cos;
    if(fabs(t11.DajTjeme(3).first)<epsilon) {
        if(t11.DajTjeme(3).second>=0) ugao1=2*atan(1);
        else ugao1=-2*atan(1);
    }
    if(fabs(t22.DajTjeme(a).first)<epsilon) {
        if(t22.DajTjeme(a).second>=0) ugao2=2*atan(1);
        else ugao2=-2*atan(1);
    }
    t11.Rotiraj({0,0},-ugao1);
    t22.Rotiraj({0,0},-ugao2);
    return DaLiSuIdenticni(t11,t22);
}
bool DaLiSuSlicni(const Trougao &t1, const Trougao &t2)
{
    double refugao=t1.DajUgao(1);
    int m;
    bool pronadjen=false;
    for(m=1; m<4; m++) {
        if(fabs(refugao-t2.DajUgao(m))<epsilon) {
            pronadjen=true;
            break;
        }
    }
    if(!pronadjen) return false;
    double str1=t1.DajStranicu(1);
    double str2=t2.DajStranicu(m);
    double faktor=str2/str1;
    Trougao t22=t2;
    t22.Skaliraj(1/faktor);
    return DaLiSuPodudarni(t1, t22);
}
bool sadrzan(std::vector<std::pair<int, int>> v, std::pair<int, int> par)
{

    for(int i=0; i<v.size(); i++) {


        if(v.at(i).first==par.first && v.at(i).second==par.second) return true;
    }

    return false;
}
int main ()
{
    int n;
    std::cout << "Koliko zelite kreirati trouglova: ";
    std::cin>>n;
    double x1,x2,x3,y1,y2,y3;
    std::vector<std::shared_ptr<Trougao>> trouglovi;
    std::shared_ptr<Trougao> pok;
    for(int i=0; i<n; i++) {
        std::cout << "Unesite podatke za " << i+1 << ". trougao (x1 y1 x2 y2 x3 y3): ";
        std:: cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        try {
            pok=std::shared_ptr<Trougao>(new Trougao({x1,y1}, {x2,y2}, {x3,y3}));
            trouglovi.push_back(pok);
        } catch(std::domain_error s) {
            std::cout << s.what() << ", ponovite unos!" << std::endl;
            i--;
        }
        //std::cout <<  std::endl;
    }
    double k1,k2;
    double ugao;
    double fakt;
    std::cout << "Unesite vektor translacije (dx dy): ";
    std::cin >> k1 >> k2;
    std::cout << "Unesite ugao rotacije: ";
    std::cin >> ugao;
    std::cout << "Unesite faktor skaliranja: ";
    std::cin >> fakt;
    bool uhvacen=false;
    std::transform(trouglovi.begin(),trouglovi.end(),trouglovi.begin(), [k1,k2,ugao,fakt,&uhvacen](std::shared_ptr<Trougao> t) {
        t->Transliraj(k1,k2);
        t->Rotiraj(ugao);
        //static bool uhvacen=false;
        //std::cout << "Rotirani ugao: ";t->Ispisi();
        try {
            t->Skaliraj(t->DajTjeme(1),fakt);
        } catch(std::domain_error d) {
            if(!uhvacen) std::cout << d.what() << std::endl;
            uhvacen=true;
        }
        return t;
    });
    std::sort(trouglovi.begin(),trouglovi.end(),[](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2) {
        return t1->DajPovrsinu()<t2->DajPovrsinu();
    }    );
    std::cout << "Trouglovi nakon obavljenih transformacija:" << std::endl;
    std::for_each(trouglovi.begin(),trouglovi.end(),[](std::shared_ptr<Trougao> t) {
        t->Ispisi();
        std::cout << std::endl;
    });
    std::cout << "Trougao sa najmanjim obimom: ";
    auto p=std::min_element(trouglovi.begin(),trouglovi.end(),[](std::shared_ptr<Trougao> t1, std::shared_ptr<Trougao> t2) {
        return t1->DajObim()<t2->DajObim();
    });
    pok=*p;
    pok->Ispisi();
    std::cout << std::endl;
    std::vector<std::pair<Trougao, Trougao>> identicni;
    std::vector<std::pair<Trougao,Trougao>> podudarni;
    std::vector <std::pair<Trougao, Trougao>> slicni;
   // std::cout << trouglovi.size();
    for(int i=0; i<trouglovi.size(); i++){
    
        for(int j=i+1; j<trouglovi.size(); j++) {

            if( DaLiSuIdenticni(*trouglovi.at(i),*trouglovi.at(j))){

                identicni.push_back(std::make_pair(*trouglovi.at(i),*trouglovi.at(j)));
                
            }
            if( DaLiSuPodudarni(*trouglovi.at(i),*trouglovi.at(j)))
                podudarni.push_back(std::make_pair(*trouglovi.at(i),*trouglovi.at(j)));
            if( DaLiSuSlicni(*trouglovi.at(i),*trouglovi.at(j)))
                slicni.push_back(std::make_pair(*trouglovi.at(i),*trouglovi.at(j)));
        }
    }
    
    if(identicni.size()==0) std::cout << "Nema identicnih trouglova!" << std::endl;
    else {
        std::cout <<  "Parovi identicnih trouglova: ";
        for(int i=0; i<identicni.size(); i++) {
            std::cout << std::endl;
            identicni.at(i).first.Ispisi();
            std::cout <<" i ";
            identicni.at(i).second.Ispisi();

        }
        std::cout << std::endl;
    }
    if(podudarni.size()==0) std::cout << "Nema podudarnih trouglova!" << std::endl;
    else {
        std::cout << "Parovi podudarnih trouglova: ";
        for(int i=0; i<podudarni.size(); i++) {
            std::cout << std::endl;
            podudarni.at(i).first.Ispisi();
            std::cout << " i ";
            podudarni.at(i).second.Ispisi();
        }
    std::cout <<  std::endl;
    }
    if(slicni.size()==0) std::cout << "Nema slicnih trouglova!" << std::endl;
    else {
        std::cout << std::endl << "Parovi slicnih trouglova: ";
        for(int i=0; i<slicni.size(); i++) {
            std::cout << std::endl;
            slicni.at(i).first.Ispisi();
            std::cout << " i ";
            slicni.at(i).second.Ispisi();
        }
    }
    /* Trougao t({1,2},{6,7},{10,13});
     Tacka tu= t.DajCentar();
     std::cout <<"centar: " << tu.first << ", " << tu.second << std::endl;
      t.Rotiraj(0);
      t.Ispisi();
      std::cout << std::endl;
    t.Skaliraj(t.DajTjeme(1),3);
      //t.Rotiraj(2);
     std::cout << "Nakon skaliranja: "; t.Ispisi(); */

    return 0;
}
