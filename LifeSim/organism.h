#pragma once

#include "BasicIncludes.h"
#include "rand.h"
#include "Anatomy.h"


class Organism
{
public:

	//Constructor and Destructor
	Organism();
	~Organism();

	//Get Organism's name
	std::string getName() const;

	//Approximate "Species" of Organism by hashing its member variables
	unsigned int getSpecies() const;

	//Compare "Species" of 2 Organisms
	bool compareSpecies(Organism other) const;

	//Attempt to Eat
	bool eat();

	//Attempt to Sleep
	bool sleep();

	//Attempt to Reproduce
	bool reproduce(Organism other);

	//Attempt to Mutate Organism
	bool mutate();

	//Determine if Organism has enough energy for specified action
	bool evalEnergy(float mult) const;

private:

	//Organism name
	std::string fName, lName;

	//Organism id number
	unsigned long int id;

	//Center of organism
	float x, y, z;

	//Organism's appendages
	std::vector<Anatomy> appendages;

	//Organism's Current Energy (Effected by food and sleep)
	unsigned int energy;

};

