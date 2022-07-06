//TP 2018/2019: Zadaća 5, Zadatak 6
#include <iostream>
#include <fstream>
#include <functional>
template<typename TipElemenata>
 class DatotecniKontejner {
     std::fstream tok;
     public:
     DatotecniKontejner (const std::string &ime_datoteke):
       tok(ime_datoteke, std::ios::binary | std::ios::in | std::ios::out | std::ios::app)
        {
            tok.close();
            tok.open(ime_datoteke, std::ios::binary | std::ios::in | std::ios::out);
             if(!tok) throw std::logic_error ("Problemi prilikom otvaranja ili kreiranja datoteke");
         }
     
   inline  void DodajNoviElement(const TipElemenata &element){
        // tok.seekp(0);
        // tok.seekp(0,std::ios::end);
         if(!tok.write(reinterpret_cast<const char*>(&element),sizeof(element)))
         throw std::logic_error("Problemi prilikom pristupa datoteci");
         tok.seekg(0, std::ios::cur);
     }
    inline int DajBrojElemenata() {
         tok.seekg(0);
         tok.seekg(0, std::ios::end);
        // if(tok.tellg()==0) return 0;
         int duzina=tok.tellg();
         //std::cout << sizeof(TipElemenata);
         return duzina/sizeof(TipElemenata);
     }
     
     TipElemenata DajElement(int pozicija){
         if(pozicija<0 || pozicija>=DajBrojElemenata()) throw std::range_error("Neispravna pozicija");
         tok.seekg(sizeof(TipElemenata)*pozicija);
         TipElemenata el;
         if(!tok.read((char*)&el,sizeof(el)))
         throw std::logic_error("Problemi prilikom pristupa datoteci");
         tok.seekg(0, std::ios::cur);
         return el;
     }
     void IzmijeniElement(int pozicija, const TipElemenata &element){
         if(pozicija<0 || pozicija>=DajBrojElemenata()) throw std::range_error("Neispravna pozicija");
         tok.seekp(sizeof(TipElemenata)*pozicija);
         if(!tok.write((char*)&element, sizeof(TipElemenata)))
         throw std::logic_error("Problemi prilikom pristupa datoteci");
         tok.seekg(0, std::ios::cur);
     }
     void Sortiraj(std::function<bool(const TipElemenata &, const TipElemenata&)>
     kriterij=std::less<TipElemenata>());
 };
// DatotecniKontejner::DatotecniKontejner(const std::string &ime_datoteke): tok(ime_datoteke,std::ios::out | std::ios::app) {}
int main ()
{
    DatotecniKontejner<int> d("l.DAT");
    std::cout << d.DajBrojElemenata();
	return 0;
}