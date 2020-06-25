/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** IPC
*/

#include "IPC.hpp"

IPC::IPC(int m, int c, int s)
{
    this->_multiplier = m;
    this->_cooks = c;
    this->_refresh = s;
}

void IPC::link(Busy &busy)
{
    int handle = shm_open("/shm", O_CREAT | O_RDWR, 0777);
    ftruncate(handle, sizeof(int) * 2048);
    _mem = (char *)mmap(0, sizeof(int) * 2048, PROT_READ | PROT_WRITE, MAP_SHARED, handle, 0);
    if (handle) {
        std::cout << "Kitchen create" << std::endl;
        busy.setSharedMem((pthread_mutex_t *)_mem);
        _sMem = (int *)(_mem + sizeof(pthread_mutex_t));
        *_sMem = 0;
    } else
        std::cerr << "Kitchen has not been created" << std::endl;
}

void IPC::unlink()
{
    munmap((void *)&this->_mem, sizeof(int) * 2048);
    shm_unlink("/shm");
}