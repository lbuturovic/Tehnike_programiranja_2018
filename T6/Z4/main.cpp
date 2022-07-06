/* 
    TP 2018/2019: Tutorijal 6, Zadatak 4
	
	Autotestovi by Kerim Hodzic. Prijave gresaka, pitanja 
	i sugestije saljite na mail: khodzic2@etf.unsa.ba
	
	Napomene: testovi su konacni tek pred tutorijal
			  za krsenje zabrana dobiva se 0 bodova za zadatak
	
*/
#include <iostream>
int** KreirajTrougao (int n){
	if(n<=0) throw std::domain_error ("Broj redova mora biti pozitivan");
	int** p;
	try{
		p=new int*[n];
		
		p[0]=nullptr;
		int suma=0;
		for(int i=1; i<=n;i++)
		suma=suma+i*2-1;
		p[0]= new int [suma];
		for(int i=1; i<n; i++) p[i]=p[i-1]+(i)*2-1;
		
		p[0][0]=1;
		int pom;
		for(int i=1; i<n; i++){
			
			p[i][0]=i+1;
			pom=i+1;
			for(int j=1;j<(i+1)*2-1;j++){
				if(j<i+1){
					pom--;
					p[i][j]=pom;
				}
				else {
					pom++;
					p[i][j]=pom;
				}
			}
		}
	}
	catch(...){
		delete [] p[0];
		delete [] p;
		throw;
	}
	return p;
}
int main ()
{
	int n;
	std::cout << "Koliko zelite redova: ";
	std::cin >> n;
	try {
		
		int** p=KreirajTrougao(n);
		for(int i=0; i<n; i++){
			for(int j=0; j<(i+1)*2-1; j++)
			std::cout << p[i][j] << " ";
			std::cout << std::endl;
		}
		delete [] p[0];
		delete [] p;
	}
	catch(std::domain_error d) {
		std::cout << "Izuzetak: " << d.what();
	}
	catch(...) {
		std::cout << "Izuzetak: Nedovoljno memorije!";
	}
	return 0;
}