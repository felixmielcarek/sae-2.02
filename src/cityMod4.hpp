#ifndef CITYMOD4_HPP
#define CITYMOD4_HPP

#include "city.hpp"
#include "networkMod4.hpp"

//fel
namespace aerial_network{
    class CityMod4:public City{
        int num;
    public:
        CityMod4(std::string name, int num);
        ~CityMod4()=default;
        void initDest(NetworkMod4* nw);
        int getNum();
    };
}

#endif // CITYMOD4_HPP