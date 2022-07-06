//TP 2018/2019: Zadaća 4, Zadatak 3
#include <iostream>
#include <utility>
#include <vector>
class Datum{
    int d;
    int m;
    int g;
    static int KolikoDanaIma(int mjesec, int godina);
    public:
    Datum(int dan, int mjesec, int godina);
    void Postavi(int dan, int mjesec, int godina);
    std::tuple<int, int, int> Ocitaj () const;
    void Ispisi() const;
};
 int Datum::KolikoDanaIma(int mjesec, int godina){
     std::vector<int> dani{0,31,0,31,30,31,30,31,31,30,31,30,31};
     if(mjesec==2){
         if(godina%4==0 && godina % 100 !=0 || godina % 400==0) return 29;
         else return 28;
     }
     return dani.at(mjesec);
 }
 void Datum::Postavi(int dan, int mjesec, int godina ){
     if(dan<=0 || dan>KolikoDanaIma(mjesec,godina) || mjesec<=0 || mjesec>12 || godina<=0)
     throw std::domain_error("Neispravan datum");
     d=dan;
     m=mjesec;
     g=godina;
 }
 Datum::Datum(int dan, int mjesec, int godina){
     Postavi(dan,mjesec,godina);
 }
 std::tuple<int, int, int>Datum::Ocitaj() const
int main ()
{
	return 0;
}