#include "Organism.h"

//Constructor
Organism::Organism()
{
	//Keep track of id numbers
	static unsigned long int next_id = 0;
	id = next_id;
	++next_id;

	//First and Last name lengths
	int fNameLen = GetDistribution(std::uniform_int_distribution<int>(3, 8));
	int lNameLen = GetDistribution(std::uniform_int_distribution<int>(4, 12));

	//Generate name
	for (int i = 0; i < fNameLen; ++i) {
		fName += static_cast<char>(GetDistribution(std::uniform_int_distribution<int>(65, 90)));
	}

	for (int i = 0; i < lNameLen; ++i) {
		lName += static_cast<char>(GetDistribution(std::uniform_int_distribution<int>(65, 90)));
	}
}

//Destructor
Organism::~Organism()
{
}

//Get Organism's name
std::string Organism::getName() const {
	return fName + ' ' + lName;
}

//Approximate "Species" of Organism by hashing its member variables
unsigned int Organism::getSpecies() const {
	//Add hasing function here

	//unsigned int seed = 487159078;
	unsigned int hashsum = 0;

	for (unsigned int i = 0; i < appendages.size(); ++i) {
		hashsum += static_cast<unsigned int>(appendages[i]);
	}

	return 0;
}

//Compare "Species" of 2 Organisms
bool Organism::compareSpecies(Organism other) const {
	unsigned int otherSpecies = other.getSpecies();

	//Difference threshold within seperating "species"
	unsigned int delta = 1000;

	//Add comparison of hash values here
	if ((std::max(getSpecies(), otherSpecies) - 
		std::min(getSpecies(), otherSpecies)) > delta) {
		return false;
	}

	else {
		return true;
	}
}

bool Organism::eat()
{
	return false;
}

bool Organism::sleep()
{
	return false;
}

//Attempt to reproduce with another Organism
bool Organism::reproduce(Organism other)
{
	if (!compareSpecies(other)) {
		return false;
	}

	if (!evalEnergy(1)) {
		return false;
	}

	/*
		Insert reproduction code here
	*/

	return true;
}

bool Organism::mutate() {
	return false;
}

//Determine if Organism has enough energy for specified action
bool Organism::evalEnergy(float mult) const {

	//Minimum required energy to execute action
	//Note: Update this as function of getSpecies() later
	float minEnergy = 150 * mult;

	//Epsilon for floating point comparison
	float epsilon = 0.0001;

	return ((energy > minEnergy - epsilon) && energy > 0);
}