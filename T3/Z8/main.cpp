//TP 2017/2018: Tutorijal 3, Zadatak 8
#include <iostream>
#include <string>

std::string IzdvojiRijec (std::string recenica, int n)
{
    if(n<1) throw std::range_error ("Pogresan redni broj rijeci!");
    bool razmak=true;
    bool nprviput=true;
    std::string rijec;
    int brojrijeci=0;
    int i=0;
    int duzinarijeci=0;
    while(i<recenica.length())
    {
        if(recenica.at(i)==' ') razmak=true;
        else if(razmak==true) { //else - ako je slovo, a razmak je true sto znaci da je prethodno bio razmak
            
            razmak=false;
            brojrijeci++;
        }
        
        if(brojrijeci==n && nprviput) {
            nprviput=false;
            int j=i;
            while(recenica[j]!=' ' && recenica[j]!='\0') { // pitanje: postoji li nacin da se izvrsi pomocu at.(j) jer u testovima baca nepredvidjene izuzetke
                
              duzinarijeci++;
              j++;
            }
            
                
           rijec=recenica.substr(i,duzinarijeci);
                
            
            
        }
        
        
        i++;
    }
    
    
    if(duzinarijeci==0) throw std::range_error("Pogresan redni broj rijeci!");
    return rijec;
}
int main ()
{
    int n;
    std::cout << "Unesite redni broj rijeci: ";
    std::cin >> n;
    std::cout << "Unesite recenicu: ";
    std::string rec;
    std::cin.ignore(10000,'\n');
    std::getline(std::cin, rec);
    try{
    std::cout << "Rijec na poziciji " << n << " je "<< IzdvojiRijec(rec,n);
    }
    catch(std::range_error izuzetak){
        
        std::cout << "IZUZETAK: " << izuzetak.what();
    }
    
    
    return 0;
}
