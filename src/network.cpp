#include "network.hpp"
using namespace std;

#include "cityMod1.hpp"

namespace aerial_network{
    //fel
    void Network::addCities(){
        string tmpName;
        
        cout << "Entrez le nom de la ville numéro "<<(cities.size()+1)<<" : ";
        cin >> tmpName;
        City* c = new CityMod1{tmpName};
        cities.push_back(c);

        // Problème pour quitter la boucle ! 
        //(Entrer ne fonctionne pas + pas dans le bon sens le if :
                    // -> meme si on donne la valeur d'arret on la rentre juste derriere
        while(tmpName != ""){
            cout << "Tapez 'Entrée' ou tapez le nom de la ville numéro "<<(cities.size()+1)<<" : ";
            cin >> tmpName;
            c = new CityMod1{tmpName};
            cities.push_back(c);
        }
        for(vector<City*>::iterator it=cities.begin();it!=cities.end();it++){
            (*it)->initDest(cities);
        }
        
    }
    void Network::displayCities(){
        for(vector<City*>::iterator it=cities.begin(); it!=cities.end();it++){
            return;
        }
    }
}