#include "cityMod4.hpp"
using namespace std;

namespace aerial_network{
    //fel
    CityMod4::CityMod4(string name, int num)
        :City{name},num{num}{}

    //fel
    void CityMod4::initDest(vector<City*> cities,NetworkMod4* nw){
        for(vector<City*>::iterator it=cities.begin();it!=cities.end();it++){
            if(this==(*it)){continue;}

            while(1){
                std::string choix;
                cout << "La ville : " << this->name << " est elle une destination directe vers : " << (*it)->getName() << "(O/n)" << endl;
                cin >> choix;
                if(choix != "O" && choix != "o" && choix!="N" && choix != "n"){
                    cout << "Donner une réponse valide : (O/n)" << endl;
                    continue;
                }
                if(choix=="O" || choix=="o"){
                    CityMod4* tmpPtr=dynamic_cast<CityMod4*>(*it);
                    nw->matrix[num][tmpPtr->num]=true;
                    break;
                }
                if(choix=="N" || choix=="n"){
                    break;
                }
            }
        }
        return;
    }

    void CityMod4::displayCity(){
        return;
    }

    int CityMod4::searchDest(vector<City*> tmp, City* city, int counter){
        return 0;
    }
} // aerial_network