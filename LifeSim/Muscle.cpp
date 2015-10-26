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

void Muscle::ChangeForce(float deltaX){
	forceApplied += deltaX;
	if (forceApplied>1.0f){
		forceApplied = 1.0f;
	}
	if (forceApplied<0.0f){
		forceApplied = 0.0f;
	}
}

void Muscle::Update(float expand){

	glm::vec3 leftPos  = left->GetPosition();
	glm::vec3 rightPos = right->GetPosition();
	glm::vec3 jointPos = joint->GetPosition();

	ChangeForce(expand);

	glm::vec3 leftVec = glm::vec3(glm::vec4((rightPos - leftPos), 1.0f)*left->GetMatrix())*NEWTON*expand;


	left->GetRigidBody()->applyForce(btVector3(0,10,0)*NEWTON, btVector3(0.0f, 0.0f, 0.0f));



	glm::vec3 rightVec = glm::normalize(leftPos-rightPos);


	right->GetRigidBody()->applyForce(btVector3(0,10,0)*NEWTON, btVector3(0, 0.0f, 0.0f));
}

Muscle::~Muscle()
{


}
