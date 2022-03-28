#ifndef CITY_HPP
#define CITY_HPP

#include <string>
#include <iostream>
#include <vector>

//fel
namespace aerial_network{
    class City{
    protected:
        std::string name;
        City(std::string name);
    public:
        virtual ~City()=default;
        std::string getName() const;
        virtual void searchDest(std::vector<City*> tmp, City* city, int& counterFix, int counterTmp)=0;
    };
} // namespace aerial_network

#endif // CITY_HPP