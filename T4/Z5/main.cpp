//TP 2018/2019: Tutorijal 4, Zadatak 5
#include <iostream>
#include <vector>
#include <string>
template <typename NekiTip>
std::vector<NekiTip> Presjek(std::vector<NekiTip> v1, std::vector<NekiTip> v2)
{
    std::vector<NekiTip> v3;
    for(int i=0; i<v1.size(); i++)
        for(int j=0; j<v2.size(); j++) {

            if(v1.at(i)==v2.at(j)) {
                bool nijesadrzan=true;
                for(int k=0; k<v3.size(); k++) {
                    if(v3.at(k)==v2.at(j)) nijesadrzan=false;

                }

                if(nijesadrzan) v3.push_back(v2.at(j));



            }



        }

    return v3;
}
int main ()
{   for(int k=0; k<2; k++){
    if(k==0)std::cout << "Test za realne brojeve..." << std::endl;
    else std::cout << "Test za stringove..."  << std::endl;
    std::cout << "Unesite broj elemenata prvog vektora: ";
    int n1,n2;
    std::cin >> n1;
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    if(k==0)std::cout << "Unesite elemente prvog vektora: ";
    if(k==1)std::cout << "Unesite elemente prvog vektora (ENTER nakon svakog unosa): ";
    std::string pomocni;
    std::vector <double> v1(n1);
    std::vector <std::string> string1(n1);
    if(k==0)
    for(int i=0; i<n1; i++)
        std::cin >> v1.at(i);
    if(k==1)
    for(int i=0; i<n1; i++){
       std::getline (std::cin, pomocni);
        string1.push_back(pomocni);
    }
    std::cout << "Unesite broj elemenata drugog vektora: ";
    std::cin >> n2;
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::vector <double> v2(n2);
    std::vector <std::string> string2(n2);
    if(k==0) std::cout << "Unesite elemente drugog vektora: ";
    if(k==1) std::cout <<"Unesite elemente drugog vektora (ENTER nakon svakog unosa): ";
    if(k==0)
    for(int i=0; i<n2; i++)
        std::cin >> v2.at(i);
    if(k==1)
    for(int i=0; i<n2; i++){
       std::getline (std::cin, pomocni);
        string2.push_back(pomocni);
    }
    std::cout << "Zajednicki elementi su: ";
    auto v3=Presjek(v1, v2);
    auto string3=Presjek(string1,string2);
    if(k==0)
    for(int i=0; i<v3.size(); i++) {
        std::cout << v3.at(i) << " ";
    }
    if(k==1)
    for(int i=0; i<string3.size();i++){
        std::cout << string3.at(i) << std::endl;
        
    }
        std::cout << std::endl;
}
    
    
    return 0;
}
