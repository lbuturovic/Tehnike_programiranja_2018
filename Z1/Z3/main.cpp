/* TP, 2018/2019, Zadaća 1, Zadatak 3*/
#include <iostream>
#include <vector>
#include <iomanip>
typedef std::vector<std::vector<int>> Matrica;
int SirinaIspisa(Matrica mat)
{
	int max=0;
	int sir=0;
	for(int i=0; i<mat.size(); i++) {
		for(int j=0; j<mat.at(i).size(); j++) {
			sir=0;
			int pom=mat.at(i).at(j);
			do {
				pom=pom/10;
				sir++;


			} while(pom!=0);
			if(sir>=max) {
				max=sir;
				if(mat.at(i).at(j)<0)
					max=max+1;
			}

		}
	}
	return max+1;
}
Matrica SpojiHorizontalno(Matrica m1, Matrica m2)
{
	//matrice sa istim brojem redova
	if(m1.size()==0) return m2;
	for(int i=0; i<m1.size(); i++) {
		for(int j=0; j<m2.at(0).size(); j++) {
			m1.at(i).push_back(m2.at(i).at(j));
		}
	}
	return m1;
}
Matrica SpojiVertikalno(Matrica m1, Matrica m2)
{
	if(m1.size()==0) return m2;
	for(int i=0; i<m2.size(); i++)
		m1.push_back(m2.at(i));
	return m1;
}
Matrica KroneckerovProizvod(Matrica m1, Matrica m2)
{
	Matrica m3;
	int redovi1=m1.size();
	int redovi2=m2.size();
	if(redovi1==0 || redovi2==0) return m3;
	int kolone1=m1.at(0).size();
	int kolone2=m2.at(0).size();
	bool nekorektnam1=false;
	bool nekorektnam2=false;
	for(int i=0; i<redovi1; i++)
		if(m1.at(i).size()!=m1.at(0).size()) {
			nekorektnam1=true;
			break;
		}
	for(int i=0; i<redovi2; i++)
		if(m2.at(i).size()!=m2.at(0).size()) {
			nekorektnam2=true;
			break;
		}
	if(nekorektnam2 && nekorektnam1) throw std::domain_error ("Parametri nemaju formu matrice");
	if(nekorektnam1) throw std::domain_error("Prvi parametar nema formu matrice");
	if(nekorektnam2) throw std::domain_error("Drugi parametar nema formu matrice");

	Matrica pom2;/*(redovi2, std::vector<int>(kolone1*kolone2))*/
	for(int i=0; i<redovi1; i++) {

		for(int j=0; j<kolone1; j++) {
			Matrica pom(redovi2, std::vector<int>(kolone2));
			for(int k=0; k<redovi2; k++)
				for(int l=0; l<kolone2; l++)
					pom.at(k).at(l)=m1.at(i).at(j)*m2.at(k).at(l);
			pom2=SpojiHorizontalno(pom2, pom);

		}
		m3=SpojiVertikalno(m3,pom2);
		pom2=Matrica(0);




	}




	return m3;

}
int main ()
{
	std::cout << "Unesite dimenzije prve matrice: "<< std::endl;
	int red1, kol1;
	std::cin >> red1 >> kol1;
	Matrica m1 (red1,std::vector<int> (kol1));
	std::cout << "Unesite elemente prve matrice: "<< std::endl;
	for(int i=0; i<red1; i++)
		for(int j=0; j<kol1; j++)
			std::cin >> m1.at(i).at(j);

	std::cout <<"Unesite dimenzije druge matrice: " << std::endl;
	int red2, kol2;
	std::cin >> red2 >> kol2;
	Matrica m2 (red2, std::vector<int> (kol2));
	std::cout <<"Unesite elemente druge matrice: " << std::endl;
	for(int i=0; i<red2; i++)
		for(int j=0; j<kol2; j++)
			std::cin >> m2.at(i).at(j);
	try {

		Matrica m3=KroneckerovProizvod(m1, m2);
		std::cout <<"Njihov Kroneckerov proizvod glasi: ";
		for(int i=0; i<m3.size(); i++) {
			std::cout << std::endl;
			for(int j=0; j<m3.at(0).size(); j++)
				std::cout << std::setw(SirinaIspisa(m3))<<m3.at(i).at(j);
		}

		std::cout << std::endl;

	} catch (std::domain_error izuzetak) {
		std::cout << izuzetak.what();
	}
	return 0;
}
