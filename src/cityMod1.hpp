#ifndef CITYMOD1_HPP
#define CITYMOD1_HPP

#include <vector>
#include <string>
#include "city.hpp"

namespace aerial_network{

    class CityMod1 : public City{
        std::vector<City*> dest;
    public:
        CityMod1(std::string nom);
        void addDest(City* c);
    };

}; // namespace aerial_network


#endif