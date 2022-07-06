//TP 2018/2019: Zadaća 3, Zadatak 4
#include <iostream>
#include <set>
#include <list>
#include <vector>
bool JeLiUImenu(char s)
{
    if((s>='a' && s<='z') || (s>='A' && s<='Z') || (s>='0' && s<='9')) return true;
    return false;
}
int BrojSlova (std::string s)
{
    int i=0;
    int duzina=0;
    while(i!=s.size()) {
        if(JeLiUImenu(s.at(i))) duzina ++;


        i++;
    }
    return duzina;
}
std::vector<std::set<std::string>> Razvrstavanje (std::vector<std::string> djecica, int n)
{
    if(n<=0 || n>djecica.size()) throw std::logic_error("Razvrstavanje nemoguce");
    std::list<std::string> listadj;
    int i=0;
    while(i!=djecica.size()) {
        listadj.push_back(djecica.at(i));
        i++;
    }
    std::vector<std::set<std::string>> timd(n);
    auto it=listadj.begin();

    i=0;
    int brojpotimu=djecica.size()/n;
    for(;;) {
        if(i<djecica.size()%n) brojpotimu=(djecica.size()/n)+1;
        else brojpotimu=djecica.size()/n;
        for(int k=0; k<brojpotimu; k++) {
            timd.at(i).insert(*it);
            int brojpomjeranja=BrojSlova(*it)-1;
            it=listadj.erase(it);
            if(it==listadj.end()) it=listadj.begin();
            if(listadj.size()==0) {
                break;
            }

            int j=0;
            while(j<brojpomjeranja) {
                j++;
                it++;

                if(it==listadj.end()) {
                    it=listadj.begin();

                }


            }


        }

        i++;
        if(listadj.size()==0) break;

    }



    return timd;

}
void IspisiSet(std::set<std::string> set)
{
    auto it=set.begin();
    std::cout << *it;
    it++;
    while(it!=set.end()) {
        //if(it==set.begin()) std::cout << *it;
        std::cout << ", " << *it;
        it++;
    }
}
int main ()
{
    int n;
    std::cout << "Unesite broj djece: ";
    std::cin >> n;
    std::cout << "Unesite imena djece: " << std::endl;
    std::vector<std::string> djeca;
    std::cin.ignore(1000,'\n');

    //for(std::string &s; djeca) std::getline(std::cin, s);
    for(int i=0; i<n; i++) {
        // std::cout << i+1 << "___";
        std::string pomocni;
        std::getline(std::cin, pomocni);
        djeca.push_back(pomocni);
    }
    std::cout << "Unesite broj timova: ";
    int k;
    std::cin>> k;
    try {
        auto timovi = Razvrstavanje(djeca, k);
        for(int i=0; i<k; i++) {
            std::cout << "Tim " << i+1 << ": ";
            IspisiSet(timovi.at(i));
            if(i!=k-1) std::cout << std::endl;
        }
    } catch(std::logic_error l) {
        std::cout << "Izuzetak: " << l.what();
    }
    return 0;
}
