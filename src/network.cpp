#include "network.hpp"
using namespace std;

namespace aerial_network{
    int Network::addCity(City* c){
        cities.push_back(c);
        return 0;
    }
    void Network::displayCities(){
        for(vector<City*>::iterator it=cities.begin(); it!=cities.end();it++){
            return;
        }
    }
}