/**
 *\file network.cpp
 *\brief code des méthodes de la classe Network
 */

#include <algorithm>
#include "network.hpp"
#include "cityMod1.hpp"
#include "exception.hpp"

using namespace std;

namespace aerial_network{
    /**
     *\brief constructeur de Network
     *\author MIELCAREK Félix
     */
    Network::~Network(){
        for ( vector<City*>::iterator i = cities.begin(); i != cities.end(); ++i ){
            delete *i;
        }
        cities.clear();
    }

    /**
     *\brief fonciton interactive permmettant des créer dynamiquement des CityMod1 et de les ajouter au 
     *\brief conteneur 'cities' de Network
     *\author MIELCAREK Félix
     */
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
            CityMod1* tmpPtr=dynamic_cast<CityMod1*>(*it);
            tmpPtr->initDest(cities);
        }
    }
    
    /**
     *\brief fonction permettant l'appelle de la fonction d'affichage de chacune des villes du conteneur
     *\brief 'cities'
     *\author DE LA FUENTE Axel
     */
    void Network::displayCities(){
        for(vector<City*>::iterator it=cities.begin(); it!=cities.end();it++){
            CityMod1* tmpPtr=dynamic_cast<CityMod1*>(*it);
            tmpPtr->displayCity();
        }
    }
    
    /**
     *\brief fonction interactive demandant où l'utilisateur souhaite se rendre, et lui renvoie le nombre
     *\brief de vol nécessaire, ou bien lui dit si ce n'est pas possible.
     *\author DE LA FUENTE Axel
     */
    void Network::searchDest(){
        cout << "De quelle ville partez vous ?\n";
        int count=1;
        for(vector<City*>::iterator it=this->cities.begin();it!=this->cities.end();it++){
            cout << count << "- " << (*it)->getName() << endl;
            count=count+1;
        }
        int choix;
        cin >> choix;

        if(choix<0 || choix>static_cast<int>(cities.size())){ throw NonExistentCityException{}; }

        cout << "Dans quelle ville allez vous ?\n";
        count=1;
        for(vector<City*>::iterator it=this->cities.begin();it!=this->cities.end();it++){
            cout << count << "- " << (*it)->getName() << endl;
            count=count+1;
        }
        int choix1;
        cin >> choix1;

        if(choix1<0 || choix1>static_cast<int>(cities.size())){ throw NonExistentCityException{}; }

        vector<City*> tmp;
        count=1;
        City* c1;
        City* c2;
        for(vector<City*>::iterator it=this->cities.begin();it!=this->cities.end();it++){
            if(count==choix){
                c1=*it;
            }   
            if(count==choix1){
                c2=*it;
            }
            count=count+1;
        }
        if(c1==c2){
            throw SamePlaceException{};
        }
        else{
            int x=999;
            CityMod1* tmpC1=dynamic_cast<CityMod1*>(c1);
            tmpC1->searchDest(tmp,c2,x,0);
            if(x==999){ throw NonExistentPathException{c1->getName(),c2->getName()}; }
            else{
                cout << "Vous pouvez aller a votre destination en " << x << " coups\n";
            }
        }
    }

     /**
     *\brief fonction setter, afin d'ajouter des cityMod1 dans le conteneur 'cities'
     *\author DE LA FUENTE Axel
     */
    void Network::pushCities(City* c){
        cities.push_back(c);
    }
}