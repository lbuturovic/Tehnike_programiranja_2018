//TP 2018/2019: Zadaća 3, Zadatak 2
#include <iostream>
#include <set>
#include <map>
#include <iterator>
bool DaLijeRazmak(char s)
{
    if((s>='a' && s<='z') || (s>='A' && s<='Z') || (s>='0' && s<='9')) return false;
    return true;
}
void PretvoriSveUMalaSlova(std::string &s)
{
    int i=0;
    while(i<s.size()) {
        if(s.at(i)>='A' && s.at(i)<='Z') s.at(i)=s.at(i)+32;

        i++;
    }
}
std::map <std::string, std::set<int>> KreirajIndeksPojmova(std::string rec)
{
    PretvoriSveUMalaSlova(rec);
    std::map<std::string, std::set<int>> mapa;
    int i=0;
    bool nijepocrijeci=true;
    while(i<rec.size()) {
        std::string rijec;
        if(DaLijeRazmak(rec.at(i))) nijepocrijeci=true;
        else if(nijepocrijeci) nijepocrijeci=false; //jeste pocetak rijeci

        if(nijepocrijeci==false) {
            int j=i;
            for(j=i; j<rec.size(); j++) {

                if(DaLijeRazmak(rec.at(j))) break;
                rijec+=rec.at(j);

            }

            if(mapa.count(rijec)==0) mapa[rijec]= {i};
            else mapa[rijec].insert(i);
            // mapa.insert({rijec,{i}});
            i=j-1;
        }



        i++;
    }



    return mapa;

}
std::set<int> PretraziIndeksPojmova(std::string rijec, std::map<std::string, std::set<int>> mapa)
{
    PretvoriSveUMalaSlova(rijec);
    if(!mapa.count(rijec)) throw std::logic_error("Pojam nije nadjen");
    return mapa[rijec];
}

void IspisiIndeksPojmova(std::map<std::string, std::set<int>> mapa)
{
    //auto it=mapa.begin();
    auto pom=mapa.begin();
    std::advance(pom,mapa.size()-1);
    //while(pom!=mapa.end()) pom++;

    for(auto it=mapa.begin(); it!=mapa.end(); it++) {
        std::cout << it->first << ": ";
        auto it2=(it->second).begin();
        auto p=it2;
        std::advance(p,(it->second).size()-1);
        //while(p!=(it->second).end()) p++;
        for(it2=(it->second).begin(); it2!=(it->second).end(); it2++) {
            if(it2!=p)std::cout << *it2 << ",";
            else std::cout << *it2 << std::endl;
        }
        //std::cout << *((it->second).end());
        //if(it==pom) std::cout << std::endl;
    }
}
int main ()
{
    std::string tekst;
    std::cout << "Unesite tekst: ";
    std::getline(std::cin, tekst);
    auto indeksi=KreirajIndeksPojmova(tekst);
    IspisiIndeksPojmova(indeksi);
    for(;;) {

        std::cout<< "Unesite rijec: ";
        std::string rijec;
        //std::cin.clear();
        //std::cin.ignore(1000, '\n');
        std::getline(std::cin, rijec); // >> rijec;
        if(rijec==".") break;
        try {

            auto brojevi=PretraziIndeksPojmova(rijec,indeksi);
            for(int a: brojevi) std::cout << a << " ";
        } catch(std::logic_error d) {
            std::cout << "Unesena rijec nije nadjena!";
        }
        std::cout << std::endl;
    }
    return 0;
}
