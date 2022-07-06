/*
    TP 16/17 (Tutorijal 7, Zadatak 10)
	Autotestove pisao Elmir Hodzic. Sva pitanja,
	prijave gresaka i sugestije slati na mail
	ehodzic3@etf.unsa.ba

	Vrsit ce se provjera na prepisivanje tutorijala.
*/
#include <iostream>
#include <functional>
/*std::function<int(int)> IteriranaFunkcija(std::function<int(int)> f, int n){
	std::cout << n << std::endl;
	/*int m=n;
    if(n<=1) return [f](int k) {return f(k);};

	return IteriranaFunkcija([f](int k) { return f(f(k));},(int)(n/2+0.5));
	} */

std::function<int(int)> IteriranaFunkcija (std::function<int(int)> f, int n)
{
	std::function<int(int)> pomocna=f;
	for(int i=1; i<n; i++) {
		pomocna=[f,pomocna] (int x) {
			return pomocna(f(x));
		};



	}

	return pomocna;

}

int main ()
{
	//std::cout << IteriranaFunkcija([](int x) { return x * x; }, 3)(3) << std::endl;
	std::function<double(double)> g{IteriranaFunkcija([](int x)
	{
		return x + 3;
	}, 6)};
	std::cout << g(7) << std::endl;
	return 0;
}
