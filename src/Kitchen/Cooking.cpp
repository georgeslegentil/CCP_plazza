/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Cooking
*/

#include "Cooking.hpp"

Cooking_t::Cooking_s(const std::size_t &cookNb) : _state(), _ingredients(), _stove(cookNb, false)
{
    this->_cooking = 0;
    this->_ready = false;
    this->_pizza = "";
    this->_cookTime = 0;
    this->_timeAdd = 0;
}

void *cooking(void *obj)
{
    Cooking_t *cook(reinterpret_cast<Cooking_t *>(obj));

    cook->_state.doNotDisturb();
    while (!cook->_stove[cook->_cooking]) {
        pthread_cond_wait(&cook->_roll, cook->_state.getLock());
    }
    if (cook->_pizza == "margarita") {
        cook->_ingredients.isEnough(cook->_timeAdd);
        std::this_thread::sleep_for(std::chrono::seconds(1 * cook->_cookTime));
    }
    if (cook->_pizza == "regina") {
        cook->_ingredients.isEnough(cook->_timeAdd);
        std::this_thread::sleep_for(std::chrono::seconds(2 * cook->_cookTime));
    }
    if (cook->_pizza == "americana") {
        cook->_ingredients.isEnough(cook->_timeAdd);
        std::this_thread::sleep_for(std::chrono::seconds(2 * cook->_cookTime));
    }
    if (cook->_pizza == "fantasia") {
        cook->_ingredients.isEnough(cook->_timeAdd);
        std::this_thread::sleep_for(std::chrono::seconds(4 * cook->_cookTime));
    }
    cook->_ready = true;
    std::cout << "Your " << cook->_pizza << " is ready !" << std::endl;
    cook->_state.avaible();
    cook->_pizza = "";
    pthread_exit(NULL);

    return (NULL);
}

void *manageCooking(void * obj)
{
    Cooking_t *cook(reinterpret_cast<Cooking_t *>(obj));

    cook->_state.doNotDisturb();
    cook->_stove[cook->_cooking] = true;
    pthread_cond_signal(&cook->_roll);
    cook->_state.avaible();
    pthread_exit(NULL);

    return (NULL);
}