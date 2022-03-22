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
        void initDest(std::vector<City*> cities);
    };

}; // namespace aerial_network


#endif