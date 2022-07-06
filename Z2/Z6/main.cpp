/* TP, 2018/2019
*/
#include <iostream>
#include <string>
#include <algorithm>
bool KriterijSortiranja(std::string prvi, std::string drugi)
{

    for(char &c1: prvi) c1=std::toupper(c1);
    for(char &c2: drugi) c2=std::toupper(c2);
    if(prvi.length()==drugi.length()) return prvi<drugi;
    return prvi.length()<drugi.length();
}
bool PretraziBinarno(std::string* s, int n, std::string trazena){
    
    std::string* iza_kraja=s+n;
    bool a=std::binary_search(s, iza_kraja, trazena, KriterijSortiranja);
    
    return a;
    
}
std::string* SortirajPoDuzini (std::string* s, int n)
{

    std::string* iza_kraja=s+n;
    std::sort(s, iza_kraja, KriterijSortiranja);
    return s;

}
int main ()
{
    int brrijeci;
    std::cout << "Unesite broj rijeci: ";
    std::cin >> brrijeci;
    try {
    std::string* rijec = new std::string[brrijeci];
    std::cout << "Unesite rijeci: ";
    for(int i=0; i<brrijeci; i++)
        std::cin >> rijec[i];
    rijec=SortirajPoDuzini(rijec,brrijeci);
    std::cout << "Sortirane rijeci: ";
    for(int i=0; i<brrijeci; i++)
        std::cout<< rijec[i] << " ";
    std::cout << std::endl;
    std::cout << "Unesite rijec za pretragu: ";
    std::string pronadji;
    std::cin >> pronadji;
    std:: cout << "Rijec '"<< pronadji << "' se ";
    if(!(PretraziBinarno(rijec, brrijeci, pronadji))) std::cout << "ne ";
    std::cout << "nalazi u nizu.";
    delete [] rijec;}
    catch(...){
        std::cout << "Nedovoljno memorije!";
    }
    return 0;
}
