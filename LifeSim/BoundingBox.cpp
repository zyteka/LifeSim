#include "BoundingBox.h"

BoundingBox::BoundingBox(btDiscreteDynamicsWorld* worldN,glm::vec3 pos,glm::vec3 size)
{
	world = worldN;

	Vertex fill = { { -size.x / 2.0f, -size.y / 2.0f, -size.z / 2.0f }, { 1.0f, 0.0f, 0.0f } };
	GetVertices().push_back(fill);
	Vertex fill1 = { { size.x / 2.0f, -size.y / 2.0f, size.z / 2.0f }, { 1.0f, 0.0f, 0.0f } };
	GetVertices().push_back(fill1);
	Vertex fill2 = { { -size.x / 2.0f, -size.y / 2.0f, size.z / 2.0f }, { 1.0f, 0.0f, 0.0f } };
	GetVertices().push_back(fill2);
	Vertex fill3 = { { size.x / 2.0f, -size.y / 2.0f, -size.z / 2.0f }, { 1.0f, 0.0f, 0.0f } };
	GetVertices().push_back(fill3);

	Vertex fill4 = { { -size.x / 2.0f, size.y / 2.0f, -size.z / 2.0f }, { 1.0f, 0.0f, 0.0f } };
	GetVertices().push_back(fill4);
	Vertex fill5 = { { size.x / 2.0f, size.y / 2.0f, size.z / 2.0f }, { 1.0f, 0.0f, 0.0f } };
	GetVertices().push_back(fill5);
	Vertex fill6 = { { -size.x / 2.0f, size.y / 2.0f, size.z / 2.0f }, { 1.0f, 0.0f, 0.0f } };
	GetVertices().push_back(fill6);
	Vertex fill7 = { { size.x / 2.0f, size.y / 2.0f, -size.z / 2.0f }, { 1.0f, 0.0f, 0.0f } };
	GetVertices().push_back(fill7);

	Index iFill1 = { glm::uvec3(0, 1, 2) };
	GetIndices().push_back(iFill1);
	Index iFill2 = { glm::uvec3(0, 3, 1) };
	GetIndices().push_back(iFill2);
	Index iFill3 = { glm::uvec3(4, 6, 5) };
	GetIndices().push_back(iFill3);
	Index iFill4 = { glm::uvec3(4, 5, 7) };
	GetIndices().push_back(iFill4);
	Index iFill5 = { glm::uvec3(0, 2, 6) };
	GetIndices().push_back(iFill5);
	Index iFill6 = { glm::uvec3(0, 6, 4) };
	GetIndices().push_back(iFill6);
	Index iFill7 = { glm::uvec3(1, 3, 7) };
	GetIndices().push_back(iFill7);
	Index iFill8 = { glm::uvec3(1, 7, 5) };
	GetIndices().push_back(iFill8);
	Index iFill9 = { glm::uvec3(0, 4, 7) };
	GetIndices().push_back(iFill9);
	Index iFill10 = { glm::uvec3(0, 7, 3) };
	GetIndices().push_back(iFill10);
	Index iFill11 = { glm::uvec3(1, 5, 6) };
	GetIndices().push_back(iFill11);
	Index iFill12 = { glm::uvec3(1, 6, 2) };
	GetIndices().push_back(iFill12);


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


void BoundingBox::Update(){ 
	btTransform trans;
	rigidBody->getMotionState()->getWorldTransform(trans);
	trans.getOpenGLMatrix(glm::value_ptr(position));
}

BoundingBox::~BoundingBox()
{
}

glm::mat4 BoundingBox::GetPosition(){
	return position;
}