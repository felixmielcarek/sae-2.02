#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <vector>
#include <iostream>
#include "city.hpp"

//fel
namespace aerial_network{
    class City;
    class Network{
    protected:
        std::vector<City*> cities;
    public:
        Network()=default;
        ~Network();
        virtual void addCities();
        void displayCities();
        virtual void searchDest();
    };
    
} // namespace aerial_network

#endif // NETWORK_HPP