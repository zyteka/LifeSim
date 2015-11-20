#include "Anatomy.h"



Anatomy::Anatomy(btDiscreteDynamicsWorld* worldN, Terrain* terrainN){

	world = worldN;
	terrain = terrainN;
}

void Anatomy::CreateOrganism(Anatomy*){
	

}
void Anatomy::CreateBaseOrganism(glm::vec3 basePos){

	float jointRadius = 0.25f*METER;
	float capRadius = jointRadius;

	float x1 = 0.0f*METER + basePos.x;
	float y1 = -2.0f*METER + basePos.z;

	float x2 = 0.0f*METER + basePos.x;
	float y2 = 0.0f*METER + basePos.z;

	float x3 = 0.0f*METER + basePos.x;
	float y3 = 2.0f*METER + basePos.z;

	glm::vec3 pos1 = glm::vec3(x1, terrain->GetHeight(x1, y1) + capRadius, y1);
	glm::vec3 pos2 = glm::vec3(x2, terrain->GetHeight(x2, y2) + capRadius, y2);
	glm::vec3 pos3 = glm::vec3(x3, terrain->GetHeight(x3, y3) + capRadius, y3);

	float max = glm::max(glm::max(pos1.y, pos2.y), pos3.y);

	pos1.y = max;
	pos2.y = max;
	pos3.y = max;

	float boneSize = pos3.z - pos2.z - (jointRadius * 2) - (jointRadius*0.05f);

	glm::vec3 bonePosition = (pos1 + pos2) / 2.0f;
	glm::vec3 bonePosition1 = (pos3 + pos2) / 2.0f;

	Joint* joint2 = new Joint(world, pos2, glm::vec3(1.0f, 0.0f, 0.0f), jointRadius);

	Bone* bone1 = new Bone(world, joint2, NULL, bonePosition, capRadius, boneSize);
	Bone* bone2 = new Bone(world, joint2, NULL, bonePosition1, capRadius, boneSize);

	bones.insert(bone1);
	joint2->AddBone(bone1);

	bones.insert(bone2);
	joint2->AddBone(bone2);

	joints.insert(joint2);

	Muscle* muscle1 = new Muscle(world, bone1, bone2, joint2, 1.0f, 1.0f);
	muscles.insert(muscle1);

}

Anatomy::~Anatomy(){

	bones.clear();
	joints.clear();
}

void Anatomy::Load(){

}
void  Anatomy::Draw(Camera& camera){
	for (std::set<Bone*>::iterator i = bones.begin(); i != bones.end(); i++) {
		(*i)->Draw(camera);
	}
	for (std::set<Joint*>::iterator i = joints.begin(); i != joints.end(); i++) {
		(*i)->Draw(camera);
	}
	for (std::set<Muscle*>::iterator i = muscles.begin(); i != muscles.end(); i++) {
		(*i)->Draw(camera);
	}
}
void  Anatomy::Update(double dt){
	for (std::set<Bone*>::iterator i = bones.begin(); i != bones.end(); i++) {
		(*i)->Update(dt);
	}
	for (std::set<Joint*>::iterator i = joints.begin(); i != joints.end(); i++) {
		(*i)->Update(dt);
	}

	for (std::set<Muscle*>::iterator i = muscles.begin(); i != muscles.end(); i++) {
		(*i)->Update(dt);
	}
}
void  Anatomy::UpdatePosition(){
	for (std::set<Bone*>::iterator i = bones.begin(); i != bones.end(); i++) {
		(*i)->UpdatePosition();
	}
	for (std::set<Joint*>::iterator i = joints.begin(); i != joints.end(); i++) {
		(*i)->UpdatePosition();
	}
	for (std::set<Muscle*>::iterator i = muscles.begin(); i != muscles.end(); i++) {
		(*i)->UpdatePosition();
	}
}

//Convert Anatomy to unsigned int for use in hashing
Anatomy::operator unsigned int() const {
	/*
		Implement this function once Anatomy member variables are deifned
	*/

	return 0;
}