#pragma once
#include "BasicIncludes.h"

class Bone;
class Joint;

class Muscle
{
public:
	Muscle(Bone*,Bone* ,Joint*,float,float,float);
	~Muscle();

	void Update(float);

private:
	float forceApplied;
	void ChangeForce(float);
	float maxForce;

	Joint* joint;
	Bone* left;
	float leftRel;
	Bone* right;
	float rightRel;
};

