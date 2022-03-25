#include "cityMod1.hpp"

using namespace std;

namespace aerial_network{
    //Axel
    CityMod1::CityMod1(string nom)
        :City{nom}{}

    //fel
    CityMod1::~CityMod1(){
        for ( vector<City*>::iterator i = dest.begin(); i != dest.end(); ++i ){
            delete *i;
        }
    }

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
    // CA MARCHE PAS EHEH EN MEME TEMPS IL EST DEJA PRESQUE 00H00 
    // ET J'ECRIT DE LA GROSSE CHIASSE DONC JE CONTINUERAI PLUS TARD
    // EN VRAI CA MARCHE PRESQUE
    int CityMod1::searchDest(vector<City*> tmp, City* city, int counter){
        // check si deja passer par cette ville
        for(vector<City*>::iterator it=tmp.begin();it!=tmp.end();it++){
            if(*it==this){
                return -1;
            }
        }
        tmp.push_back(this);
        // check si on est arrivé à la dest
        if(this==city){
            return counter;
        }
        // appelle récursivement pour chaque destination possible
        for(vector<City*>::iterator it=this->dest.begin();it!=this->dest.end();it++){
            int x=(*it)->searchDest(tmp,city,counter);
            if(x==-1){
                continue;
            }
            counter=counter+1;
        }
        return -1;
    }
};// namespace aerial_network