#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <vector>
#include "City.hpp"

namespace aerial_network{
    class City;
    class Network{
        vector<City> cities;
    public:
        int addCity(City city);
    };
} // namespace aerial_network

#endif // NETWORK_HPP