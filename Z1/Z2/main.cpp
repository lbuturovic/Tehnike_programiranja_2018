/* TP, 2018/2019, Zadaća 1, Zadatak 2

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.
*/
#include <iostream>
#include <vector>
#include <complex>
typedef std::vector <std::vector<int>> Matrica;
std::complex<double> VrhMatrice (Matrica mat, int p, int q)
{
	std::complex<double> indeks(p,q);

	for(int i=0; i<mat.size(); i++) {

		if(mat.at(i).size()!=mat.at(0).size()) throw std::domain_error ("Nekorektna matrica");

	}

	if (mat.size()==0 || mat.at(0).size()==0) throw std::domain_error ("Nekorektna matrica");
	else if(p<0 || q<0 || p>=mat.size() || q>=mat.at(0).size()) throw std::range_error ("Nekorektna pocetna pozicija");

	bool pronasaoveci=false;
	bool pronasaovrh=false;
	bool red=false;
	bool kolona=false;
	int n;
	int poz;
	if(mat.size()==1) {
		red=true;
		n=mat.at(0).size();
		poz=q;
	}
	if(mat.at(0).size()==1) {
		kolona=true;
		n=mat.size();
		poz=p;
	}
	if(kolona && red) return std::complex<double> (p,q);
	if(kolona || red) {

		for(int m=0; m<n; m++) {
			if(pronasaovrh) return indeks;
			if(m==poz) {

				for(;;) {
					int i;
					int j;
					m=poz;
					pronasaoveci=false;

					if(m==0) {
						m=m+1;
						if(red) {
							j=m;
							i=0;
							p=0;
							q=poz;
						} else if(kolona) {
							i=m;
							j=0;
							q=0;
							p=poz;
						}
						if(mat.at(i).at(j)>mat.at(p).at(q)) {
							pronasaoveci=true;
							poz=m;
						}
					} else if(m==n-1) {
						m=m-1;
						if(red) {
							j=m;
							i=0;
							p=0;
							q=poz;
						} else if(kolona) {
							i=m;
							j=0;
							q=0;
							p=poz;
						}
						if(mat.at(i).at(j)>mat.at(p).at(q)) {
							pronasaoveci=true;
							poz=m;
						}
					} else {
						for(int k=0; k<2; k++) {
							if(k==0) m=m+1;
							if(k==1) m=m-2;
							if(red) {
								j=m;
								i=0;
								p=0;
								q=poz;
							} else if(kolona) {
								i=m;
								j=0;
								q=0;
								p=poz;
							}
							if(mat.at(i).at(j)>mat.at(p).at(q)) {
								pronasaoveci=true;
								poz=m;
							}
						}
					}
					indeks= std::complex<double> (p,q);
					if(!pronasaoveci) {
						pronasaovrh=true;
						break;
					}


				}
			}

		}



	}
	for(int i=0; i<mat.size(); i++) {

		if(pronasaovrh) break;
		for(int j=0; j<mat.at(0).size(); j++) {

			if(pronasaovrh) break;
			if(i==p && j==q) {

				for(;;) {
					i=p;
					j=q;
					pronasaoveci=false;
					indeks= std::complex<double>(p,q);
					if(i!=0 && j!=0 && i!=mat.size()-1 && j!=mat.at(0).size()-1) {
						for(int k=0; k<8; k++) {
							if(k==0)i=i-1;
							if(k==1)j=j+1;
							if(k==2)i=i+1;
							if(k==3)i=i+1;
							if(k==4)j=j-1;
							if(k==5)j=j-1;
							if(k==6)i=i-1;
							if(k==7)i=i-1;
							if(mat.at(i).at(j)>mat.at(p).at(q)) {
								pronasaoveci=true;
								p=i;
								q=j;
							}
						}



					} else if(i==0 && j==0) { //gornji lijevi cosak

						for(int k=0; k<3; k++) {
							if(k==0) j=j+1;
							if(k==1) i=i+1;
							if(k==2) j=j-1;
							if(mat.at(i).at(j)>mat.at(p).at(q)) {
								pronasaoveci=true;
								p=i;
								q=j;
							}
						}

					}

					else if(i==0 && j==mat.at(0).size()-1) { //gornji desni cosak
						for(int k=0; k<3; k++) {
							if(k==0) i=i+1;
							if(k==1) j=j-1;
							if(k==2) i=i-1;
							if(mat.at(i).at(j)>mat.at(p).at(q)) {
								pronasaoveci=true;
								p=i;
								q=j;
							}
						}


					}

					else if(i==mat.size()-1 && j==0) { // donji lijevi cosak
						for(int k=0; k<3; k++) {
							if(k==0) i=i-1;
							if(k==1) j=j+1;
							if(k==2) i=i+1;
							if(mat.at(i).at(j)>mat.at(p).at(q)) {
								pronasaoveci=true;
								p=i;
								q=j;
							}
						}

					}

					else if(i==mat.size()-1 && j==mat.at(0).size()-1) {

						for(int k=0; k<3; k++) {
							if(k==0) i=i-1;
							if(k==1) {
								i=i+1;
								j=j-1;
							}
							if(k==2) i=i-1;
							if(mat.at(i).at(j)>mat.at(p).at(q)) {
								pronasaoveci=true;
								p=i;
								q=j;

							}

						}
					}

					else if(i==0) {

						for(int k=0; k<5; k++) {
							if(k==0) j=j+1;
							if(k==1) i=i+1;
							if(k==2) j=j-1;
							if(k==3) j=j-1;
							if(k==4) i=i-1;
							if(mat.at(i).at(j)>mat.at(p).at(q)) {
								pronasaoveci=true;
								p=i;
								q=j;
							}

						}
					}

					else if(j==0) {
						for(int k=0; k<5; k++) {
							if(k==0) i=i-1;
							if(k==1) j=j+1;
							if(k==2) i=i+1;
							if(k==3) i=i+1;
							if(k==4) j=j-1;
							if(mat.at(i).at(j)>mat.at(p).at(q)) {
								pronasaoveci=true;
								p=i;
								q=j;
							}


						}

					}

					else if(i==mat.size()-1) {
						for(int k=0; k<5; k++) {
							if(k==0) i=i-1;
							if(k==1) j=j+1;
							if(k==2) i=i+1;
							if(k==3) j=j-2;
							if(k==4) i=i-1;
							if(mat.at(i).at(j)>mat.at(p).at(q)) {
								pronasaoveci=true;
								p=i;
								q=j;

							}

						}

					}

					else if(j==mat.at(0).size()-1) {
						for(int k=0; k<5; k++) {
							if(k==0) i=i-1;
							if(k==1) i=i+2;
							if(k==2) j=j-1;
							if(k==3) i=i-1;
							if(k==4) i=i-1;
							if(mat.at(i).at(j)>mat.at(p).at(q)) {
								pronasaoveci=true;
								p=i;
								q=j;
							}
						}

					}

					indeks = std::complex<double> (p,q);
					if(!pronasaoveci) {

						pronasaovrh=true;
						break;
					}

				}

			}


		}



	}


	return indeks;

}

int main ()
{
	int n1, n2;
	std::cout << "Unesite broj redova i kolona matrice: " << std::endl;
	std::cin >> n1 >> n2;
	Matrica m (n1, std::vector<int> (n2));
	std::cout << "Unesite elemente matrice: " << std::endl;
	for(int i=0; i<n1; i++)
		for(int j=0; j<n2; j++) {

			std::cin >> m.at(i).at(j);
		}
	std::cout << "Unesite poziciju odakle zapocinje pretraga: "<< std::endl;
	int p,q;
	std:: cin >> p >> q;

	try {
		std::complex<double> rez=VrhMatrice(m,p,q);
		double prvi= rez.real();
		double drugi= rez.imag();
		prvi=(int)prvi;
		drugi=(int)drugi;
		std::cout << "Nadjen je vrh matrice na poziciji " << prvi << " " << drugi;
		std::cout << std::endl << "Njegova vrijednost je " << m.at(prvi).at(drugi);
	} catch(std::domain_error izuz) {
		std::cout << "Greska: " << izuz.what() << "!";

	} catch(std::range_error izuz) {
		std::cout << "Greska: " << izuz.what();
	}

	return 0;
}
