//TP 2018/2019: Tutorijal 8, Zadatak 1
#include <iostream>
#include <iomanip>
struct Vrijeme {
    int sati, minute, sekunde;
    
};
void TestirajVrijeme(Vrijeme v1){
    if(v1.sati <0 || v1.sati>23 || v1.minute <0 || v1.minute>59
    || v1.sekunde<0 || v1.sekunde>59)
    throw std::domain_error ("Neispravno vrijeme");
    
}
void IspisiVrijeme(Vrijeme v){
    TestirajVrijeme(v);
    std::cout << std::setfill('0') << std::setw(2) << v.sati << ":" <<  std::setw(2) << v.minute << ":" << std::setw(2) << v.sekunde;
}
Vrijeme SaberiVrijeme (Vrijeme v1, Vrijeme v2) {
    TestirajVrijeme(v1);
    TestirajVrijeme(v2);
    int pomocna;
    Vrijeme v3;
    pomocna=v1.sekunde+v2.sekunde;
    v3.sekunde=pomocna%60;
    pomocna=pomocna/60;
    pomocna=pomocna+v1.minute+v2.minute;
    v3.minute=pomocna%60;
    pomocna=pomocna/60+v1.sati+v2.sati;
    v3.sati=pomocna%24;
    return v3;
}
int main ()
{
    Vrijeme v1;
    Vrijeme v2;
    try{
        std::cout << "Unesite prvo vrijeme (h m s): ";
        std::cin >> v1.sati >> v1.minute >> v1.sekunde;
        TestirajVrijeme(v1);
        std::cout << "Unesite drugo vrijeme (h m s): ";
        std::cin >> v2.sati >> v2.minute >> v2.sekunde;
        TestirajVrijeme(v2);
        std::cout << "Prvo vrijeme: ";
        IspisiVrijeme(v1);
        std::cout << std::endl;
        std::cout <<"Drugo vrijeme: ";
        IspisiVrijeme(v2);
        std::cout << std::endl;
        Vrijeme v3=SaberiVrijeme(v1, v2);
        std::cout <<"Zbir vremena: ";
        IspisiVrijeme(v3);
    }
    catch(std::domain_error d){
        std::cout << d.what();
    }
	return 0;
}