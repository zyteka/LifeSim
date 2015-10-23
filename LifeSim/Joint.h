#pragma once

#include "BasicIncludes.h"
#include "BoundingBox.h"


class Bone;

class Joint : public Object
{
public:
	Joint(btDiscreteDynamicsWorld*,glm::vec3,glm::vec3);
	~Joint();

	void Update();

	void AddBone(Bone*);
private:
	glm::vec3 boxSize;
	std::set<Bone*> bones;
};

