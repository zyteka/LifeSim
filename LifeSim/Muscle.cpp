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

	float width = 0.3f*METER;
	GetVertices().push_back({ { -height / 2.0f, -width / 2.0f, -width / 2.0f }, { 0.0f, 0.0f, 1.0f } });
	GetVertices().push_back({ { height / 2.0f, -width / 2.0f, width / 2.0f }, { 0.0f, 0.0f, 1.0f } });
	GetVertices().push_back({ { -height / 2.0f, -width / 2.0f, width / 2.0f }, { 0.0f, 0.0f, 1.0f } });
	GetVertices().push_back({ { height / 2.0f, -width / 2.0f, -width / 2.0f }, { 0.0f, 0.0f, 1.0f } });

	GetVertices().push_back({ { -height / 2.0f, width / 2.0f, -width / 2.0f }, { 0.0f, 0.0f, 1.0f } });
	GetVertices().push_back({ { height / 2.0f, width / 2.0f, width / 2.0f }, { 0.0f, 0.0f, 1.0f } });
	GetVertices().push_back({ { -height / 2.0f, width / 2.0f, width / 2.0f }, { 0.0f, 0.0f, 1.0f } });
	GetVertices().push_back({ { height / 2.0f, width / 2.0f, -width / 2.0f }, { 0.0f, 0.0f, 1.0f } });

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

	shape = new btBoxShape(btVector3(height / 2.0f, height / 2.0f, height / 2.0f));

	Load();
	UpdateConstraint(one,two);
}
void Muscle::UpdateConstraint(MuscleConnector* one, MuscleConnector* two){
	btVector3 pivotInA = btVector3(0.0f, 0.0f, 0.0f);
	btVector3 pivotInC = btVector3(0.0f, 0.0f, 0.0f);

	btVector3 pivotInJointtoA = one->GetRigidBody() ? one->GetRigidBody()->getCenterOfMassTransform().inverse()(rigidBody->getCenterOfMassTransform()(pivotInA)) : pivotInA;

	btVector3 pivotInJointtoB = one->GetRigidBody() ? one->GetRigidBody()->getCenterOfMassTransform().inverse()(rigidBody->getCenterOfMassTransform()(pivotInA)) : pivotInC;

	btVector3 axisInA = btVector3(joint->localAxisofRotation.x, joint->localAxisofRotation.y, joint->localAxisofRotation.z);



	btTransform frameLeft;
	frameLeft.setIdentity();
	frameLeft.setOrigin(btVector3(-0.25f*METER, 0.0f, 0.0f));
	btTransform frameRight;
	frameRight.setIdentity();
	frameRight.setOrigin(btVector3(0.25f*METER, 0.0f, 0.0f));
	//btVector3 pivotAtoB = two->GetRigidBody() ? two->GetRigidBody()->getCenterOfMassTransform().inverse()(one->GetRigidBody()->getCenterOfMassTransform()(pivotInA)) : pivotInC;
	//frameRight.setOrigin(pivotAtoB);


	constraint = new btSliderConstraint(*one->GetRigidBody(), *two->GetRigidBody(), frameLeft, frameRight, false);

	//constraint->setLowerLinLimit(1.0f*METER);
	//constraint->setUpperLinLimit(3.0f*METER);
	constraint->setPoweredLinMotor(false);
	constraint->setMaxLinMotorForce(10);
	constraint->setTargetLinMotorVelocity(1.0f);    // negative value to contract
	world->addConstraint(constraint, true);
}

void Muscle::UpdatePosition(){
	one->UpdatePosition();
	two->UpdatePosition();
	position = (one->GetMatrix() + two->GetMatrix()) / 2.0f;
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

	constraint->setTargetLinMotorVelocity(100.0f);

}

Muscle::~Muscle()
{


}
