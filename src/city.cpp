#include "city.hpp"
using namespace std;

namespace aerial_network{
    City::City(string name):name{name}{}
    
    string City::getName()const{
        return name;
    }
}

