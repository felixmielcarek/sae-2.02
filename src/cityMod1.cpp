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
    
    // Axel
    void CityMod1::displayCity(){
        cout << this->name << " {";
        vector<City*>::iterator it=dest.begin();
        if(it==dest.end()){
            cout << "}\n";
            return;
        }
        cout << (*it)->getName();
        it++;
        while(it!=dest.end()){
            cout << ", " << (*it)->getName();
            it++;
        }
        cout << "}\n";
    }

    // Axel
    void CityMod1::searchDest(vector<City*> tmp, City* city, int& counterFix, int counterTmp){
        // check si deja passer par cette ville
        for(vector<City*>::iterator it=tmp.begin();it!=tmp.end();it++){
            if(*it==this){
                return;
            }
        }
        tmp.push_back(this);
        // check si on est arrivé à la dest et change le compteur
        if(this==city){
            cout << "TROUVE" << endl;
            if(counterTmp<counterFix){
                counterFix=counterTmp;
            }
            return;
        }
        // appelle récursivement pour chaque destination possible
        for(vector<City*>::iterator it=dest.begin(); it!=dest.end();it++){
            counterTmp=counterTmp+1;
            (*it)->searchDest(tmp,city,counterFix,counterTmp);
        }
    }

    //Axel
    void CityMod1::pushCity(City* c){
        dest.push_back(c);
    }
};// namespace aerial_network