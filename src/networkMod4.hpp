/**
 *\file networkMod4.hpp
 *\brief délcaration de la classe NetworkMod4 ainsi que de ses méthodes. 
 *\author MIELCAREK Félix
 */

#ifndef NETWORKMOD4_HPP
#define NETWORKMOD4_HPP
#include "network.hpp"
#include "exception.hpp"

namespace aerial_network{
    class NetworkMod4:public Network{
            friend class CityMod4;
            int matrixPath(int a,const int b,std::vector<int>& path);
        public:
            NetworkMod4()=default;
            ~NetworkMod4();
            std::vector<std::vector<bool>> matrix;
            void addCities()override;
            void defaultCityMod4();
            void searchDest()override;
            void displayCities()override;
    };
}
#endif // NETWORKMOD4_HP