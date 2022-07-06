//TP 2018/2019: Tutorijal 4, Zadatak 2
#include <iostream>
#include <string>
void IzvrniString(std::string &s){
    int duzina;
    if(s.length()%2!=0) duzina=(s.length()/2)+1;
    else duzina=s.length()/2;
    for(int i=0; i<duzina;i++){
        char pom=s[i];
        s[i]=s[s.length()-i-1];
        s[s.length()-i-1]=pom;
        
    }
    
    
}
int main ()
{
    std::string s;
    std::cout << "Unesi string: ";
    std::getline(std::cin,s);
    IzvrniString(s);
    std::cout << "Izvrnuti string je: "<< s;
	return 0;
}