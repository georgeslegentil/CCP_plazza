/*
** EPITECH PROJECT, 2020
** CCP_plazza_2019
** File description:
** Busy
*/

#pragma once

#include "Plazza.hpp"
#include <pthread.h>
#include <string>

class Busy {
public:
    explicit Busy();
    Busy(pthread_mutex_t *memory);
    ~Busy();
    inline pthread_mutex_t *getLock(void) { return &_lock; }
    bool setSharedMem(pthread_mutex_t *sharedMem);
    void doNotDisturb(void);
    void avaible(void);
private:
    pthread_mutex_t _lock;
    pthread_mutex_t *_sharedMem;
    pthread_mutexattr_t _attr;
    bool _isShared;
};
