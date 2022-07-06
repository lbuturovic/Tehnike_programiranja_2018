/*  *** Zadaci za samostalan rad (ZSR 1, Zadatak 14) *** */
#include <iostream>

int main ()
{
    
    int n,n1;
    std::cout << "Unesite broj: ";
    std::cin >> n;
    n1=n;
    int n2=0;
    int cifra;
    do {
        
        cifra=n%10;
        n2=n2*10+cifra;
        n=n/10;
        
        
        
    }while(n!=0);
    
    if(n1==n2)
    std::cout << "Broj je palindroman.";
    else std::cout << "Broj nije palindroman.";
	return 0;
}