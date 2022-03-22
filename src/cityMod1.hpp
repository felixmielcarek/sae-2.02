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
        friend bool operator==(const City& c1, const City& c2);
    };

}; // namespace aerial_network


#endif