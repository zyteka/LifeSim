#include <iostream>
#include "rand.h"
#include "BasicIncludes.h"
#include <random>
#include <chrono>

void Update(double);
void Draw();

int main(){

	//Comments
	//#define Connor GOD 
	//More Comments

	std::cout << "Hello World" << std::endl;

	std::mt19937 mtrand(std::chrono::system_clock::now());
	

	return 0;
}
