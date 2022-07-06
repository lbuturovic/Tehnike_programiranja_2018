//TP 2017/2018: Tutorijal 3, Zadatak 6
#include <iostream>
#include <vector>
#include<iomanip>
typedef std::vector<std::vector<int>> Matrica;
Matrica KreirajMatricu (int broj_redova, int broj_kolona)
{

    return Matrica(broj_redova, std::vector<int>(broj_kolona));

}
int NajvecaSirina(Matrica m)
{
    int maxsirina=0;
    for(int i=0; i<m.size(); i++)
        for(int j=0; j<m[i].size(); j++) { // zasto mi javlja upozorenje
            int sirina=0;
            int pom=m[i][j];
            do {

                m[i][j]=m[i][j]/10;
                sirina++;


            } while(m[i][j]!=0);
            m[i][j]=pom;
            if(sirina>=maxsirina) {

                maxsirina=sirina;
                if(m[i][j]<0) maxsirina++;
            }



        }

    return maxsirina;

}
Matrica KroneckerovProizvod(std::vector<int> v1, std::vector<int> v2)
{

    Matrica kroneker=KreirajMatricu(v1.size(),v2.size());

    for(int i=0; i<v1.size(); i++) {
        for(int j=0; j<v2.size(); j++) {

            kroneker[i][j]=v1[i]*v2[j];

        }


    }

    return kroneker;
}
int main ()
{
    int n1;
    std::cout <<"Unesite broj elemenata prvog vektora: ";
    std::cin >> n1;
    std::cout << "Unesite elemente prvog vektora: ";
    std::vector<int> a(n1);
    for(int i=0; i<n1; i++) {
        std::cin >> a.at(i);

    }
    int n2;
    std::cout <<"Unesite broj elemenata drugog vektora: ";
    std::cin >> n2;
    std::cout << "Unesite elemente drugog vektora: ";
    std::vector<int> b(n2);
    for(int i=0; i<n2; i++) {
        std::cin >> b.at(i);

    }

    Matrica c;
    c=KroneckerovProizvod(a,b);
    std::cout << std::endl;
    for(int i=0; i<n1; i++) {
        for(int j=0; j<n2; j++) {

            std::cout << std::setw(NajvecaSirina(c)+1)<< c[i][j];

        }

        std::cout << std::endl;
    }

    return 0;
}
