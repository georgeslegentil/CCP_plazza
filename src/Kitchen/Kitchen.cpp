/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Kitchen
*/

#include "Kitchen.hpp"
#include "Cook.hpp"

Kitchen::Kitchen(CCommand c, float m, int cooks, int s) :
_m(m),
_cooks(cooks),
_s(s),
_sCommand(c)
{
}

Kitchen::~Kitchen()
{
}

void Kitchen::takecommand(const std::string &pizzaName)
{
    Cook cook(this->_cooks);
    Cooking_t CookGestion(this->_cooks);

    CookGestion._cookTime = this->_m;
    CookGestion._timeAdd = this->_s;
    CookGestion._pizza = pizzaName;
    cook.assignCook(CookGestion);
}
