#ifndef NETWORKMOD4_HPP
#define NETWORKMOD4_HPP
#include "network.hpp"

namespace aerial_network{
    class NetworkMod4:public Network{
        public:
            NetworkMod4()=default;
            ~NetworkMod4();
            std::vector<std::vector<bool>> matrix;
            // Finir ces fonctions permettant d'ajouter pour chaque vector "BOOL" les correspondances de chaques villes.
            void addCities()override;
            void place();
    };
}
#endif // NETWORKMOD4_HP