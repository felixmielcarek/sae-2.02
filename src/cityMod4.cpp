#include "cityMod4.hpp"
using namespace std;

namespace aerial_network{
    //fel
    CityMod4::CityMod4(string name, int num)
        :City{name},num{num}{}

    //fel
    void CityMod4::initDest(NetworkMod4* nw){
        for(vector<City*>::iterator it=nw->cities.begin() ; it!=nw->cities.end() ; it++){
            if(this==(*it)) {continue;}

            while(1){
                string choix;
                cout << "La ville : " << this->name << " est elle une destination directe vers : " << (*it)->getName() << "(O/n)" << endl;
                cin >> choix;
                if(choix != "O" && choix != "o" && choix!="N" && choix != "n"){
                    cout << "Donner une réponse valide : (O/n)" << endl;
                    continue;
                }
                if(choix=="O" || choix=="o"){
                    CityMod4* tmpPtr=dynamic_cast<CityMod4*>(*it);
                    nw->matrix[this->num][tmpPtr->num]=true;
                    break;
                }
                if(choix=="N" || choix=="n"){
                    break;
                }
            }
        }
    }

    int CityMod4::getNum(){ return num; }
} // aerial_network