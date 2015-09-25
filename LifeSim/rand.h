#pragma once

#include <random>
#include <chrono>

std::mt19937 generator;
void InitRandom(){
	generator = std::mt19937(std::chrono::high_resolution_clock::now().time_since_epoch().count());
}
float GetDistribution(std::uniform_real_distribution<float> distro){
	return distro(generator);
}
int GetDistribution(std::uniform_int_distribution<int> distro) {
	return distro(generator);
}