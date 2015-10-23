#pragma once

#include "BasicIncludes.h"
#include "BoundingBox.h"

class Joint;

class Bone : public Object
{
public:
	Bone(btDiscreteDynamicsWorld*,Joint *,Joint*,glm::vec3,glm::vec3);
	~Bone();

	glm::vec3 GetPosition();
private:

	Joint* endLeft;
	Joint* endRight;

};

