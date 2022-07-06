//TP 2018/2019: Tutorijal 4, Zadatak 3
#include <iostream>
#include <string>
#include <vector>
bool MalaSlova (char c)
{

    if(c>='a' && c<='z') return true;
    return false;


}
void IzdvojiKrajnjeRijeci(std::vector <std::string> s, std::string &prvi, std::string &posljednji)
{
   if(s.size()!=0){
    std::vector<std::string> pomocni=s;
    for(int i=0; i<pomocni.size(); i++) {

        for(int j=0; j<pomocni.at(i).size(); j++) {

            if(MalaSlova(pomocni.at(i).at(j))) pomocni.at(i).at(j)=pomocni.at(i).at(j)-32;
        }


    }
    prvi=pomocni.at(0);
    posljednji=pomocni.at(0);
    int max=0;
    int min=0;
    for(int i=0; i<pomocni.size(); i++) {

        if(pomocni.at(i)<prvi) {
            max=i;
            prvi=pomocni.at(i);
        }
        if(pomocni.at(i)>posljednji) {
            min=i;
            posljednji=pomocni.at(i);
        }


    }

    prvi=s.at(max);
    posljednji=s.at(min);
   }




}

void ZadrziDuplikate (std::vector<std::string> &s){
    
    std::vector<std::string> pomocni;
    for(int i=0; i<s.size();i++){
        
        bool duplikat=false;
            for(int j=i+1; j<s.size();j++){
                
                if(s.at(i)==s.at(j)) {
                    duplikat=true;
                    for(int k=0; k<pomocni.size();k++){
                        if(pomocni.at(k)==s.at(j)) duplikat=false;
                    }
                    
                    break;
                }
               
                
            }
    
     if(duplikat) pomocni.push_back(s.at(i));
    
    
    }
    
    s=pomocni;
    
    
    
}
int main ()
{
    std::vector <std::string> s;
    std::cout << "Koliko zelite unijeti rijeci: ";
    int n;
    std::cin >> n;
    std::cin.clear();
    std::cin.ignore(10000,'\n');
    std::cout << "Unesite rijeci: ";
    std::string pom;
    for(int i=0; i<n;i++){
        
        std::getline(std::cin,pom,' ');
        s.push_back(pom);
    
    }
    std::string prva;
    std::string posljednja;
    IzdvojiKrajnjeRijeci(s,prva, posljednja);
    ZadrziDuplikate(s);
    std::cout << "Prva rijec po abecednom poretku je: " << prva << std::endl;
    std::cout << "Posljednja rijec po abecednom poretku je: " << posljednja << std::endl;
    std::cout << "Rijeci koje se ponavljaju su: ";
    for(int i=0; i<s.size();i++)
     std::cout << s.at(i) << " ";
    
    return 0;
}
