//TP 2017/2018: Tutorijal 3, Zadatak 7
#include <iostream>
#include <vector>
#include <iomanip>
typedef std::vector <std::vector<int>> Matrica;
Matrica KreirajMatricu(int broj_redova, int broj_kolona) {
    
    return Matrica(broj_redova,std::vector<int> (broj_kolona));
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


Matrica PascalovTrougao(int n) {
    /*Matrica trougao(n);*/
    Matrica m;
    if(n==0) return m;
    if(n<0) throw std::domain_error ("Broj redova ne smije biti negativan");
    auto trougao=KreirajMatricu(n,n);
    for(int i=0;i<n;i++) trougao[i].resize(i+1);
    for(int i=0;i<n;i++)
        for(int j=0;j<trougao[i].size();j++) {
            if(j==0 || i==j) trougao.at(i).at(j)=1;
            else trougao.at(i).at(j)=trougao.at(i-1).at(j)+trougao.at(i-1).at(j-1);
            
        }
        
    return trougao;
}
int main ()
{
    int n;
    std::cout << "Unesite broj redova: ";
    std::cin >> n;
    std::cout << std::endl;
    Matrica trougao=PascalovTrougao(n);
    for(int i=0;i<n;i++)
      for(int j=0;j<trougao[i].size();j++) {
          std::cout << std::setw(NajvecaSirina(trougao)+1) << trougao.at(i).at(j);
          if(i==j) std::cout << std::endl;
      }
	return 0;
}
