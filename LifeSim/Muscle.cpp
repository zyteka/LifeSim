#include "Muscle.h"
#include "Bone.h"
#include "Joint.h"

Muscle::Muscle(btDiscreteDynamicsWorld* worldN, Bone* leftN, Bone* rightN, Joint* jointN, float leftLinN, float rightLinN)
{
	isGhost = true;
	world = worldN;
	left = leftN;
	right = rightN;
	joint = jointN;
	extend = false;

	one = new MuscleConnector(world,left,joint,leftLinN);
	two = new MuscleConnector(world, right, joint, rightLinN);

	glm::vec3 pos = (left->GetPosition() + right->GetPosition()) / 2.0f;
	position = glm::translate(position, pos);
	position = glm::rotate(position, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));

	float height = 1.0f*METER;
	float radius = 0.25*METER;

	GetVertices().push_back({ { -radius, -height / 2.0f, -radius }, { 0.0f, 0.0f, 1.0f } });
	GetVertices().push_back({ { radius, -height / 2.0f, radius }, { 0.0f, 0.0f, 1.0f } });
	GetVertices().push_back({ { -radius, -height / 2.0f, radius }, { 0.0f, 0.0f, 1.0f } });
	GetVertices().push_back({ { radius, -height / 2.0f, -radius }, { 0.0f, 0.0f, 1.0f } });

	GetVertices().push_back({ { -radius, height / 2.0f, -radius }, { 0.0f, 0.0f, 1.0f } });
	GetVertices().push_back({ { radius, height / 2.0f, radius }, { 0.0f, 0.0f, 1.0f } });
	GetVertices().push_back({ { -radius, height / 2.0f, radius }, { 0.0f, 0.0f, 1.0f } });
	GetVertices().push_back({ { radius, height / 2.0f, -radius }, { 0.0f, 0.0f, 1.0f } });

	GetIndices().push_back({ glm::uvec3(0, 1, 2) });
	GetIndices().push_back({ glm::uvec3(0, 3, 1) });
	GetIndices().push_back({ glm::uvec3(4, 6, 5) });
	GetIndices().push_back({ glm::uvec3(4, 5, 7) });
	GetIndices().push_back({ glm::uvec3(0, 2, 6) });
	GetIndices().push_back({ glm::uvec3(0, 6, 4) });
	GetIndices().push_back({ glm::uvec3(1, 3, 7) });
	GetIndices().push_back({ glm::uvec3(1, 7, 5) });
	GetIndices().push_back({ glm::uvec3(0, 4, 7) });
	GetIndices().push_back({ glm::uvec3(0, 7, 3) });
	GetIndices().push_back({ glm::uvec3(1, 5, 6) });
	GetIndices().push_back({ glm::uvec3(1, 6, 2) });

	shape = new btCapsuleShape(radius, height - (radius * 2));

	Load();
	UpdateConstraint(one,two);
}
void Muscle::UpdateConstraint(MuscleConnector* one, MuscleConnector* two){
	btVector3 pivotInA = btVector3(0.0f, 0.0f, 0.0f);
	btVector3 pivotInC = btVector3(0.0f, 0.0f, 0.0f);

	btVector3 pivotInB = rigidBody ? rigidBody->getCenterOfMassTransform().inverse()(GetRigidBody()->getCenterOfMassTransform()(pivotInA)) : pivotInA;

	btVector3 axisInA = btVector3(joint->localAxisofRotation.x, joint->localAxisofRotation.y, joint->localAxisofRotation.z);

	btTransform frameA = one->GetRigidBody()->getWorldTransform();
	btTransform frameB = rigidBody->getWorldTransform();
	btTransform frameC = two->GetRigidBody()->getWorldTransform();

	conOne = new btSliderConstraint(*one->GetRigidBody(), *rigidBody, frameA, frameB, true);
	conTwo = new btSliderConstraint(*two->GetRigidBody(), *rigidBody, frameC, frameB, true);
	world->addConstraint(conOne, true);
	world->addConstraint(conTwo, true);
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

void  Muscle::Draw(Camera& camera){
	Object::Draw(camera);
	one->Draw(camera);
	two->Draw(camera);
}

void Muscle::Update(float expand){

	if (extend){
		conOne->setPoweredLinMotor(true);
		conTwo->setPoweredLinMotor(true);
		conOne->setMaxLinMotorForce(3*NEWTON);
		conTwo->setTargetLinMotorVelocity(1.0f);    // negative value to contract
	}
	else{
		conOne->setPoweredLinMotor(true);
		conTwo->setPoweredLinMotor(true);
		conOne->setMaxLinMotorForce(3 * NEWTON);
		conTwo->setTargetLinMotorVelocity(-1.0f);    // negative value to contract
	}
}

Muscle::~Muscle()
{


}
