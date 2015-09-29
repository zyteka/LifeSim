#pragma once
#include <iostream>
#include "BoundingBox.h"

class Anatomy
{
public:
	Anatomy();
	Anatomy(int l);
	~Anatomy();
	
private:
	BoundingBox mainPart;

};

