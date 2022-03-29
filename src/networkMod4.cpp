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
        cities.clear();
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
            cout << "ou tapez le nom de la ville numéro "<< (cities.size()+1) << " : ";
            cin >> tmpName;
        }

        int cs = static_cast<int>(cities.size());
        for(int i=0; i<cs;i++){
            vector<bool> tmpV;
            tmpV.resize(cs);
            for(int y=0 ; y<cs ; y++){
                tmpV[y]=false;
            }
            matrix.push_back(tmpV);
        }

        for(vector<City*>::iterator it=cities.begin();it!=cities.end();it++){
            CityMod4* tmpPtr=dynamic_cast<CityMod4*>(*it);
            tmpPtr->initDest(this);
        }
    }
    
    //fel
    void NetworkMod4::displayCities(){
        string empty;
        empty.resize(10,' ');

        cout << "\\__________     Arrivé  " ;
        tabEmptyDisplay();

        cout << "           \\___________ ";
        for(int i = 0 ; i < static_cast<int>(matrix.size()) ; i++){
            string tmpStr=cities[i]->getName();
            tmpStr.resize(10,' ');
            cout << "|\t" << tmpStr << "\t";
        }

        cout << endl << "   Départ              \\";
        tabEmptyDisplay();

        for(int i=0;i<static_cast<int>(matrix.size());i++){
            string tmpStr=cities[i]->getName();
            tmpStr.resize(10,' ');

            for (int ii = 0; ii < static_cast<int>(matrix.size())+1; ii++){
                cout << "-------------------------" ;
            }            
            cout << endl << "\t" << empty << "\t";

            tabEmptyDisplay();

            cout << "\t" << tmpStr << "\t";
                
            for(int y=0 ; y < static_cast<int>(matrix.size()) ; y++){
                string res;
                if(matrix[i][y]){
                    res="Accessible";
                }
                else{
                    res=" ";
                }
                res.resize(10,' ');
                
                cout << "|\t" << res << "\t";
            }
            cout << endl << "\t" << empty << "\t";
            tabEmptyDisplay();
        }
    }
    
    //fel
    void NetworkMod4::tabEmptyDisplay(){
        string empty;
        empty.resize(10,' ');

        for(int i=0 ; i<static_cast<int>(cities.size()) ; i++){
            cout << "|\t" << empty << "\t";
        }
        cout << endl;
    }

    void NetworkMod4::pushCities(City* c){
        cities.push_back(c);
    }

}