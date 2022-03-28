#ifndef CITYMOD4_HPP
#define CITYMOD4_HPP

#include "city.hpp"
#include "networkMod4.hpp"

//fel
namespace aerial_network{
    class CityMod4:public City{
        int num;
        friend class NetworkMod4;
    public:
        CityMod4(std::string name, int num);
        ~CityMod4()=default;
        void initDest(std::vector<City*> cities,NetworkMod4* nw);
        int searchDest(std::vector<City*> tmp, City* city, int& counterFix, int counterTmp)override;
    };
}

#endif // CITYMOD4_HPP