/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Ingredients
*/

#pragma once

#include <map>
#include <vector>
#include <chrono>
#include "Plazza.hpp"

enum e_ingr {
    DOE,
    TOMATO,
    GRUYERE,
    HAM,
    MUSHROOMS,
    STEAK,
    EGGPLANT,
    GOATCHEESE,
    CHIEFLOVE
};

class Ingredients {
    public:
        Ingredients();
        ~Ingredients();
        void initIngredients();
        void initMenu();
        bool isEnough(int refresh);
        void restockIngredients(int timeAdd);
        void stockStatus();

    protected:
    private:
        std::map <e_ingr, int> ingredients;
        std::map <std::string, std::vector<e_ingr>> pizzaType;

};
