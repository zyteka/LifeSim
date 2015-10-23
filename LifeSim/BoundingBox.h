#pragma once

#include "Object.h"

class BoundingBox : public Object
{
public:
	BoundingBox(btDiscreteDynamicsWorld*,glm::vec3,glm::vec3);
	~BoundingBox();


	glm::mat4 GetPosition();
	btRigidBody* GetRigidBody();

	void SetPosition(glm::vec3);

private:

};

