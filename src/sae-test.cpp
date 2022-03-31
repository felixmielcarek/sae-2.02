/**
 *\file sae-test.cpp
 *\brief code des fonctions de test et des fonctions de création de réseau (main) 
 */

#include <iostream>
#include <string>
#include "network.hpp"
#include "cityMod1.hpp"
#include "cityMod4.hpp"
#include "city.hpp"
#include "exception.hpp"

//code couleur
#define NC "\e[0m"
#define RED "\e[0;31m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"
#define YEL "\033[0;33m"
#define CLEAR "\e[1;1H\e[2J"

using namespace std;
using namespace aerial_network;

/**
 *\brief fonction de test grâce à la création d'un réseau par défaut
 *\author DE LA FUENTE Axel
 */
void testDefaultCityMod1(){
    Network nwDefault;
    City* c1 = new CityMod1{"Clermont-Ferrand"};
    City* c2 = new CityMod1{"Castres"};
    City* c3 = new CityMod1{"Albi"};
    City* c4 = new CityMod1{"Perpignan"};
    City* c5 = new CityMod1{"Paris"};
    City* c6 = new CityMod1{"Lyon"};
    nwDefault.pushCities(c1);
    nwDefault.pushCities(c2);
    nwDefault.pushCities(c3);
    nwDefault.pushCities(c4);
    nwDefault.pushCities(c5);
    nwDefault.pushCities(c6);

    CityMod1* tmp=dynamic_cast<CityMod1*>(c1);
    tmp->pushCity(c2);
    tmp->pushCity(c4);
    tmp=dynamic_cast<CityMod1*>(c2);
    tmp->pushCity(c1);
    tmp->pushCity(c5);
    tmp=dynamic_cast<CityMod1*>(c3);
    tmp->pushCity(c1);
    tmp=dynamic_cast<CityMod1*>(c4);
    tmp->pushCity(c2);
    tmp=dynamic_cast<CityMod1*>(c5);
    tmp->pushCity(c2);
    tmp->pushCity(c4);
    tmp->pushCity(c6);
    tmp=dynamic_cast<CityMod1*>(c6);
    tmp->pushCity(c1);
    tmp->pushCity(c2);
    tmp->pushCity(c4);
    tmp->pushCity(c5);
    
    nwDefault.displayCities();
    cout <<endl;
    try{
        nwDefault.searchDest();
    }
    catch(const SamePlaceException &e){
        cout <<endl;
    }
    catch(const NonExistentCityException &ex){
        cout <<endl;
    }
    catch(const NonExistentPathException &ex){
        cout <<endl;
    }
}

/**
 *\brief sous-menu afin de gérer les réseaux sous le modèle 1 (NetworkMod1)
 *\author DE LA FUENTE Axel
 */
void menuCityMod1(){
    string flag;
    cout << CLEAR;
    while(true){
        string choice;
        cout << YEL "\n===== Menu Réseau (modèle liste (1)) =====" NC <<endl;
        cout << "1. Utiliser le réseau par défaut" << endl;
        cout << "2. Créer son propre réseau" << endl;
        cout << "Donner votre choix (q pour quitter) :";
        cin >> choice;
        if(choice!="q" && choice!="Q" && choice!="1" && choice!="2"){
            cout << CLEAR REDB "Veuillez rentrer une valeur valide" NC << endl;
            continue;
        }
        else if(choice == "q" || choice == "Q"){
            cout << CLEAR;
            return;
        }
        else if(choice == "1"){
            cout << CLEAR CYN "\n----- Bienvenue dans la réseau par défaut -----" NC << endl;
            testDefaultCityMod1();
            cout << "(Appuyer sur Entrer pour continuer)\n";
            system("read");
            cout << CLEAR;
        }
        else if(choice == "2"){
            cout << CYN "\n----- Bienvenue dans l'outil de création de réseau -----" NC << endl;
            Network nw;
            nw.addCities();
            cout << CLEAR CYN "---- Réseau ----" NC << endl;
            nw.displayCities();
            cout << endl;
            try{
                nw.searchDest();
            }
            catch(const SamePlaceException &e){
                cout <<endl;
            }
            catch(const NonExistentCityException &ex){
                cout <<endl;
            }
            catch(const NonExistentPathException &ex){
                cout <<endl;
            }
            cout << "(Appuyer sur Entrer pour continuer)\n";
            system("read");
            cout << CLEAR;
        }
    }
}

/**
 *\brief sous-menu afin de gérer les réseaux sous le modèle 4 (NetworkMod4)
 *\author MIELCAREK Félix
 */
void menuCityMod4(){
    cout << CLEAR;
    while(true){
        string choice;
        NetworkMod4 nw;
        cout << YEL "\n===== Menu Réseau (modèle matrice (4)) =====" NC <<endl;
        cout << "1. Utiliser le réseau par défaut" << endl;
        cout << "2. Créer son propre réseau" << endl;
        cout << "Donner votre choix (q pour quitter) :";
        cin >> choice;
        if(choice!="q" && choice!="Q" && choice!="1" && choice!="2"){
            cout << CLEAR REDB "Veuillez rentrer une valeur valide" NC << endl;
            continue;
        }
        else if(choice == "q" || choice == "Q"){
            cout << CLEAR;
            return;
        }
        else if(choice == "1"){
            cout << CLEAR CYN "\n----- Bienvenue dans la réseau par défaut -----" NC << endl;
            nw.defaultCityMod4();
            cout << CLEAR;
        }
        else if(choice == "2"){
            cout << CYN "\n----- Bienvenue dans l'outil de création de réseau -----" NC << endl;
            nw.addCities();
        }
        cout << CLEAR CYN "---- Réseau ----" NC << endl;
        try{
            nw.displayCities();
            cout << endl;
            try{
                nw.searchDest();
            }
            catch(const SamePlaceException &e){
                cout <<endl;
            }
            catch(const NonExistentCityException &ex){
                cout <<endl;
            }
            catch(const NonExistentPathException &ex){
                cout <<endl;
            }
        }
        catch(const NoCityException& e){
            cout << endl;
        }
        
        cout << " (Appuyer sur Entrer pour continuer)\n";
        system("read");
        cout << CLEAR;
    }
}

/**
 *\brief menu principale afin de gérer le choix du réseau utilisé
 *\author DE LA FUENTE Axel
 */
int main(){
    cout << CLEAR;
    while(true){
        string choice;
        cout << RED "\n===== Menu Principal =====" NC <<endl;
        cout << "1. Utiliser le réseau en liste" << endl;
        cout << "2. Utiliser le réseau en matrice" << endl;
        cout << "Donner votre choix (q pour quitter) :";
        cin >> choice;
        if(choice!="q" && choice!="Q" && choice!="1" && choice!="2"){
            cout << CLEAR REDB "Veuillez rentrer une valeur valide" NC << endl;
            continue;
        }
        else if(choice == "q" || choice == "Q"){
            cout << CLEAR;
            return 0;
        }
        else if(choice == "1"){
            menuCityMod1(); 
        }
        else if(choice == "2"){
            menuCityMod4();
        }
    }
}

