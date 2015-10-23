#pragma once

#include "BasicIncludes.h"
#include "BoundingBox.h"

class Joint;

class Bone : public Object
{
public:
	Bone(btDiscreteDynamicsWorld*,Joint *,Joint*,glm::vec3,float,float);
	~Bone();

	glm::vec3 GetPosition();
private:
	float radius;
	float height;
	Joint* endLeft;
	Joint* endRight;

};

