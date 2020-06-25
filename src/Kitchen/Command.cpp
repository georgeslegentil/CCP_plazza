/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Command
*/

#include "Command.hpp"


CCommand::CCommand(std::string t, std::string s)
{
    this->_pizzaProperties.first = t;
    this->_pizzaProperties.second = s;
}

CCommand::~CCommand()
{
}


