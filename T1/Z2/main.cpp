//TP 2016/2017: Tutorijal 1, Zadatak 1
#include <iostream>
#include <cmath>
int main ()
{
    double a,b,c;
    std::cout << "Unesite tri broja: ";
    std::cin >> a >> b >> c;
    if(a<=0 || b<=0 || c<=0 || (a+b)<=c || (a+c)<=b || (b+c)<=a) {
        
        std::cout << "Ne postoji trougao cije su duzine stranica " << a << ", " << b
        << " i " << c << "!";
        return 0;
    }
    
    double s=(a+b+c)/2;
    double p=std::sqrt(s*(s-a)*(s-b)*(s-c));
    constexpr double pi=4*atan(1.);
    double ugao1, ugao2, ugao3;
    ugao1=std::acos((a*a+b*b-c*c)/(2*a*b));
    ugao2=std::acos((a*a+c*c-b*b)/(2*a*c));
    ugao3=std::acos((c*c+b*b-a*a)/(2*c*b));
    if(ugao2<ugao1) ugao1=ugao2;
    if(ugao3<ugao1) ugao1=ugao3;
    int st, m, se;
    ugao1= ugao1*180/pi;
    st=int(ugao1);
    m=int((ugao1-st)*3600)/60;
    se=int((ugao1-st)*3600)%60;
    
    std::cout << "Obim trougla sa duzinama stranica " << a <<", " << b << " i " << c
    << " iznosi " << a+b+c << "." << std::endl;
    std::cout <<"Njegova povrsina iznosi " << p << "."<< std::endl
    << "Njegov najmanji ugao ima " << st << " stepeni, " << m << " minuta i " << se
    << " sekundi.";
    
	return 0;
}