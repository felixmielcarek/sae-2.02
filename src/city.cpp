#include "city.hpp"
using namespace std;

namespace aerial_network{
    /**
     *\brief constructeur de City
     *\param name nom que l'on souhaiter donner a la ville
     *\author MIELCAREK Félix & JAULT Aurian & DE LA FUENTE Axel
     */
    City::City(string name):name{name}{}

    /**
     *\brief getter du nom de City
     *\author MIELCAREK Félix & JAULT Aurian & DE LA FUENTE Axel
     */
    string City::getName()const{
        return name;
    }
}

