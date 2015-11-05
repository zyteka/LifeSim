#pragma once
#include "BasicIncludes.h"
#define ACTIONSIZE 4

//Type definitions used in the program

enum Action {SLEEP, EAT, REPRODUCE, WAKEUP};

#define ACTIONBEGIN SLEEP
#define ACTIONEND WAKEUP

#define PriorityType std::set<std::pair<float, Action> > 