//TP 2018/2019: Zadaća 3, Zadatak 6
#include <iostream>
#include <set>
#include <vector>
#include <memory>
struct Dijete {
    std::string ime;
    std::shared_ptr <Dijete> sljedeci;
};
bool JeLiUImenu(char s)
{
    if((s>='a' && s<='z') ||(s>='A' && s<='Z') || (s>='0' && s<='9')) return true;
    return false;
}
int BrojSlova(std::string s)
{
    int i=0;
    int duzina=0;
    while(i!=s.size()) {
        if(JeLiUImenu(s.at(i))) duzina++;
        i++;
    }
    return duzina;
}
std::vector<std::set<std::string>> Razvrstavanje(std::vector<std::string> djecica, int n)
{
    if(n<=0 || n>djecica.size()) throw std::logic_error ("Razvrstavanje nemoguce");
    int i=0;
    std::shared_ptr<Dijete> prvo=nullptr;
    std::shared_ptr<Dijete> prethodno;
    for(;;) {
        if(i==djecica.size()) break;
        std::shared_ptr<Dijete> novo=nullptr;
        novo=std::shared_ptr<Dijete>(new Dijete{djecica.at(i),prvo});
        if(!prvo) prvo=novo;
        else prethodno->sljedeci=novo;
        prethodno=novo;
        i++;
    }
    std::vector<std::set<std::string>> timd(n);
    auto it=prvo;
    int brojdjece=djecica.size();
    int brojpotimu=djecica.size()/n;
    i=0;
    for(;;){
       /* if(brojdjece==1) {it->sljedeci=nullptr;
                            prethodno->sljedeci=nullptr;}*/
        if(i<djecica.size()%n) brojpotimu=(djecica.size()/n)+1;
        else brojpotimu=djecica.size()/n;
        for(int k=0; k<brojpotimu; k++){
            timd.at(i).insert(it->ime);
            int brojpomjeranja=BrojSlova(it->ime)-1;
            prethodno->sljedeci=it->sljedeci;
            brojdjece--;
            if(brojdjece==0) break;
            it=prethodno->sljedeci;
            int j=0;
            while(j<brojpomjeranja){
                j++;
                it=it->sljedeci;
                prethodno=prethodno->sljedeci;
            }
        }
        i++;
        if(brojdjece==0) break;
    }
    it->sljedeci=nullptr;
    return timd;
}
void IspisiSet(std::set<std::string> set){
    auto it=set.begin();
    std::cout << *it;
    it++;
    while(it!=set.end()){
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
    for(int i=0; i<n; i++){
        std::string pomocni;
        std::getline(std::cin, pomocni);
        djeca.push_back(pomocni);
    }
    std::cout << "Unesite broj timova: ";
    int k;
    std::cin >> k;
    try {
        auto timovi=Razvrstavanje(djeca, k);
        for(int i=0; i<k; i++){
            std::cout <<"Tim " << i+1 << ": ";
            IspisiSet(timovi.at(i));
            if(i!=k-1) std::cout << std::endl;
        }
    }
    catch(std::logic_error l) {
        std::cout << "Izuzetak: " << l.what();
    }
    return 0;
}
