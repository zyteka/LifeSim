#pragma once
#include "BasicIncludes.h"
#include "BoundingBox.h"

class Anatomy
{
public:
	Anatomy();
	Anatomy(int l);
	~Anatomy();

	//Convert Anatomy to unsigned int for use in hashing
	operator unsigned int() const;
	
private:
	BoundingBox mainPart;

};

