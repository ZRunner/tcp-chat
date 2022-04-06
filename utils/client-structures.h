#pragma once

#include <stdlib.h>

#ifndef bool
    #define bool unsigned int
    #define true 1
    #define false 0
#endif

typedef struct {
    long type; // 1
    char username[100];
    char message[100];
} messageSignal;

typedef struct {
    long type; // 2
    char username[100];
    bool is_join;
} moveSignal;

typedef struct {
    long type; // 3
    int signal; // 0: STOP, 1: connected, 2: disconnected
} stopSignal;
