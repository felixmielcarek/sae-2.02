#include "city.hpp"
using namespace std;

namespace aerial_network{
    City::City(string name,int number):name{name},number{number}{}
    
    ostream& operator<<(ostream &s,const City& c){
        s << c.name << " (" << c.number << ")";
        return s;
    }

    string City::getName()const{return name;}
    int City::getNumber()const{return number;}
}

