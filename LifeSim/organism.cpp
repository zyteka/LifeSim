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

	asleep = false;
	asleepSince = -1.0;

	energy = GetDistribution(std::normal_distribution<float>(maxEnergy() / 2, maxEnergy() / 10));
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
	//Add hashing function here

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
	unsigned int Species = getSpecies();

	//Add comparison of hash values here
	if ((std::max(Species, otherSpecies) - 
		std::min(Species, otherSpecies)) > DELTA) {
		return false;
	}

	else {
		return true;
	}
}

//Attempt to eat given resource
//Note: Add ersource parameter to function
bool Organism::eat() {
	//Determine if Organism has enough energy to digest food
	//Note: May want to change this multiplier to be variable 
	//based on the Anatomy of the Organism
	if (!evalEnergy(0.03)) return false;


	return false;
}

//Attempt to Sleep
bool Organism::sleep(float curTime) {
	//Organism is already asleep
	if (asleep) return false;
	
	//Organism is well rested, so sleep is unnecessary
	if (energy > maxEnergy() / 2) return false;

	asleepSince = curTime;
	asleep = true;

	return true;
}

//Attempt to Awaken from Sleep
bool Organism::wakeUp(float curTime) {
	//Organism is Already Awake
	if (!asleep) return false;

	//Organism has not yet rested enough
	if (energy < 9 * maxEnergy() / 10) return false;

	//Note: Tweak Sleep Energy Gain multiplier
	energy += (curTime - asleepSince) * 0.05;

	//Adjust energy to maximum energy for Organism
	energy = std::max(energy, maxEnergy());

	asleep = false;
	asleepSince = -1.0;

	return true;
}

//Attempt to reproduce with another Organism
bool Organism::reproduce(Organism other) {
	if (!compareSpecies(other)) {
		return false;
	}

	if (!evalEnergy(0.85)) {
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
//Assumes mult > 0
bool Organism::evalEnergy(float mult) const {

	//Minimum required energy to execute action
	//Note: Update this as function of getSpecies() later
	float minEnergy = 150 * mult;

	return ((energy > minEnergy - EPSILON) && energy > 0);
}

//Maximum Energy the Organism may store
unsigned int Organism::maxEnergy() const {
	//Note: may want to update/tweak this in the future (add multiplier)
	return getSpecies();
}