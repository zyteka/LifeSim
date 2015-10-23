#include "BoundingBox.h"

BoundingBox::BoundingBox(btDiscreteDynamicsWorld* worldN,glm::vec3 pos,glm::vec3 size)
{
	world = worldN;

	GetVertices().push_back( { { -size.x / 2.0f, -size.y / 2.0f, -size.z / 2.0f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { size.x / 2.0f, -size.y / 2.0f, size.z / 2.0f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { -size.x / 2.0f, -size.y / 2.0f, size.z / 2.0f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { size.x / 2.0f, -size.y / 2.0f, -size.z / 2.0f }, { 1.0f, 0.0f, 0.0f } });

	GetVertices().push_back({ { -size.x / 2.0f, size.y / 2.0f, -size.z / 2.0f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { size.x / 2.0f, size.y / 2.0f, size.z / 2.0f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { -size.x / 2.0f, size.y / 2.0f, size.z / 2.0f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { size.x / 2.0f, size.y / 2.0f, -size.z / 2.0f }, { 1.0f, 0.0f, 0.0f } });

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


	shape = new btBoxShape(btVector3(size.x / 2.0f, size.y / 2.0f, size.z / 2.0f));

	btDefaultMotionState* fallMotionState =
		new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(pos.x, pos.y, pos.z)));
	btScalar mass = 1;
	btVector3 fallInertia(0, 0, 0);
	shape->calculateLocalInertia(mass, fallInertia);
	btRigidBody::btRigidBodyConstructionInfo fallRigidBodyCI(mass, fallMotionState, shape, fallInertia);
	rigidBody = new btRigidBody(fallRigidBodyCI);
	world->addRigidBody(rigidBody);

	Load();
}

btRigidBody* BoundingBox::GetRigidBody(){
	return rigidBody;
}

BoundingBox::~BoundingBox()
{
}

glm::mat4 BoundingBox::GetPosition(){
	return position;
}