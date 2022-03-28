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
        int floor=1;
        cout << "\t" << empty << "\t";

        for(int i=0 ; i<static_cast<int>(matrix.size()) ; i++){

            if(floor==1 || floor==3){
                cout << "|\t" << empty << "\t";
                if(i == static_cast<int>(matrix.size())-1){
                    floor++;
                    i=0;
                    cout << endl << "\t" << empty << "\t";
                }
            }
            else if(floor==2){
                string tmpStr=cities[i]->getName();
                tmpStr.resize(10,' ');
                cout << "|\t" << tmpStr << "\t";
                if(i == static_cast<int>(matrix.size())-1){
                    floor++;
                    i=0;
                    cout << endl;
                    cout << endl << "\t" << empty << "\t";
                }
            }
        }

        floor=1;

        for(int ii=0;ii<static_cast<int>(matrix.size());ii++){
            
            if(floor==1 || floor==3){
                cout << "|\t" << empty << "\t";
                if(ii == static_cast<int>(matrix.size())-1){
                    floor++;
                    ii=0;
                    cout << endl << "\t" << empty << "\t";
                }
            }

            else if(floor==2){
                string tmpStr=cities[ii]->getName();
                tmpStr.resize(10,' ');
                cout << "\t" << tmpStr << "\t";
                
                for(int y=0 ; y < static_cast<int>(matrix.size()) ; y++){
                    string tmpBool=to_string(matrix[ii][y]);
                    tmpBool.resize(10,' ');
                    cout << "|\t" << tmpBool << "\t";
                }
                if(ii == static_cast<int>(matrix.size())-1){
                    floor++;
                    ii=0;
                    cout << endl;
                    cout << endl << "\t" << empty << "\t";
                }
            }
        }
    }
    
    //Parcours la listes des villes et retournes sont placement (utiliser pour le vector Villes)
    // Aurian
    void NetworkMod4::place(){
        for(std::vector<City*>::iterator it=cities.begin();it!=cities.end();++it){

        }
    }
}