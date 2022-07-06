//TP 2017/2018: ZSR 1, Zadatak 31
#include <iostream>

bool DjeljivSumomCifara (int a)
{

    int b=a;
    int suma=0;

    do {

        suma+=a%10;
        a=a/10;
    } while(a!=0);

    if(b%suma==0) return true;
    return false;


}
int main ()
{
    int a,b,brojac=0;
    std::cout << "Unesite dva broja: ";
    std::cin >> a >> b;
    for(int i=a;i<=b;i++){
        
        if(DjeljivSumomCifara(i)) brojac++;
        
    }
    
    std::cout << "Broj brojeva djeljivih sa sumom svojih cifara je " << brojac;
    

    return 0;
}
