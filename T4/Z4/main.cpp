//TP 2018/2019: Tutorijal 4, Zadatak 4
#include <iostream>
#include <string>
template <typename NekiTip>
    void UnosBroja (std::string poruka1, std::string poruka2, NekiTip &n){
        for(;;){
            
            std::cout << poruka1;
            std::cin >> n;
            std::cout << std::endl;
            if(!std::cin || std::cin.peek()!='\n') {
                
                std::cout << poruka2<< std::endl;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                
            }
            else break;
            
        }
        
    }
int main ()
{
    double x;
    UnosBroja("Unesite bazu: ", "Neispravan unos, pokusajte ponovo...", x);
    std::cout << std::endl;
    int n;
    UnosBroja("Unesite cjelobrojni eksponent: ","Neispravan unos, pokusajte ponovo...",n);
    double rez=x;
    int m=n;
     if(n<0) m=-1*n;
     if(n==0) rez=x;
    else {
        rez=1;
        for(int i=1; i<=m; i++){
             rez=rez*x;
        }
    }
    if(n<0) rez=1./rez;
    std::cout << std::endl << x  << " na " << n << " iznosi " << rez;
    
	return 0;
}