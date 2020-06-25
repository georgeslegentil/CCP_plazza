/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Cook
*/

#include <iostream>
#include <algorithm>
#include "Cook.hpp"

Cook::Cook(const std::size_t &cookNb) : _thread(cookNb, 0)
{
    this->_threadControl = 0;
}

bool Cook::assignCook(Cooking_t &Cooking)
{
    Cooking._ready = false;
    pthread_create(&_thread[Cooking._cooking], NULL, &cooking, &Cooking);
    pthread_create(&_threadControl, NULL, &manageCooking, &Cooking);
    pthread_join(_thread[Cooking._cooking], NULL);
    pthread_join(_threadControl, NULL);
    Cooking._cooking++;
    return (true);
}
