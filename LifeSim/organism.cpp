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
		fName += static_cast<char>(GetDistribution( std::uniform_int_distribution<int>(65, 90) ));
	}

	for (int i = 0; i < lNameLen; ++i) {
		lName += static_cast<char>(GetDistribution( std::uniform_int_distribution<int>(65, 90) ));
	}

	//Organism is not asleep at creation
	asleep = false;
	asleepSince = -1.0;

	//Organisms begin with energy normally distributed around 50% of their maximum
	energy = std::max(unsigned int(GetDistribution(std::normal_distribution<float>(maxEnergy() / 2, maxEnergy() / 10))), maxEnergy());

	//In case above energy distribution does not work out
	//energy = GetDistribution(std::uniform_int_distribution<int>(0, maxEnergy() ));

	age = 0.0;

	for (int i = 0; i < ACTIONSIZE; ++i){
		float priority = GetDistribution(std::normal_distribution<float>(0.5f, 0.1f));
		if (priority < 0) priority = 0;
		if (priority > 1) priority = 1;

		priorities.insert(std::make_pair(priority, static_cast<Action>(i)));
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
	//Add hashing function here

	//unsigned int seed = 487159078;
	unsigned int hashsum = 0;

	for (unsigned int i = 0; i < appendages.size(); ++i) {
		hashsum += static_cast<unsigned int>(appendages[i]);

		//Alternate casting option: Reinterpret
		//const void * p = &appendages[i];
		//const unsigned int * q = static_cast<const unsigned int *>(p);
		//hashsum += *q;
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
	//if (!evalEnergy(0.03)) return false;


	return false;
}

//Attempt to Sleep
bool Organism::sleep(float curTime) {
	//Organism is already asleep
	if (asleep) return false;
	
	//Organism is well rested, so sleep is unnecessary
	//if (energy > maxEnergy() / 2) return false;

	asleepSince = curTime;
	asleep = true;

	return true;
}

//Attempt to Awaken from Sleep
bool Organism::wakeUp(float curTime) {
	//Organism is Already Awake
	if (!asleep) return false;

	//Organism has not yet rested enough
	//if (energy < 9 * maxEnergy() / 10) return false;

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
	//Organisms of different species cannot reproduce
	if (!compareSpecies(other)) {
		return false;
	}

	//Organism needs enough energy to reproduce
	/*if (!evalEnergy(0.85)) {
		return false;
	}*/

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

//Preform Top Priority
bool Organism::act(Organism Other) {

	//Get Action with top priority
	PriorityType::reverse_iterator itr = priorities.rbegin();

	//Assign Action associated with top priority
	Action a = itr->second;

	//Capture success of attempted Action
	bool success;

	//How Organism should act based on top priority
	switch (a) {
		case SLEEP		:	success = sleep(time(NULL));			break; 
		case EAT		:	success = eat();						break;
		case REPRODUCE	:	success = reproduce(Other);				break;
		case WAKEUP		:	success = wakeUp(time(NULL));			break; 
		default			:	std::cerr << a << std::endl; exit(1);	break;
	}

	//If Action is successful, readjust its priority
	if (success) {

		//Get Action With lowest priority
		PriorityType::iterator itr2 = priorities.begin();

		//Set new priority to half of the current lowest priority
		std::pair<float, Action> tmp = std::make_pair((itr2->first) / 2, itr->second);

		//Erase previous top priority Action from set of Actions
		priorities.erase(std::next(itr).base());

		//Reinsert Action with its new priority into set of Actions
		priorities.insert(tmp);

		//Rebalance the Organism's Priorities to prevent
		//convergence to zero
		balanceEnergy();
	}

	return success;
}

//Rebalance the Organism's Priorities
void Organism::balanceEnergy() {

	//Get initial bounds of distribution
	float a = priorities.begin()->first;
	float b = priorities.rbegin()->first;

	//New bounds for normalization
	float c = 0.0; //GetDistribution(std::normal_distribution<float>(0.25f, 0.05f));
	float d = 1.0; //GetDistribution(std::normal_distribution<float>(0.75f, 0.05f));

	for (PriorityType::iterator itr = priorities.begin(); itr != priorities.end();) {

		//Get current value and transform to new value
		float y = itr->first;
		float x = (c / a) + ((d - c) / (b - a)) * (y - a);

		//Correct for floating point arithmetic errors
		x = std::min(x, 1.0f);
		x = std::max(x, 0.0f);

		//Create pair using new value
		std::pair<float, Action> tmp = std::make_pair(y, itr->second);

		//Store temporary iterator before erasing old pair
		PriorityType::iterator itr2 = itr;
		itr2++;

		//Erase old pair and insert the new one
		priorities.erase(itr);
		priorities.insert(tmp);

		//Copy the temporary iterator back to the main one
		itr = itr2;
	}
	
}