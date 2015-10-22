#pragma once

#include "BasicIncludes.h"
#include "BoundingBox.h"


class Bone;

class Joint
{
public:
	Joint(btDiscreteDynamicsWorld*,glm::vec3,glm::vec3);
	~Joint();

	void Load();
	void Draw(Camera& camera);
	void Update();

	void AddBone(Bone*);
private:

	glm::vec3 position;
	std::set<Bone*> bones;
	BoundingBox* bodyPart;
};

