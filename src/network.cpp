#include "network.hpp"
using namespace std;

#include "cityMod1.hpp"

namespace aerial_network{
    //fel
    Network::~Network(){
        for ( vector<City*>::iterator i = cities.begin(); i != cities.end(); ++i ){
            delete *i;
        }
    }

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
            CityMod1* tmpPtr=dynamic_cast<CityMod1*>(*it);
            tmpPtr->initDest(cities);
        }
    }
    
    // Axel
    void Network::displayCities(){
        for(vector<City*>::iterator it=cities.begin(); it!=cities.end();it++){
            CityMod1* tmpPtr=dynamic_cast<CityMod1*>(*it);
            tmpPtr->displayCity();
        }
    }

    // Axel
    void Network::searchDest(){
        cout << "De quelle ville partez vous ?\n";
        int count=1;
        for(vector<City*>::iterator it=this->cities.begin();it!=this->cities.end();it++){
            cout << count << "- " << (*it)->getName() << endl;
            count=count+1;
        }
        int choix;
        cin >> choix;
        cout << "Dans quelle ville allez vous ?\n";
        count=1;
        for(vector<City*>::iterator it=this->cities.begin();it!=this->cities.end();it++){
            cout << count << "- " << (*it)->getName() << endl;
            count=count+1;
        }
        int choix1;
        cin >> choix1;
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
            cout << "Vous êtes déjà sur place inutile de prendre un vole ! :D\n";
        }
        else{
            int x=0;
            c1->searchDest(tmp,c2,x,0);
            if(x==-1){
                cout << "Il est impossible de se rendre à " << c2->getName() << endl;
            }
            else{
                cout << "Vous pouvez aller a votre destination en " << x << " coups\n";
            }
        }
    }

    //Axel
    void Network::pushCities(City* c){
        cities.push_back(c);
    }
}