/**
 *\file city.hpp
 *\brief délcaration de la classe mère city ainsi que de ses méthodes. 
 *\author MIELCAREK Félix
 */

#ifndef CITY_HPP
#define CITY_HPP

#include <string>
#include <iostream>
#include <vector>

namespace aerial_network{
    // Félix
    class City{
    protected:
        std::string name;
        City(std::string name);
    public:
        virtual ~City()=default;
        std::string getName() const;
    };
} // namespace aerial_network

#endif // CITY_HPP