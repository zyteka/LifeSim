#pragma once
#include "BasicIncludes.h"
#include "Object.h"
#include "MuscleConnector.h"

class Bone;
class Joint;

class Muscle :public Object
{
public:
	Muscle(btDiscreteDynamicsWorld* worldN, Bone* leftN, Bone* rightN, Joint* jointN, float leftLinN, float rightLinN);
	~Muscle();

	void Update(float);
	void Draw(Camera&);

private:
	void UpdateConstraint(MuscleConnector*, MuscleConnector*);
	float forceApplied;
	void ChangeForce(float);
	float maxDistance;
	bool extend;
	MuscleConnector* one;
	MuscleConnector* two;
	btSliderConstraint* conOne;
	btSliderConstraint* conTwo;
	Joint* joint;
	Bone* left;
	Bone* right;
};

