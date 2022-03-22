#include <iostream>
#include <string>
#include "network.hpp"
#include "city.hpp"
using namespace std;
using namespace aerial_network;


int main(){
    cout << "----- Bienvenue à l'aéroport de Aulnat ----------"<< endl;
    Network nw;
    nw.displayCities();
    return 0;
}