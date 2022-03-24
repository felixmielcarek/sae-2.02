#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <vector>
#include <iostream>
#include "city.hpp"

//fel
namespace aerial_network{
    class City;
    class Network{
        std::vector<City*> cities;
    public:
        virtual void addCities();
        void displayCities();
        void searchDest();
    };
    
} // namespace aerial_network

#endif // NETWORK_HPP