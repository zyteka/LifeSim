#pragma once

#include "BasicIncludes.h"
#include "Bone.h"
#include "Joint.h"
#include "Muscle.h"
#include "Terrain.h"

class Anatomy : public Object
{
public:
	Anatomy(btDiscreteDynamicsWorld*, Terrain*);
	~Anatomy();

	void Load();
	void Draw(Camera& camera);
	void Update(double dt);
	void UpdatePosition();

	void CreateOrganism(Anatomy*);
	void CreateBaseOrganism(glm::vec3);

	//Convert Anatomy to unsigned int for use in hashing
	operator unsigned int() const;
	
private:
	Terrain* terrain;
	std::set<Bone*> bones;
	std::set<Joint*> joints;
	std::set<Muscle*> muscles;
};

