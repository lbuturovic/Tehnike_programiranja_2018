/* TP, 2018/2019, Zadaća 1, Zadatak 1

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.
*/
#include <iostream>
#include <vector>
bool JeLiBrPalindroman (int br)
{
	if(br<0) br=-1*br;
	int pom=br;
	int br2=0;
	int cifra;
	do {

		cifra=pom%10;
		br2=10*br2+cifra;
		pom=pom/10;



	} while(pom!=0);

	if(br2==br) return true;
	return false;
}

int AbsObrnutBroj (int br)
{

	if(br<0) br=-1*br;
	int pom=br;
	int br2=0;
	int cifra;
	do {

		cifra=pom%10;
		br2=10*br2+cifra;
		pom=pom/10;



	} while(pom!=0);

	return br2;
}

std::vector<int> PalindromskaOtpornost (std::vector <int> vbrojeva)
{

	std::vector<int> otpornosti(vbrojeva.size());

	for(int i=0; i<vbrojeva.size(); i++) {
		int suma=vbrojeva.at(i);
		int otpornost=0;
		if(suma<0) suma=-1*suma;
		for(;;) {

			if(JeLiBrPalindroman(suma)) break;
			suma=suma+AbsObrnutBroj(suma);
			otpornost++;


		}
		otpornosti.at(i)=otpornost;


	}

	return otpornosti;
}

int main ()
{
	int n;
	std::cout << "Koliko zelite unijeti elemenata: ";
	std::cin >> n;
	std::vector<int> niz(n);
	std::cout << "Unesite elemente: ";
	for(int i=0; i<n; i++) {

		std::cin >> niz.at(i);
	}
	std::vector<int> otpornosti(n);
	otpornosti=PalindromskaOtpornost(niz);
	for(int i=0; i<n; i++) {

		std::cout << "Palindromska otpornost broja " << niz.at(i) << " iznosi " << otpornosti.at(i) << std::endl;
	}

	return 0;
}
