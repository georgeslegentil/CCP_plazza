/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Ingredients
*/

#include "Ingredients.hpp"
#include <iostream>

Ingredients::Ingredients()
{
    initIngredients();
    initMenu();
}

Ingredients::~Ingredients()
{

}

void Ingredients::initIngredients()
{
    ingredients.insert({DOE, 5});
    ingredients.insert({TOMATO, 5});
    ingredients.insert({GRUYERE, 5});
    ingredients.insert({HAM, 5});
    ingredients.insert({MUSHROOMS, 5});
    ingredients.insert({STEAK, 5});
    ingredients.insert({EGGPLANT, 5});
    ingredients.insert({GOATCHEESE, 5});
    ingredients.insert({CHIEFLOVE, 5});
}

void Ingredients::initMenu()
{
    std::vector<e_ingr> margarita = {DOE, TOMATO, GRUYERE};
    std::vector<e_ingr> regina = {DOE, TOMATO, GRUYERE, HAM, MUSHROOMS};
    std::vector<e_ingr> americana = {DOE, TOMATO, GRUYERE, STEAK};
    std::vector<e_ingr> fantasia = {DOE, TOMATO, EGGPLANT, GOATCHEESE, CHIEFLOVE};

    pizzaType.insert({"margarita", margarita});
    pizzaType.insert({"regina", regina});
    pizzaType.insert({"americana", americana});
    pizzaType.insert({"fantasia", fantasia});
}

bool Ingredients::isEnough(int timeAdd)
{
    e_ingr current;
    std::vector<e_ingr> needed;

    for (auto it = pizzaType.begin(); it != pizzaType.end(); ++it) {
        needed = it->second;
    }

    for (auto i : needed) {
        current = needed[i];
        if (ingredients[current] > 0) {
            ingredients[current]--;
        } else {
            restockIngredients(timeAdd);
        }
    }
    return (true);
}

void Ingredients::restockIngredients(int timeAdd)
{
    auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> ecartTimeToAdd = end - start;
    int secondToAdd = timeAdd/1000;

    while (ecartTimeToAdd.count() <= secondToAdd) {
        end = std::chrono::system_clock::now();
        ecartTimeToAdd = end - start;
    }

    for (auto it = ingredients.begin(); it != ingredients.end(); ++it) {
        it->second++;
    }
}

void Ingredients::stockStatus()
{
    for (auto it = ingredients.begin(); it != ingredients.end(); ++it) {
        std::cout << it->first << "=" << it->second << std::endl;
    }
}