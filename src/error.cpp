/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** error
*/

#include "Plazza.hpp"

int check_args(char *av)
{
	if (atof(av) < 0)
		return (FAILURE);
	for (size_t y = 0; av[y]; y++)
    	if (!isdigit(av[y]) && av[y] != '.')
    		return (FAILURE);
	return (0);
}

int isfloat(char *av)
{
	for (size_t y = 0; av[y]; y++)
		if (av[y] == '.')
			return (FAILURE);
	return (0);
}

int error_gestion(int ac, char **av)
{
	if (ac != 4) {
		std::cerr << "Usage: ./plazza [multiplier] [cooks_per_kictchen] [replace_ingredients]\n";
		return (FAILURE);
	}
	for (size_t y = 1; av[y]; y++) {
		if (check_args(av[y]) == FAILURE) {
			std::cerr << "Error: wrong format ! Use ./plazza -h\n";
			return (FAILURE);
		}
		if (y == 2 || y == 3)
			if (isfloat(av[y]) == FAILURE)
				return (FAILURE);
	}
	return (0);
}
