//TP 2018/2019: Tutorijal 4, Zadatak 1
#include <iostream>


int Cifre (long long int n, int &min, int &max){
    max=n%10;
    min=n%10;
    if(max<0) max=-1*max;
    if(min<0) min=-1*min;
    int velicina=0;
    do {
        long long int a=n%10;
        if(a<0) a=-1*a;
        velicina++;
        if(a>max) max=a;
        if(a<min) min=a;
        n=n/10;
        
    }while(n!=0);
    
    return velicina;
}
int main ()
{
    long long int n;
    std::cout << "Unesite broj: ";
    std::cin >> n;
    int min;
    int max;
    int a=Cifre(n,min,max);
    std::cout << "Broj "<< n << " ima " << a << " cifara, najveca je " << max <<
    " a najmanja "<< min << ".";
    
    
	return 0;
}