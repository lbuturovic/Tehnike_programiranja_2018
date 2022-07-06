#include <iostream>
#include <iomanip>
#include <cstring>
#include <stdexcept>
#include <new>
#include <ostream>
#include <istream>
template <typename TipEl>
class Matrica
{
	int br_redova, br_kolona;
	TipEl **elementi;
	char ime_matrice;
	static TipEl **AlocirajMemoriju(int br_redova, int br_kolona);
	static void DealocirajMemoriju(TipEl **elementi, int br_redova);
	void KopirajElemente(TipEl **elementi);
public:
	Matrica(int br_redova, int br_kolona, char ime = 0);
	Matrica(const Matrica &m);
	Matrica(Matrica &&m);
	TipEl& operator ()(int i, int j) {
		if(i<1 || i>br_redova) throw std::range_error("Neispravan indeks");
		if(j<1 || j>br_kolona) throw std::range_error("Neispravan indeks");
		return elementi[i-1][j-1];
	}
	TipEl operator ()(int i, int j) const {
		if(i<1 || i>br_redova) throw std::range_error("Neispravan indeks");
		if(j<1 || j>br_kolona) throw std::range_error("Neispravan indeks");
		return elementi[i-1][j-1];
	}
	TipEl*& operator[] (int red){
		//if(red<1 || red>br_redova) throw std::range_error("Neispravan indeks");
		return elementi[red];
	}
	TipEl* operator [] (int red) const {
		//if(red<1 || red>br_redova) throw std::range_error("Neispravan indeks");
		return elementi[red];
	}
	~Matrica()
	{
		DealocirajMemoriju(elementi, br_redova);
	}
	Matrica &operator =(const Matrica &m);
	Matrica &operator =(Matrica &&m);
	operator std::string () const;
	//void Unesi();
	template <typename TipEl2>
	friend std::istream & operator >>(std::istream &tok, Matrica<TipEl2> &mat);
	template <typename TipEl2>
	friend std::ostream & operator <<(std::ostream& tok, const Matrica<TipEl2> &mat);
	template <typename Tip2>
	friend Matrica<Tip2> operator +(const Matrica<Tip2> &m1,const Matrica<Tip2> &m2);
	template<typename TipElemenata>
friend Matrica<TipElemenata>  operator * (double br,Matrica <TipElemenata> &m );
	 template <typename TipElemenata>
friend Matrica<TipElemenata> operator *(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2);
template<typename TipElemenata>
friend Matrica<TipElemenata>  operator * (Matrica <TipElemenata> &m, double br);
template <typename TipEl2>
friend Matrica<TipEl2> operator-(const Matrica<TipEl2> &m1,  const Matrica<TipEl2> &m2);
template <typename TipEl2>
 friend Matrica<TipEl2>& operator+=(Matrica<TipEl2> &m1,  const Matrica<TipEl2> &m2);
 template <typename TipEl2>
 friend Matrica<TipEl2>& operator-=(Matrica<TipEl2> &m1,  const Matrica<TipEl2> &m2);
};
template<typename TipElemenata>
Matrica<TipElemenata>  operator * (Matrica <TipElemenata> &m, double br)
{
    for(int i=0; i<m.br_redova; i++){
        for(int j=0; j<m.br_kolona; j++)
            m.elementi[i][j]=m.elementi[i][j]*br;
        
    }
    return m;
}
template<typename TipElemenata>
Matrica<TipElemenata>  operator * (double br,Matrica <TipElemenata> &m )
{
    for(int i=0; i<m.br_redova; i++){
        for(int j=0; j<m.br_kolona; j++)
            m.elementi[i][j]=m.elementi[i][j]*br;
        
    }
    return m;
}
template <typename TipEl>
TipEl ** Matrica<TipEl>::AlocirajMemoriju(int br_redova, int br_kolona)
{
	TipEl **elementi = new TipEl*[br_redova] {};
	try {
		for(int i = 0; i < br_redova; i++) elementi[i] = new TipEl[br_kolona];
	} catch(...) {
		DealocirajMemoriju(elementi, br_redova);
		throw;
	}
	return elementi;
}
template <typename TipElemenata>
Matrica<TipElemenata> operator *(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.br_kolona!=m2.br_redova) throw std::domain_error ("Matrice nisu saglasne za mnozenje");
    Matrica<TipElemenata> matr (m1.br_redova,m2.br_kolona);
    for(int i=0; i<matr.br_redova; i++)
        for(int j=0; j<matr.br_kolona; j++)
            matr.elementi[i][j]=0;
    for(int i=0; i<matr.br_redova; i++)
        for(int j=0; j<matr.br_kolona; j++)
            for(int m=0; m<m1.br_kolona; m++)
                matr.elementi[i][j]+=m1.elementi[i][m]*m2.elementi[m][j];
    return matr;
}
template <typename TipEl>
void Matrica<TipEl>::DealocirajMemoriju(TipEl **elementi, int br_redova)
{
	for(int i = 0; i < br_redova; i++) delete[] elementi[i];
	delete[] elementi;
}
template <typename TipEl>
Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char ime) :
	br_redova(br_redova), br_kolona(br_kolona), ime_matrice(ime),
	elementi(AlocirajMemoriju(br_redova, br_kolona)) {}
template <typename TipEl>
void Matrica<TipEl>::KopirajElemente(TipEl **elementi)
{
	for(int i = 0; i < br_redova; i++)
		for(int j = 0; j < br_kolona; j++)
			Matrica::elementi[i][j] = elementi[i][j];
}
template <typename TipEl>
Matrica<TipEl>::Matrica(const Matrica<TipEl> &m) : br_redova(m.br_redova),
	br_kolona(m.br_kolona), ime_matrice(m.ime_matrice),
	elementi(AlocirajMemoriju(m.br_redova, m.br_kolona))
{
	KopirajElemente(m.elementi);
}
template <typename TipEl>
Matrica<TipEl>::Matrica(Matrica<TipEl> &&m) : br_redova(m.br_redova),
	br_kolona(m.br_kolona), elementi(m.elementi), ime_matrice(m.ime_matrice)
{
	m.br_redova = 0;
	m.elementi = nullptr;
}
template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(const Matrica<TipEl> &m)
{
	if(br_redova < m.br_redova || br_kolona < m.br_kolona) {
		TipEl **novi_prostor = AlocirajMemoriju(m.br_redova, m.br_kolona);
		DealocirajMemoriju(elementi, br_redova);
		elementi = novi_prostor;
	} else if(br_redova > m.br_redova)
		for(int i = m.br_redova; i < br_redova; i++) delete elementi[i];
	br_redova = m.br_redova;
	br_kolona = m.br_kolona;
	ime_matrice = m.ime_matrice;
	KopirajElemente(m.elementi);
	return *this;
}
template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator =(Matrica<TipEl> &&m)
{
	std::swap(br_redova, m.br_redova);
	std::swap(br_kolona, m.br_kolona);
	std::swap(ime_matrice, m.ime_matrice);
	std::swap(elementi, m.elementi);
	return *this;
}
template <typename TipEl>
std::ostream& operator <<(std::ostream &tok, const Matrica<TipEl> &mat)
{
	int sirina_ispisa=tok.width();
	for(int i = 0; i < mat.br_redova; i++) {
		for(int j = 0; j < mat.br_kolona; j++)
			tok<< std::setw(sirina_ispisa) << mat.elementi[i][j];
		tok << std::endl;
	}
	return tok;
}
template <typename TipEl>
std::istream &  operator >>(std::istream &tok, Matrica<TipEl> &mat){
	for(int i = 0; i < mat.br_redova; i++)
		for(int j = 0; j < mat.br_kolona; j++) {
			std::cout << mat.ime_matrice << "(" << i + 1 << "," << j + 1 << ") = ";
			tok >> mat.elementi[i][j];
		}
		return tok;
}
template <typename TipEl>
Matrica<TipEl>& operator+=(Matrica<TipEl> &m1,  const Matrica<TipEl> &m2)
{
	if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
		throw std::domain_error("Matrice nemaju jednake dimenzije!");
	Matrica<TipEl> m3=m1;
	for(int i = 0; i < m1.br_redova; i++)
		for(int j = 0; j < m1.br_kolona; j++)
			m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
	m1=m3;
	return m1;
}
template <typename TipEl>
Matrica<TipEl>& operator-=(Matrica<TipEl> &m1,  const Matrica<TipEl> &m2)
{
	if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
		throw std::domain_error("Matrice nemaju jednake dimenzije!");
	Matrica<TipEl> m3=m1;
	for(int i = 0; i < m1.br_redova; i++)
		for(int j = 0; j < m1.br_kolona; j++)
			m3.elementi[i][j] = m1.elementi[i][j] - m2.elementi[i][j];
	m1=m3;
	return m1;
}
template <typename TipEl>
Matrica<TipEl> operator+(const Matrica<TipEl> &m1,  const Matrica<TipEl> &m2)
{
	if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
		throw std::domain_error("Matrice nemaju jednake dimenzije!");
	Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
	for(int i = 0; i < m1.br_redova; i++)
		for(int j = 0; j < m1.br_kolona; j++)
			m3.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];
	return m3;
}
template <typename TipEl>
Matrica<TipEl> operator-(const Matrica<TipEl> &m1,  const Matrica<TipEl> &m2)
{
	if(m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
		throw std::domain_error("Matrice nemaju jednake dimenzije!");
	Matrica<TipEl> m3(m1.br_redova, m1.br_kolona);
	for(int i = 0; i < m1.br_redova; i++)
		for(int j = 0; j < m1.br_kolona; j++)
			m3.elementi[i][j] = m1.elementi[i][j] - m2.elementi[i][j];
	return m3;
}
template<typename TipEl>
Matrica<TipEl> :: operator std::string () const{
	std::string st;
	st.push_back('{');
	for(int i=0; i<br_redova; i++){
		st.push_back('{');
		for(int j=0; j<br_kolona; j++){
			std::string st1=std::to_string(int(elementi[i][j]));
			st=st+st1;
			if(j!=br_kolona-1) st.push_back(',');
		}
		st.push_back('}');
		if(i!=br_redova-1) st.push_back(',');
	}
	st.push_back('}');
	return st;
}
int main()
{
	int m, n;
	std::cout << "Unesi broj redova i kolona za matrice:\n";
	std::cin >> m >> n;
	try {
		Matrica<double> a(m, n, 'A'), b(m, n, 'B');
		std::cout << "Unesi matricu A:\n";
		std::cin >> a;
		std::cout << "Unesi matricu B:\n";
		std::cin >> b;
		std::cout << "Zbir ove dvije matrice je:\n";
		std::cout << std::setw(7) << a+b;
	} catch(std::bad_alloc) {
		std::cout << "Nema dovoljno memorije!\n";
	}
	return 0;
}
