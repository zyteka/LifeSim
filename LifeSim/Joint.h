#pragma once

#include "BasicIncludes.h"
#include "BoundingBox.h"


class Bone;

class Joint : public Object
{
public:
	Joint(btDiscreteDynamicsWorld*,glm::vec3,float);
	~Joint();

	void Update();

	void AddBone(Bone*);
private:
	float radius;
	std::set<Bone*> bones;
};

