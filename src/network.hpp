#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <vector>
#include <iostream>
#include "city.hpp"

namespace aerial_network{
    class City;
    class Network{
        std::vector<City*> cities;
    public:
        int addCity(City* city);
        void displayCities();
    };
    
} // namespace aerial_network

#endif // NETWORK_HPP