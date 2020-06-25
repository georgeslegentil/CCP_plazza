/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Plazza
*/

#pragma once

#include <iostream>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <algorithm>
#include <fcntl.h>


#define END_OF_STRING '\0'

enum PizzaType
{
    Regina = 1,
    Margarita = 2,
    Americana = 4,
    Fantasia = 8
};

enum PizzaSize
{
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16
};

enum return_value {
	SUCCESS = 0,
	FAILURE = 84,
};

int error_gestion(int ac, char **av);
std::pair <std::string, int> prompt();