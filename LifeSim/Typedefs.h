#pragma once
#include "BasicIncludes.h"
#define ENUMSIZE 4

//Type definitions used in the program

enum Action {SLEEP, EAT, REPRODUCE, WAKEUP};

#define ENUMBEGIN SLEEP
#define ENUMEND WAKEUP

#define PriorityType std::set<std::pair<float, Action> > 