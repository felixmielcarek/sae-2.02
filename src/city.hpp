#ifndef CITY_HPP
#define CITY_HPP

#include <string>
#include <iostream>

namespace aerial_network{
    class City{
        std::string name;
        int number;
    public:
        City(std::string name,int number);
        friend std::ostream& operator<<(std::ostream& s,const City& c);
        std::string getName()const;
        int getNumber()const;
    };
} // namespace aerial_network

#endif // CITY_HPP