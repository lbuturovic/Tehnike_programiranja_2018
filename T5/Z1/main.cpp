/* 
    TP 2018/2019: Tutorijal 5, Zadatak 1
*/
#include <iostream>
bool JeLiRazmak(char s){
	return(s=' ');
}
int main ()
{
	char recenica[1001];
	std::cout <<"Unesite recenicu: ";
	std::cin.getline(recenica, 1000);
	char*p=recenica;
	int br=0;
	bool razmak=true;
	std::cout << "Recenica bez prve rijeci glasi: ";
	while(*p!='\0'){
		if(*p==' ') razmak=true;
		else if(razmak==true){
			razmak=false;
			br++;
		}
		if(br>=2)
		std::cout<< *p;
		
		p++;
	}
	std::cout << std::endl;
	return 0;
}