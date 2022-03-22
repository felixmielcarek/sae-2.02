#ifndef CITY_HPP
#define CITY_HPP

#include <string>
#include <iostream>
#include <vector>

namespace aerial_network{
    class City{
    protected:
        std::string name;
        City(std::string name);
    public:
        virtual void initDest(std::vector<City*> cities)=0; 
        std::string getName() const;
    };
} // namespace aerial_network

#endif // CITY_HPP