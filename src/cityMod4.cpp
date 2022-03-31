/**
 *\file cityMod4.cpp
 *\brief code des méthodes de la classe CityMod4
 */

#include "cityMod4.hpp"
using namespace std;

namespace aerial_network{
    /**
     *\brief constructeur de CityMod4
     *\param name nom que l'on souhaite donner à la ville
     *\param num numero attribué à la ville
     *\author MIELCAREK Félix
     */
    CityMod4::CityMod4(string name, int num)
        :City{name},num{num}{}

    /**
     *\brief fonction interactive permettant d'initialiser les liaisons entre les ville de type CityMod4
     *\param nw pointeur sur le NetworkMod4 que l'on souhaite initialiser
     *\author MIELCAREK Félix
     */
    void CityMod4::initDest(NetworkMod4* nw){
        for(vector<City*>::iterator it=nw->cities.begin() ; it!=nw->cities.end() ; it++){
            if(this==(*it)) {continue;}

            while(true){
                string choix;
                cout << "La ville : " << this->name << " est elle une destination directe vers : " << (*it)->getName() << "(O/n)" << endl;
                cin >> choix;
                if(choix != "O" && choix != "o" && choix!="N" && choix != "n"){
                    cout << "Donner une réponse valide : (o/n)" << endl;
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
    
    /**
     *\brief getter du numéro de la ville
     *\author MIELCAREK Félix
     */
    int CityMod4::getNum(){ return num; }
} // aerial_network