#include "organism.h"

//Constructor
Organism::Organism()
{
	//Keep track of id numbers
	static unsigned long int next_id = 0;
	id = next_id;
	++next_id;

	//First and Las tname lengths
	int fNameLen = closedRandInt(3, 8);
	int lNameLen = closedRandInt(4, 12);

	for (int i = 0; i < fNameLen; ++i) {
		fName += static_cast<char>(closedRandInt(1, 26));
	}

	for (int i = 0; i < lNameLen; ++i) {
		lName += static_cast<char>(closedRandInt(1, 26));
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
int Organism::getSpecies() const {
	//Add hasing function here

	return 0;
}

//Compare "Species" of 2 Organisms
int Organism::compareSpecies(Organism other) const {
	int otherSpecies = other.getSpecies();

	//Add comparison of hash values here

	return 0;
}