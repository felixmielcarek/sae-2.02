#ifndef CITY_HPP
#define CITY_HPP

#include <string>

namespace aerial_network{
    class City{
        std::string name;
        int number;
    public:
        City(std::string name,int number);
        std::string getName();
        int getNumber();
    };
} // namespace aerial_network

#endif // CITY_HPP