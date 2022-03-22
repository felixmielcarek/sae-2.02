#include "cityMod1.hpp"

using namespace std;

namespace aerial_network{
    //Axel
    CityMod1::CityMod1(string nom)
        :City{nom}{}

    //Axel
    void CityMod1::initDest(vector<City*> cities){
        for(vector<City *>::iterator it=cities.begin();it!=cities.end();it++){ 
            if (this==(*it)){
                continue;
            }
            while(1){
                std::string choix;
                cout << "La ville : " << this->name << " est elle une destination directe vers : " << (*it)->getName() << "(O/n)" << endl;
                cin >> choix;
                if(choix != "O" && choix != "o" && choix!="N" && choix != "n"){
                    cout << "Donner une réponse valide : (O/n)" << endl;
                    continue;
                }
                if(choix=="O" || choix=="o"){
                    dest.push_back(*it);
                    break;
                }
                if(choix=="N" || choix=="n"){
                    break;
                }
            }
        }
    }

    // Axel
    bool operator==(const City& c1, const City& c2){
        return c1.getName()==c2.getName();
    }

};// namespace aerial_network