#include <algorithm>

//Generates a uniform random integer value in [a,b)
int randInt(int a, int b) {
	while (1) {
		int myRand = std::rand();

		//Verify random variable is not at end of random distribution
		//This prevents taking mod from biasing the distribution
		if (myRand < ((RAND_MAX / (b - a)) * (b - a))) {
			return ((myRand % (b - a)) + a);
		}
	}
}

//Generates a uniform random integer value in [0,b)
int RandInt(int b) {
	return randInt(0, b);
}

//Generates a uniform random integer value in [a,b]
int closedRandInt(int a, int b) {
	return randInt(a, b + 1);
}

//Generates a uniform random integer value in [0,b]
int closedRandInt(int b) {
	return randInt(0, b + 1);
}