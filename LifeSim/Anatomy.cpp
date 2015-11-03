#include "Anatomy.h"



Anatomy::Anatomy(btDiscreteDynamicsWorld* worldN, glm::vec3 basePos){

	world = worldN;
	
	float jointRadius = 0.25f*METER;
	float capRadius = jointRadius;
	glm::vec3 pos1 = glm::vec3(0.0f*METER, capRadius, -2.0f*METER) + basePos;
	glm::vec3 pos2 = glm::vec3(0.0f*METER, capRadius, 0.0f*METER) + basePos;
	glm::vec3 pos3 = glm::vec3(0.0f*METER, capRadius, 2.0f*METER) + basePos;

	float boneSize = pos3.z - pos2.z - (jointRadius * 2) - (jointRadius*0.05f);

	glm::vec3 bonePosition = (pos1 + pos2) / 2.0f;
	glm::vec3 bonePosition1 = (pos3 + pos2) / 2.0f;

	Joint* joint2 = new Joint(world, pos2, glm::vec3(1.0f,0.0f,0.0f),jointRadius);

	Bone* bone1 = new Bone(worldN, joint2,NULL , bonePosition, capRadius, boneSize);
	Bone* bone2 = new Bone(worldN, joint2, NULL, bonePosition1, capRadius, boneSize);

	bones.insert(bone1);
	joint2->AddBone(bone1);

	bones.insert(bone2);
	joint2->AddBone(bone2);

	joints.insert(joint2);

	Muscle* muscle1 = new Muscle(worldN,bone1, bone2, joint2, 1.0f,1.0f);
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