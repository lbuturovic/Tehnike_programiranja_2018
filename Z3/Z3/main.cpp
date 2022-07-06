//TP 2018/2019: Zadaća 3, Zadatak 3
#include <iostream>
#include <new>
#include <iomanip>
#include <stdexcept>
#include <vector>
template <typename TipElemenata>
struct Matrica {
    int bredova, bkolona;
    TipElemenata **elementi = nullptr;
};
template <typename TipElemenata>
void UnistiMatricu (Matrica <TipElemenata> &mat)
{
    if(!mat.elementi) return;
    for(int i=0; i<mat.bredova; i++)
        delete [] mat.elementi[i];
    delete [] mat.elementi;
    mat.elementi=nullptr;
}
template <typename TipElemenata>
Matrica <TipElemenata> StvoriMatricu (int bredova, int bkolona)
{
    Matrica<TipElemenata> m1;
    m1.bredova=bredova;
    m1.bkolona=bkolona;
    m1.elementi= new TipElemenata*[bredova] { };
    try {
        for(int i=0; i<bredova; i++) {
            m1.elementi[i]=new TipElemenata [bkolona];
        }
    } catch(...) {
        UnistiMatricu(m1);
        throw;
    }
    return m1;
}
template <typename TipElemenata>
void UnesiMatricu (char ime_matrice, Matrica<TipElemenata> &mat)
{
    for(int i=0; i<mat.bredova; i++) {
        for(int j=0; j<mat.bkolona; j++) {
            std::cout << ime_matrice << "(" << i+1 << "," << j+1 << ") = ";
            std::cin>>mat.elementi[i][j];
        }
    }
}
template <typename TipElemenata>
Matrica <TipElemenata> ZbirMatrica(const Matrica <TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.bredova!=m2.bredova || m1.bkolona!=m2.bkolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    auto m3= StvoriMatricu<TipElemenata> (m1.bredova, m1.bkolona);
    for(int i=0; i<m1.bredova; i++)
        for(int j=0; j<m1.bkolona; j++)
            m3.elementi[i][j] = m1.elementi[i][j]+m2.elementi[i][j];
    return m3;
}
template <typename TipElemenata>
void IspisiMatricu ( Matrica <TipElemenata> &m1, int sirina_ispisa=10, int preciznost=6, bool treba_brisati=false)
{
    for(int i=0; i< m1.bredova; i++) {
        for(int j=0; j<m1.bkolona; j++)
            std::cout << std::setw(sirina_ispisa) << std::setprecision(preciznost) << m1.elementi[i][j];
        std::cout << std::endl;
    }
    if(treba_brisati)
        UnistiMatricu(m1);

}
template <typename TipElemenata>
Matrica<TipElemenata> ProduktMatrica(const Matrica<TipElemenata> &m1, const Matrica<TipElemenata> &m2)
{
    if(m1.bkolona!=m2.bredova) throw std::domain_error ("Matrice nisu saglasne za mnozenje");
    auto matr=StvoriMatricu<TipElemenata>(m1.bredova,m2.bkolona);
    for(int i=0; i<matr.bredova; i++)
        for(int j=0; j<matr.bkolona; j++)
            matr.elementi[i][j]=0;
    for(int i=0; i<matr.bredova; i++)
        for(int j=0; j<matr.bkolona; j++)
            for(int m=0; m<m1.bkolona; m++)
                matr.elementi[i][j]+=m1.elementi[i][m]*m2.elementi[m][j];
    return matr;
}
template<typename TipElemenata>
void Pomnozibrojem (Matrica <TipElemenata> &m, double br)
{
    for(int i=0; i<m.bredova; i++){
        for(int j=0; j<m.bkolona; j++)
            m.elementi[i][j]=m.elementi[i][j]*br;
        
    }
    //return m;
}
template<typename TipElemenata>
Matrica<TipElemenata> MatricniPolinom(const Matrica <TipElemenata> &m, std::vector<double> k)
{
    if(m.bkolona!=m.bredova) throw std::domain_error ("Matrica mora biti kvadratna");
    if(k.size()==0) {
        auto matrica=StvoriMatricu<TipElemenata>(m.bredova,m.bkolona);
        for(int i=0; i<m.bredova; i++)
            for(int j=0; j<m.bkolona; j++) {
                matrica.elementi[i][j]=0;
            }
        return matrica;
    }
    auto pomocna=StvoriMatricu<TipElemenata>(m.bredova,m.bkolona);
    // std::cout << "Pomocna (trebaju biti sve jedinice)" << std::endl;
    for(int i=0; i<m.bredova; i++) {
        for(int j=0; j<m.bkolona; j++) {
            if(i==j) pomocna.elementi[i][j]=1;
            else pomocna.elementi[i][j]=0;
        }
        // std::cout << pomocna.elementi[i][j]<< " ";
        //std:: cout <<std::endl;
    }   // pokusaj
    //auto matrica=StvoriMatricu(m.bredova,m.bkolona);

    auto prvamatrica=StvoriMatricu<TipElemenata>(m.bredova,m.bkolona);
    for(int i=0; i<m.bredova; i++ )
        for(int j=0; j<m.bkolona; j++) {
            if(i==j) prvamatrica.elementi[i][j]=k.at(0);
            else prvamatrica.elementi[i][j]=0;
            //std::cout << prvamatrica.elementi[i][j];
        }

    for(int i=1; i<k.size(); i++) {
        auto stepen=ProduktMatrica(pomocna,m);
        /* for(int l=0; l<m.bredova; l++){
             for(int f=0; f<m.bredova; f++)
             std::cout << stepen.elementi[l][f];
             std::cout << std::endl;
         } */
        //stepen se mijenja zbog ref u fji
        for(int l=0; l<m.bredova; l++)
            for(int f=0; f<m.bredova; f++)
                pomocna.elementi[l][f]=stepen.elementi[l][f];
        Pomnozibrojem(stepen,k.at(i));
        for(int l=0; l<m.bredova; l++)
            for(int f=0; f<m.bkolona; f++) {
                prvamatrica.elementi[l][f]+=stepen.elementi[l][f];
            }
        UnistiMatricu(stepen);

    }
    UnistiMatricu(pomocna);
    return prvamatrica;
}
int main ()
{
    Matrica<double> mat;
    std::cout << "Unesite dimenziju kvadratne matrice: ";
    int n;
    std::cin >> n;
    mat=StvoriMatricu<double>(n,n);
    std::cout << "Unesite elemente matrice A: " << std::endl;
    UnesiMatricu('A', mat);
    int m;
    std::cout << "Unesite red polinoma: ";
    std::cin >> m;
    std::cout << "Unesite koeficijente polinoma: ";
    std::vector<double> k(m+1);
    for(int i=0; i<m+1; i++)
        std::cin >> k.at(i);
    Matrica <double> polinom=MatricniPolinom(mat,k);
    IspisiMatricu(polinom,10,6,true);
    UnistiMatricu(mat);
    return 0;
}
