#include "cityMod1.hpp"

using namespace std;

namespace aerial_network{
    //Axel
    CityMod1::CityMod1(string nom)
        :City{nom}{}

    //Axel
    //Il faut revoir les pointeur de city avec le vector cities --> pour remplir le vector dest
    /*
    void CityMod1::initDest(vector<City*> cities){
        std::string choix;
        for(vector<City *>::iterator it=cities.begin();it!=cities.end();it++){
        while(1){
            cout << "La ville : " << this->name << "est elle une destination directe vers : " << cities->name << "(O/n)" << endl;
            cin >> choix;
            if(choix != "O" && choix != "o" && choix!="N" && choix != "n"){
                cout << "Donner une réponse valide : (O/n)" << endl;
                continue;
            }
                if(choix=="O" || choix=="o"){
                    dest.push_back(cities);
                    return;
                }
                if(choix=="N" || choix=="n"){
                    return;
                }
            }
        }
    }
    */
};// namespace aerial_network