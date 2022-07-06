/* TP, 2018/2019, Zadaća 1, Zadatak 4*/

#include <iostream>
#include <vector>
#include <string>
bool PripadaRijeci (char c)
{

	if((c>='A' && c<='Z') || (c>='a' && c<= 'z') || (c>='0' && c<='9')) return true;
	return false;
}
bool MalaSlova (char c)
{
	if(c>='a' && c<='z') return true;
	return false;
}

bool JeLiSimetricna(std:: string rijec)
{

	std::vector<char> v1;
	std::vector<char> v2;
	for(int i=0; i<rijec.length(); i++) {
		if(MalaSlova(rijec.at(i))) rijec.at(i)=rijec.at(i)-32;
		v1.push_back(rijec.at(i));
	}
	for(int i=rijec.length()-1; i>=0; i--) {
		v2.push_back(rijec.at(i));
	}
	for(int i=0; i<rijec.length(); i++)
		if(v1.at(i)!=v2.at(i)) return false;
	return true;
}
std::vector <std::string> NadjiSimetricneRijeci (std::string s)
{


	std::vector<std::string> palindromi;
	bool nijepocetakrijeci=true;
	int i=0;
	while(i<s.length()) {
		std::string rijec;
		int duzina=0;
		if(!PripadaRijeci(s.at(i))) nijepocetakrijeci=true;
		else if(nijepocetakrijeci==true) nijepocetakrijeci=false;
		if(nijepocetakrijeci==false) {
			int j=i;
			for(j=i; j<s.size(); j++) {
				if(!PripadaRijeci(s.at(j))) break;
				duzina++;

			}
			rijec=s.substr(i,duzina);
			bool duplo=false;
			if(JeLiSimetricna(rijec) && duzina>=2) {
				for(int k=0; k<palindromi.size();k++)
				if(palindromi.at(k)==rijec) duplo=true;
				if(!duplo) palindromi.push_back(rijec);
				
			}
			i=j-1;
		}




		i++;
	}



	return palindromi;
}

int main ()
{
	/*std::cout << "Unesite recenicu: ";
	std::string recenica1;
	std::getline(std::cin, recenica1);
	std::vector <std:: string> palindromi=NadjiSimetricneRijeci(recenica1);
	if(palindromi.size()==0) {
		std::cout << std::endl << "Recenica ne sadrzi simetricne rijeci!";
		return 0;
	}
	std::cout <<std::endl << "Simetricne rijeci unutar recenice su:" << std::endl;
	for(int i=0; i<palindromi.size(); i++)
		std::cout << palindromi.at(i) << std::endl;*/
		auto sim = NadjiSimetricneRijeci("melem");
std::cout << sim.size() << ": '" << *sim.cbegin() << "'";
	return 0;
}
