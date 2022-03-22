#ifndef NETWORKMOD4_HPP
#define NETWORKMOD4_HPP
#include "network.hpp"
#include "city.hpp"
namespace aerial_network{
    class NetworkMod4:public Network{
        protected:
            std::vector<std::vector<bool>> matrix;
        public:
            NetworkMod4();
            ~NetworkMod4();            
            /* Finir ces fonctions permettant d'ajouter pour chaque vector "BOOL" les correspondances de chaques villes.
            void addCity()override;
            void place();
            
            */
    };
};
#endif // NETWORKMOD4_HP