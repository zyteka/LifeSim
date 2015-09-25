#pragma once

#include <random>
#include <chrono>

std::uniform_real_distribution<float> distribution01(0.0f, 1.0f);
std::mt19937 generator;
void InitRandom(){
	generator = std::mt19937(std::chrono::high_resolution_clock::now().time_since_epoch().count());
}
void GetDistribution(std::uniform_real_distribution<float> distro){
	distro(generator);
}