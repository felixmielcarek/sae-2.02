#ifndef CITYMOD1_HPP
#define CITYMOD1_HPP

#include <vector>
#include <string>
#include "city.hpp"

namespace aerial_network{

    class CityMod1 : public City{
        std::vector<City*> access;
    public:
        CityMod1(std::string nom);
        void addAccess(City* c);
    };

}; // namespace aerial_network


#endif