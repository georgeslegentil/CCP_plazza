/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Kitchen
*/

#pragma once

#include <iostream>
#include <vector>
#include "Command.hpp"

class Kitchen {
    public:
        Kitchen();
        void AddIngredient();
        void initTime();
        void initKitchen(int , int, int);
        void calculEcartTime();
        void _stopTime();
        void initIngredient();
        void takecommand(const std::string &pizzaName);
        Kitchen(CCommand, float, int, int);
        ~Kitchen();

    protected:
    bool KitchenOpen = true;
    int tomato;
    int gruyere;
    int ham;
    int mushroom;
    int steak;
    int eggplant;
    int goatCheese;
    int nbCookers;
    int pizzaMax;
    int pizzaMake = 0;
    std::vector<bool> tabCooker;
    private:
    time_t startTimeToAdd, stopTimeToAdd, ecartTimeToAdd;
    time_t startTime, stopTime, ecartTime;
    private:
        float _m;
        int _cooks;
        int _s;
        CCommand _sCommand;
};