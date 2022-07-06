//TP 2016/2017: Tutorijal 1, Zadatak 4
#include <iostream>
#include <cmath>
int main ()
{
    double n2;
    for(;;) {
        std::cout << "Unesite prirodan broj ili 0 za kraj: ";
        std::cin >> n2;
        int n=(int)n2;
        if(!(std::cin) || n2<0 || n!=n2)
        {
            std::cout <<"Niste unijeli prirodan broj!" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            
        }
        else
        
        {
            
            if(n>0)
            {
                int j;
                int suma=0;
                for(j=1;j<n;j++){
                    
                    if(n%j==0) suma+=j;
                    
                }
                if(suma==n)
                std::cout <<"Broj " << n << " je savrsen!" << std::endl;
                if(suma<n)
                std::cout <<"Broj " << n << " je manjkav!" << std::endl;
                if(suma>n)
                std::cout << "Broj " << n << " je obilan!" << std::endl;
            
            }
            
            if(n==0) {
                
                std::cout<<"Dovidjenja!";
                break;
            }
        }
    }

    
	return 0;
}