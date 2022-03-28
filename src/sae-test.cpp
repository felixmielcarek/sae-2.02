#include <iostream>
#include <string>
#include "network.hpp"
#include "cityMod1.hpp"
#include "city.hpp"

//code couleur
#define NC "\e[0m"
#define RED "\e[0;31m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"
#define CLEAR "\e[1;1H\e[2J"

using namespace std;
using namespace aerial_network;

//Axel
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
    tmp->pushCity(c3);
    tmp=dynamic_cast<CityMod1*>(c3);
    tmp->pushCity(c1);
    tmp=dynamic_cast<CityMod1*>(c4);
    tmp->pushCity(c2);
    tmp->pushCity(c3);
    tmp->pushCity(c6);
    tmp=dynamic_cast<CityMod1*>(c5);
    tmp->pushCity(c2);
    tmp->pushCity(c4);
    tmp->pushCity(c6);
    tmp=dynamic_cast<CityMod1*>(c6);
    tmp->pushCity(c1);
    tmp->pushCity(c2);
    tmp->pushCity(c3);
    tmp->pushCity(c4);
    tmp->pushCity(c5);
    
    nwDefault.displayCities();
    cout <<endl;
    nwDefault.searchDest();
}

// Axel
int main(){
    string flag;
    cout << CLEAR;
    while(1){
        string choice;
        cout << RED "\n===== Menu principal =====" NC <<endl;
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
            return 0;
        }
        else if(choice == "1"){
            cout << CLEAR CYN "\n----- Bienvenue dans la réseau par défaut -----" NC << endl;
            testDefaultCityMod1();
            cout << "(Appuyer sur Entrer pour continuer)\n";
            system("read"); // pas ouff -> mais marche bien
            cout << CLEAR;
        }
        else if(choice == "2"){
            cout << CYN "\n----- Bienvenue dans l'outil de création de réseau -----" NC << endl;
            Network nw;
            nw.addCities();
            cout << CLEAR CYN "---- Réseau ----" NC << endl;
            nw.displayCities();
            cout << endl;
            nw.searchDest();
            cout << "(Appuyer sur Entrer pour continuer)\n";
            system("read");
            cout << CLEAR;
        }
    }
}