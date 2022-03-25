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
        virtual ~City()=default;
        virtual void initDest(std::vector<City*> cities)=0; 
        std::string getName() const;
        virtual void displayCity()=0;
        virtual int searchDest(std::vector<City*> tmp, City* city, int counter)=0;
    };
} // namespace aerial_network

#endif // CITY_HPP