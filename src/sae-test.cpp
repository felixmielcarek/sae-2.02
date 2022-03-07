#include <iostream>
#include <string>
#include "network.hpp"
#include "city.hpp"
using namespace std;
using namespace aerial_network;


int main(){
    cout << "----- Bienvenue à l'aéroport de Aulnat ----------"<< endl;
    Network nw;
    City clf{"Clermont-Ferrand",1};
    City cas{"Castres",2};
    nw.addCity(&clf);
    cout << cas << endl;
    nw.displayCities();
    return 0;
}