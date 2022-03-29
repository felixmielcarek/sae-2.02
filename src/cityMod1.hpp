/**
 *\file cityMod1.hpp
 *\brief déclaration de la classe City (selon le modèle 1, en liste), ainsi que la déclaration de ses méthodes
 *\author DE LA FUENTE Axel
 */

#ifndef CITYMOD1_HPP
#define CITYMOD1_HPP

#include <vector>
#include <string>
#include "city.hpp"

namespace aerial_network{

    //Axel
    class CityMod1 : public City{
        std::vector<City*> dest;
    public:
        CityMod1(std::string nom);
        ~CityMod1()=default;
        void initDest(std::vector<City*> cities);
        void displayCity();
        void searchDest(std::vector<City*> tmp, City* city, int& counterFix, int counterTmp);
        void pushCity(City* c);
        friend bool operator==(const City& c1, const City& c2);
    };

}; // namespace aerial_network


#endif