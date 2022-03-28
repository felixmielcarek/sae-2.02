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
        virtual void displayCities();
        virtual void searchDest();
        virtual void pushCities(City* c);
    };
    
} // namespace aerial_network

#endif // NETWORK_HPP