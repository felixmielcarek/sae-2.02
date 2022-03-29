#ifndef NETWORKMOD4_HPP
#define NETWORKMOD4_HPP
#include "network.hpp"

namespace aerial_network{
    class NetworkMod4:public Network{
        friend class CityMod4;
        public:
            NetworkMod4()=default;
            ~NetworkMod4();
            std::vector<std::vector<bool>> matrix;
            void addCities()override;
            void defaultCityMod4();
            void displayCities()override;
    };
}
#endif // NETWORKMOD4_HP