#include <iostream>
//#include <string>
#include <vector>

#include "rand.h"


//Remove this once Appendage class prototyped with header file
class Appendage;

class Organism
{
public:

	//Constructor and Destructor
	Organism();
	~Organism();

	//Get Organism's name
	std::string getName() const;

	//Approximate "Species" of Organism by hashing its member variables
	int getSpecies() const;

	//Compare "Species" of 2 Organisms
	int compareSpecies(Organism other) const;

private:

	//Organism name
	std::string fName, lName;

	//Organism id number
	unsigned long int id;

	//Center of organism
	int x, y, z;

	//Organism's appendages
	std::vector<Appendage> appendages;

};