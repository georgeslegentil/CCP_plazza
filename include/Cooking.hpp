/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Cooking
*/

#pragma once

#include <vector>
#include <thread>
#include "Busy.hpp"
#include "Ingredients.hpp"

typedef struct Cooking_s {
    explicit Cooking_s(const std::size_t &);

    Busy _state;
    Ingredients _ingredients;

    std::vector<bool> _stove;
    std::size_t _cooking;
    bool _ready;

    std::string _pizza;
    int _cookTime;
    int _timeAdd;

    pthread_cond_t _roll;
} Cooking_t;

void *cooking(void *obj);
void *manageCooking(void *obj);