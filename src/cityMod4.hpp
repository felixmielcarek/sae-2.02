#ifndef CITYMOD4_HPP
#define CITYMOD4_HPP

#include "city.hpp"

//fel
namespace aerial_network{
    class CityMod4:public City{
        int num;
    public:
        CityMod4(std::string name, int num);
        ~CityMod4()=default;
        void initDest(std::vector<City*> cities)override;
        void displayCity()override;
        int searchDest(std::vector<City*> tmp, City* city, int counter)override;
    };
}

#endif // CITYMOD4_HPP