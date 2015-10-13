#pragma once

#include "BasicIncludes.h"
#include "BoundingBox.h"

class Anatomy : public Object
{
public:
	Anatomy(btDiscreteDynamicsWorld*);
	~Anatomy();

	void Load();
	void Draw(Camera& camera);
	void Update();
	//Convert Anatomy to unsigned int for use in hashing
	operator unsigned int() const;
	
private:
	BoundingBox* mainPart;

};

