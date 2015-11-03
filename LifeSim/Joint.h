#pragma once

#include "BasicIncludes.h"
#include "BoundingBox.h"


class Bone;

class Joint : public Object
{
public:
	Joint(btDiscreteDynamicsWorld*,glm::vec3,glm::vec3,float);
	~Joint();

	void Update(double dt);

	void AddBone(Bone*);

	glm::vec3 localAxisofRotation;
private:

	float radius;
	std::set<Bone*> bones;
};

