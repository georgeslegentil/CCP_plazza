/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Cook
*/

#pragma once

#include <pthread.h>
#include <vector>
#include "Cooking.hpp"

class Cook {
public:
    explicit Cook(const std::size_t &cookNb);
    ~Cook() = default;
    bool assignCook(Cooking_t &hCook);
private:
    std::vector<pthread_t> _thread;
    pthread_t _threadControl;
};