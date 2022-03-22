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

        while(tmpName != ""){
            cout << "Tapez 'Entrée' ou tapez le nom de la ville numéro "<<(cities.size()+1)<<" : ";
            cin >> tmpName;
            c = new CityMod1{tmpName};
            cities.push_back(c);
        }

        for(vector<City*>::iterator it=cities.begin();it!=cities.end();it++){
            // appelle fonction de cityMod1
            //it->initDest(cities);
        }
        
    }
    void Network::displayCities(){
        for(vector<City*>::iterator it=cities.begin(); it!=cities.end();it++){
            return;
        }
    }
}