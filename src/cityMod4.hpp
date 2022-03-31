/**
 *\file cityMod4.hpp
 *\brief délcaration de la classe fille cityMod4 (selon le modèle 4, en matrice) ainsi que de ses méthodes. 
 *\author MIELCAREK Félix
 */

#ifndef CITYMOD4_HPP
#define CITYMOD4_HPP

#include "city.hpp"
#include "networkMod4.hpp"

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