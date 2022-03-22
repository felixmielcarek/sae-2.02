#ifndef CITYMOD4_HPP
#define CITYMOD4_HPP

#include "city.hpp"
#include <string>

namespace aerial_network{
    class CityMod4:public City{
        int num;
    public:
        CityMod4(std::string name, int num);
    };
}

#endif // CITYMOD4_HPP