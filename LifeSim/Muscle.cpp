#include "Muscle.h"
#include "Bone.h"
#include "Joint.h"

Muscle::Muscle(btDynamicsWorld* worldN, Bone* leftN, Bone* rightN, Joint* jointN,float maxDist)
{
	world = worldN;
	left = leftN;
	right = rightN;
	joint = jointN;
	maxDistance = maxDist;


	//world->addConstraint(con, true);
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

	//glm::vec3 relativeJointNormal = glm::normalize(glm::vec3(joint->GetMatrix()*glm::vec4(jointNormal, 1.0f)) - joint->GetPosition());

	//btVector3 pivotInJoint = btVector3(0.0f, 0.0f, 0.0f);

	//btVector3 pivotInLeft = left->GetRigidBody() ? left->GetRigidBody()->getCenterOfMassTransform().inverse()(joint->GetRigidBody()->getCenterOfMassTransform()(pivotInJoint)) : pivotInJoint;
	//btVector3 pivotInRight = right->GetRigidBody() ? right->GetRigidBody()->getCenterOfMassTransform().inverse()(joint->GetRigidBody()->getCenterOfMassTransform()(pivotInJoint)) : pivotInJoint;

	//btVector3 targetLeft = btVector3(relativeJointNormal.z, relativeJointNormal.y, relativeJointNormal.z)*left->height -pivotInLeft ;

	//pivotInLeft = -pivotInLeft;

	//btVector3 targetRight =  btVector3(relativeJointNormal.z, relativeJointNormal.y, relativeJointNormal.z)*right->height-pivotInRight ;

	//pivotInRight = -pivotInRight;

	//btVector3 forceLeft = (targetLeft- pivotInLeft)*NEWTON*expand*10.0f;

	//btVector3 forceRight = (targetRight - pivotInRight)*NEWTON*expand*10.0f;


	//glm::vec3 leftVec = (glm::vec3(left->GetMatrix()*glm::vec4(glm::vec3(0.0f,0.0f,-1.0f), 1.0f))-left->GetPosition())*NEWTON*100.0f*expand;
	//btVector3 leftV = btVector3(leftVec.x, leftVec.y, leftVec.z);

	////left->GetRigidBody()->applyForce(forceLeft, pivotInLeft);


	//glm::vec3 rightVec = (glm::vec3(right->GetMatrix()*glm::vec4(glm::vec3(0.0f, 0.0f, -1.0f), 1.0f)) - right->GetPosition())*NEWTON*100.0f*expand;
	//btVector3 rightV = btVector3(rightVec.x, rightVec.y, rightVec.z);

	////right->GetRigidBody()->applyForce(forceRight, pivotInRight);
}

Muscle::~Muscle()
{


}
