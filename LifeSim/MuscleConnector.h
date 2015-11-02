#pragma once
#include "BasicIncludes.h"
#include "Object.h"

class Bone;
class Joint;

class MuscleConnector :public Object
{
public:
	MuscleConnector(btDiscreteDynamicsWorld*, Bone*, Joint*, float);
	~MuscleConnector();
	
private:
	void UpdateConstraint();
	Joint* joint;
	Bone* bone;
	float radius;
	float translate;
};

