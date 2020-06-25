/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** IPC
*/

#pragma once

#include "Plazza.hpp"
#include "Busy.hpp"

class IPC {
    public:
         IPC(int, int, int);
        ~IPC() = default;

        inline int *getSmemory(void) const { return _sMem; }
        inline void setSmemory(int name, int size)
        {
          _sMem[0] = name;
          _sMem[1] = size;
        }
        void link(Busy &busy);
        void unlink();

    protected:
    private:
        int _multiplier;
        int _cooks;
        int _refresh;
        char *_mem;
        int *_sMem;
};
