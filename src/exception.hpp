#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <iostream>
#include <string>

namespace aerial_network{
    class Exception : public std::exception{
        std::string msg{"Error : the wagon is mooving\n"};
    public:
        Exception() {std::cout << msg;}
        const char *what() const noexcept override {return msg.c_str();}
    };

    

} // namespace aerial_network

#endif // EXCPETION_HPP