#pragma once

#include "BasicIncludes.h"
#include "BoundingBox.h"

class Joint;

class Bone
{
public:
	Bone(btDiscreteDynamicsWorld*,Joint *,Joint*,glm::vec3,glm::vec3);
	~Bone();

	void Load();
	void Draw(Camera& camera);
	void Update();
private:
	Joint* endLeft;
	Joint* endRight;

	BoundingBox* bodyPart;
};

