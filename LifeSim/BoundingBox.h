#pragma once

#include "Object.h"

class BoundingBox : public Object
{
public:
	BoundingBox(btDiscreteDynamicsWorld*,glm::vec3,glm::vec3);
	~BoundingBox();


	void Update();


	glm::mat4 GetPosition();
	void SetPosition(glm::vec3);

private:

};

