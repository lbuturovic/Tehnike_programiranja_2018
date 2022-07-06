//TP 2018/2019: Tutorijal 8, Zadatak 4
#include <iostream>
#include <map>
#include <string>
std::string ZamijeniPremaRjecniku(std::string s, std::map<std::string, std::string> rjecnik){
    std::string pomocni;
    bool nijepocetakrijeci=true;
    int i=0;
    while(i<s.length()){
        std::string rijec;
        int duzina=0;
        if(s.at(i)==' ') {
            nijepocetakrijeci=true;
            pomocni=pomocni+' ';
            
        }
        else if(nijepocetakrijeci) nijepocetakrijeci=false;
        if(!nijepocetakrijeci){
            
            int j=i;
            for(j=i; j<s.size();j++){
                if(s.at(j)==' ') break;
                duzina++;
            }
            
        rijec=s.substr(i,duzina);
        auto it=rjecnik.find(rijec);
        if(it!=rjecnik.end()) pomocni=pomocni+(it->second);
        else pomocni=pomocni+rijec;
        i=j-1;}
        i++;
    }
    return pomocni;
}
int main ()
{
    std::map<std::string, std::string> rjecnik 
    { 
        {"jabuka", "apple"}, 
        {"da", "yes"}, 
        {"kako", "how"}, 
        {"ne", "no"}, 
        {"majmun", "monkey"}, 
        {"mart", "ozujak"},
        {"maj", "svibanj"}, 
        {"jul", "srpanj"}
    };
    
  std::cout << ZamijeniPremaRjecniku("  kako   da   ne   ", rjecnik) << std::endl;
	return 0;
}