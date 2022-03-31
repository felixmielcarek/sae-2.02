/**
 *\file cityMod1.cpp
 *\brief code des méthodes de la classe CityMod1 
 */

#include "cityMod1.hpp"

using namespace std;

namespace aerial_network{
    /**
     *\brief constructeur de CityMod1
     *\param nom nom que l'on souhaiter donner a la ville
     *\author DE LA FUENTE Axel
     */
    CityMod1::CityMod1(string nom)
        :City{nom}{}

    /**
     *\brief fonction intéractive permettant de remplir le vector des destinations directe accessible depuis la ville appellé avec cette méthode
     *\param cities vector contenant toute les villes du réseau (possibilité de destination)
     *\author DE LA FUENTE Axel
     */
    void CityMod1::initDest(vector<City*> cities){
        for(vector<City *>::iterator it=cities.begin();it!=cities.end();it++){ 
            if (this==(*it)){
                continue;
            }
            while(true){
                std::string choix;
                cout << "La ville : " << this->name << " est elle une destination directe vers : " << (*it)->getName() << "(O/n)" << endl;
                cin >> choix;
                if(choix != "O" && choix != "o" && choix!="N" && choix != "n"){
                    cout << "Donner une réponse valide : (o/n)" << endl;
                    continue;
                }
                if(choix=="O" || choix=="o"){
                    dest.push_back(*it);
                    break;
                }
                if(choix=="N" || choix=="n"){
                    break;
                }
            }
        }
    }

    /**
     *\brief surchage de l'opérateur "==" entre deux CityMod1
     *\param c1 première ville à comparer
     *\param c2 deuxième ville à comparer
     *\return un booléen, pour savoir si l'égalité est vrai ou fausse
     *\author DE LA FUENTE Axel
     */
    bool operator==(const City& c1, const City& c2){
        return c1.getName()==c2.getName();
    }
    
    /**
     *\brief fonction d'affichage de la CityMod1 appellé avec toutes ses destinations possible
     *\author DE LA FUENTE Axel
     */
    void CityMod1::displayCity(){
        cout << this->name << " {";
        vector<City*>::iterator it=dest.begin();
        if(it==dest.end()){
            cout << "}\n";
            return;
        }
        cout << (*it)->getName();
        it++;
        while(it!=dest.end()){
            cout << ", " << (*it)->getName();
            it++;
        }
        cout << "}\n";
    }

    /**
     *\brief fonction récursive de recherche du trajet le plus court entre deux CityMod1
     *\param tmp est un vector (vide de base) dans lequel chaque ville déjà parcourus est rentrer afin d'éviter de refaire plusieurs fois le même chemin
     *\param city est la CityMod1 que l'utilsateur souhaite atteindre en un minimu de vol
     *\param counterFix est la référence vers le compteur qui garde le trajet le plus court.
     *\param counterTmp est le compteur temporaire qui calcul le nombre de vol nécessaire pour chacun des trajets possible dans le réseau
     *\author DE LA FUENTE Axel
     */
    void CityMod1::searchDest(vector<City*> tmp, City* city, int& counterFix, int counterTmp){
        // check si deja passer par cette ville
        for(vector<City*>::iterator it=tmp.begin();it!=tmp.end();it++){
            if(*it==this){
                return;
            }
        }
        tmp.push_back(this);
        // check si on est arrivé à la dest et change le compteur
        if(this==city){
            if(counterTmp<counterFix){
                counterFix=counterTmp;
            }
            return;
        }
        // appelle récursivement pour chaque destination possible
        counterTmp=counterTmp+1;
        for(vector<City*>::iterator it=dest.begin(); it!=dest.end();it++){
            CityMod1* tmpCity=dynamic_cast<CityMod1*>(*it);
            tmpCity->searchDest(tmp,city,counterFix,counterTmp);
        }
        return;
    }

    /**
     *\brief setter pour le vector dest de la CityMod1 appellé
     *\param c ville ajouter au vector dest
     *\author DE LA FUENTE Axel
     */
    void CityMod1::pushCity(City* c){
        dest.push_back(c);
    }
};// namespace aerial_network