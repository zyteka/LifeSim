#pragma once
#include "BasicIncludes.h"

//Type definitions used in the program

enum Action {SLEEP, EAT, REPRODUCE, WAKEUP};

#define ACTIONSIZE 4
#define ACTIONBEGIN SLEEP
#define ACTIONEND WAKEUP

#define PriorityType std::set<std::pair<float, Action> > 
