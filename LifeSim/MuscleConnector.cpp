#include "MuscleConnector.h"
#include "Bone.h"
#include "Joint.h"

MuscleConnector::MuscleConnector(btDiscreteDynamicsWorld* worldN, Bone* boneN, Joint* jointN, float trans)
{
	isGhost = true;
	world = worldN;
	bone = boneN;
	joint = jointN;
	translate = trans;

	glm::vec3 relToBone = glm::normalize(bone->GetPosition() - joint->GetPosition())*trans*(bone->height/2.0f);
	position = glm::translate(position, relToBone + bone->GetPosition());

	radius = 0.25f*METER;
	GetVertices().push_back({ { -radius, -radius, -radius }, { 0.0f, 1.0f, 0.0f } });
	GetVertices().push_back({ { radius, -radius, radius }, { 0.0f, 1.0f, 0.0f } });
	GetVertices().push_back({ { -radius, -radius, radius }, { 0.0f, 1.0f, 0.0f } });
	GetVertices().push_back({ { radius, -radius, -radius }, { 0.0f, 1.0f, 0.0f } });

	GetVertices().push_back({ { -radius, radius, -radius }, { 0.0f, 1.0f, 0.0f } });
	GetVertices().push_back({ { radius, radius, radius }, { 0.0f, 1.0f, 0.0f } });
	GetVertices().push_back({ { -radius, radius, radius }, { 0.0f, 1.0f, 0.0f } });
	GetVertices().push_back({ { radius, radius, -radius }, { 0.0f, 1.0f, 0.0f } });

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


	shape = new btSphereShape(radius);

	Load();
	UpdateConstraint();
}
void MuscleConnector::UpdateConstraint(){
	btVector3 pivotInA = btVector3(0.0f, 0.0f, 0.0f);

	btVector3 pivotInB = bone->GetRigidBody() ? bone->GetRigidBody()->getCenterOfMassTransform().inverse()(GetRigidBody()->getCenterOfMassTransform()(pivotInA)) : pivotInA;

	btVector3 axisInA = btVector3(joint->localAxisofRotation.x, joint->localAxisofRotation.y, joint->localAxisofRotation.z);

	btHingeConstraint* con = new btHingeConstraint(*rigidBody, *bone->GetRigidBody(), pivotInA, pivotInB, axisInA, axisInA, true);
	world->addConstraint(con, true);

}

MuscleConnector::~MuscleConnector()
{
}
