#include "networkMod4.hpp"
#include "cityMod4.hpp"
#include <string>
using namespace std;

namespace aerial_network{
    //fel
    NetworkMod4::~NetworkMod4(){
        for ( vector<City*>::iterator i = cities.begin(); i != cities.end(); ++i ){
            delete *i;
        }
    }

    //Aurian Fél
    //Fais correspondre un "TRUE" pour chaque villes saisie
    void NetworkMod4::addCities(){
        string tmpName;
        City* c;
        
        cout << "Entrez le nom de la ville numéro "<<(cities.size()+1)<<" : ";
        cin >> tmpName;

        while(tmpName != "-1"){
            c = new CityMod4{tmpName,static_cast<int>(cities.size())};
            cities.push_back(c);
            cout << "Entrez '-1' si vous ne souhaitez pas rajouter de ville," << endl;
            cout << "ou tapez le nom de la ville numéro "<<(cities.size()+1)<<" : ";
            cin >> tmpName;
        }

        int cs = (int) cities.size();
        for(int i=0; i<cs;i++){
            vector<bool> tmpV (false,cs);
            matrix.push_back(tmpV);
        }

        for(vector<City*>::iterator it=cities.begin();it!=cities.end();it++){
            CityMod4* tmpPtr=dynamic_cast<CityMod4*>(*it);
            tmpPtr->initDest(cities,this);
        }
    }
    
    void NetworkMod4::displayCities(){
        string empty;
        empty.resize(10,' ');
        cout << "\t" << empty << "\t";
        for(int i=0;i<static_cast<int>(matrix.size());i++){
            string tmpStr=cities[i]->getName();
            tmpStr.resize(10,' ');
            cout << "|\t" << tmpStr << "\t";
        }
    }
    
    //Parcours la listes des villes et retournes sont placement (utiliser pour le vector Villes)
    // Aurian
    void NetworkMod4::place(){
        for(std::vector<City*>::iterator it=cities.begin();it!=cities.end();++it){

        }
    }
}