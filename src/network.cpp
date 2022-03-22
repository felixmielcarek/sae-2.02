#include "network.hpp"
using namespace std;

#include "cityMod1.hpp"

namespace aerial_network{
    //fel
    void Network::addCities(){
        string tmpName;
        City* c;
        
        cout << "Entrez le nom de la ville numéro "<<(cities.size()+1)<<" : ";
        cin >> tmpName;

        while(tmpName != "-1"){
            c = new CityMod1{tmpName};
            cities.push_back(c);
            cout << "Entrez '-1' si vous ne souhaitez pas rajouter de ville," << endl;
            cout << "ou tapez le nom de la ville numéro "<<(cities.size()+1)<<" : ";
            cin >> tmpName;
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