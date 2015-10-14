#include "Rand.h"

std::mt19937 generator = std::mt19937(uint(std::chrono::high_resolution_clock::now().time_since_epoch().count()));

float GetDistribution(std::uniform_real_distribution<float> distro) {
		
	return distro(generator);
}

int GetDistribution(std::uniform_int_distribution<int> distro) {
	return distro(generator);
}

int GetDistribution(std::normal_distribution<int> distro) {
	return distro(generator);
}