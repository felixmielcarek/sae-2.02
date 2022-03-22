#include "cityMod1.hpp"

using namespace std;

namespace aerial_network{

    CityMod1::CityMod1(string nom)
        :City{nom}{}

    void CityMod1::addDest(City* c){
        dest.push_back(c);
    }

};// namespace aerial_network