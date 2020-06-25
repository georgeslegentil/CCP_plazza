/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Command
*/

#pragma once

#include "Plazza.hpp"
#include "Ingredients.hpp"

class CCommand {
    private:
        std::map<std::string, int> _typeMap;
        std::map<std::string, int> _sizeMap;
        std::pair<int, int> _pizzaEnumProperties;
        std::pair<std::string, std::string> _pizzaProperties;
        std::map<PizzaType, std::vector<e_ingr>> _typePizzas;

    public:
        CCommand(std::string, std::string);
        ~CCommand();
        std::pair<std::string, std::string> getPizzaProperties() const { return this->_pizzaProperties; };
        std::pair<int, int> getCommandProperties() const { return this->_pizzaEnumProperties; };
};
