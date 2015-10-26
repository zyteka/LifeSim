#pragma once
#include "BasicIncludes.h"
class Bone;
class Joint;

class Muscle
{
public:
	Muscle(btDynamicsWorld*,Bone*, Bone*, Joint*, float);
	~Muscle();

	void Update(float);

private:
	float forceApplied;
	void ChangeForce(float);
	float maxDistance;

	btDynamicsWorld* world;
	Joint* joint;
	Bone* left;
	Bone* right;
};

