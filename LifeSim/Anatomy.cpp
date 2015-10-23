#include "Anatomy.h"



Anatomy::Anatomy(btDiscreteDynamicsWorld* worldN){

	world = worldN;
	
	glm::vec3 jointSize=glm::vec3(0.5f)*METER;

	glm::vec3 pos1 = glm::vec3(0.0f, 0.5f, -2.0f)*METER;
	glm::vec3 pos2 = glm::vec3(0.0f, 0.5f, 0.0f)*METER;
	glm::vec3 pos3 = glm::vec3(0.0f, 0.5f, 2.0f)*METER; 

	glm::vec3 boneSize = glm::vec3(0.75f*METER, 0.75f*METER, pos3.z - pos2.z - jointSize.x);

	glm::vec3 bonePosition = (pos1 + pos2) / 2.0f;
	glm::vec3 bonePosition1 = (pos3 + pos2) / 2.0f;

	Joint* joint2 = new Joint(world, pos2, jointSize);

	Bone* bone1 = new Bone(worldN, NULL, joint2, bonePosition, boneSize);
	Bone* bone2 = new Bone(worldN, joint2, NULL, bonePosition1, boneSize);

	bones.insert(bone1);
	joint2->AddBone(bone1);

	bones.insert(bone2);
	joint2->AddBone(bone2);

	joints.insert(joint2);
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
}
void  Anatomy::Update(){
	for (std::set<Bone*>::iterator i = bones.begin(); i != bones.end(); i++) {
		(*i)->Update();
	}
	for (std::set<Joint*>::iterator i = joints.begin(); i != joints.end(); i++) {
		(*i)->Update();
	}
}


//Convert Anatomy to unsigned int for use in hashing
Anatomy::operator unsigned int() const {
	/*
		Implement this function once Anatomy member variables are deifned
	*/

	return 0;
}