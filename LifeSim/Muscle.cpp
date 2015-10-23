#include "Muscle.h"
#include "Bone.h"
#include "Joint.h"

Muscle::Muscle( Bone* leftN, Bone* rightN, Joint* jointN,float leftRelN,float rightRelN,float maxForceN)
{
	left = leftN;
	right = rightN;
	joint = jointN;
	leftRel = leftRelN;
	rightRel = rightRelN;
	maxForce = maxForceN;
}

void Muscle::Update(float expand){

	glm::vec3 leftPos  = left->GetPosition();
	glm::vec3 rightPos = right->GetPosition();
	glm::vec3 jointPos = joint->GetPosition();

	left->GetRigidBody()->applyForce(btVector3(0.0f,0.0f,0.0f),btVector3(0.0f,0.0f,0.0f));



	right->GetRigidBody()->applyForce(btVector3(0.0f, 0.0f, 0.0f), btVector3(0.0f, 0.0f, 0.0f));
}

Muscle::~Muscle()
{


}
