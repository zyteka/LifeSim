#pragma once

#include "BasicIncludes.h"
#include "Bone.h"
#include "Joint.h"
#include "Muscle.h"

class Anatomy : public Object
{
public:
	Anatomy(btDiscreteDynamicsWorld*, glm::vec3);
	~Anatomy();

	void Load();
	void Draw(Camera& camera);
	void Update(double dt);
	void UpdatePosition();
	//Convert Anatomy to unsigned int for use in hashing
	operator unsigned int() const;
	
private:
	std::set<Bone*> bones;
	std::set<Joint*> joints;
	std::set<Muscle*> muscles;
};

