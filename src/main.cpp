/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** main
*/

#include "IPC.hpp"
#include "Plazza.hpp"
#include "Reception.hpp"

int main(int ac, char **av)
{
	ArrayOfCommands command;
	if (error_gestion(ac, av) == 84)
		return (FAILURE);
	Reception r(atof(av[1]), atoi(av[2]), atof(av[3]));
    r.open();
    return (0);
}