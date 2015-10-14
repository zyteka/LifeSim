#pragma once

#include <random>
#include <chrono>
#include "BasicIncludes.h"


float GetDistribution(std::uniform_real_distribution<float> distro);
int GetDistribution(std::uniform_int_distribution<int> distro);
float GetDistribution(std::normal_distribution<float> distro);