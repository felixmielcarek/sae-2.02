#ifndef CITY_HPP
#define CITY_HPP

#include <string>
#include <iostream>

namespace aerial_network{
    class City{
    protected:
        std::string name;
        City(std::string name);
    };
} // namespace aerial_network

#endif // CITY_HPP