/**
 *\file exception.cpp
 *\brief déclaration et code des excpetions possibles dans l'application 
 *\author MIELCAREK Félix & DE LA FUENTE Axel
 */

#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <iostream>
#include <string>

namespace aerial_network{
    //Axel
    class SamePlaceException : public std::exception{
        std::string msg{"Vous êtes déjà sur place, inutile de prendre un vol !\n"};
    public:
        SamePlaceException() {std::cout << msg;}
        const char *what() const noexcept override {return msg.c_str();}
    };

    //Félix
    class NonExistentCityException: public std::exception{
        std::string msg{"La ville que vous avez sélectionné n'existe pas !\n"};
    public:
        NonExistentCityException() {std::cout << msg;}
        const char *what() const noexcept override {return msg.c_str();}
    };

    //Félix
    class NonExistentPathException: public std::exception{
        std::string c1;
        std::string c2;
        std::string msg{"Aucun chemin n'existe pour relier "+c1+" et "+c2+" !\n"};
    public:
        NonExistentPathException(std::string c1, std::string c2)
            :c1{c1},c2{c2}{std::cout << msg;}
        const char *what() const noexcept override {return msg.c_str();}
    };

    class NoCityException: public std::exception{
        std::string msg{"Votre réseau aérien est vide (il n'y a aucune ville dedans) !\n"};
    public:
        NoCityException() {std::cout << msg;}
        const char *what() const noexcept override {return msg.c_str();}
    };

    

} // namespace aerial_network

#endif // EXCPETION_HPP