/* TP, 2018/2019
*/
#include <iostream>
#include <cmath>
bool Prost(int n)
{
    if(n==1) return false;
    for(int i=2; i<n; i++)
        if(n%i==0) return false;
    return true;
}
bool OslobodjenOdKv(int n)
{
    if(n==1) return true;
    for(int i=2; i<=sqrt(n); i++) {
        if(Prost(i) && n%i==0) {
            n=n/i;
            if(n%i==0) return false;
        }
    }
    return true;
}
void RastavaBroja(int n, int &p, int &q)
{
    if(n<=0) throw std::domain_error ("Broj koji se rastavlja mora biti prirodan");
    bool pronasao=false;
    int i=1;
    do {

        int p1=n/(i*i);
        if (OslobodjenOdKv(p1) && p1*i*i==n) {
            p=p1;
            q=i;
            pronasao=true;
        }
        i++;


    } while(!pronasao);

}

int main ()
{
    int n;
    std::cout << "Unesite prirodan broj ";
    try {
        std::cin >> n;
        int a,b;
        std::cout << std::endl;
        RastavaBroja(n,a,b);
        std::cout << a << " " << b;
    } catch(std::domain_error d) {
        std::cout << std::endl << "Izuzetak: " << d.what()<<"!";
    }
    return 0;
}
