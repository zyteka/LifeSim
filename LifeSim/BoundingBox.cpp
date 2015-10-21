#include "BoundingBox.h"

BoundingBox::BoundingBox(btDiscreteDynamicsWorld* worldN)
{
	world = worldN;
	layer = 0;
	parent = NULL;

	Vertex fill = { { -0.5f*METER, -0.5f*METER, -0.5f*METER }, { 1.0f, 0.0f, 0.0f } };
	GetVertices().push_back(fill);
	Vertex fill1 = { { 0.5f*METER, -0.5f*METER, 0.5f*METER }, { 1.0f, 0.0f, 0.0f } };
	GetVertices().push_back(fill1);
	Vertex fill2 = { { -0.5f*METER, -0.5f*METER, 0.5f*METER }, { 1.0f, 0.0f, 0.0f } };
	GetVertices().push_back(fill2);
	Vertex fill3 = { { 0.5f*METER, -0.5f*METER, -0.5f*METER }, { 1.0f, 0.0f, 0.0f } };
	GetVertices().push_back(fill3);

	Vertex fill4 = { { -0.5f*METER, 0.5f*METER, -0.5f*METER }, { 1.0f, 0.0f, 0.0f } };
	GetVertices().push_back(fill4);
	Vertex fill5 = { { 0.5f*METER, 0.5f*METER, 0.5f*METER }, { 1.0f, 0.0f, 0.0f } };
	GetVertices().push_back(fill5);
	Vertex fill6 = { { -0.5f*METER, 0.5f*METER, 0.5f*METER }, { 1.0f, 0.0f, 0.0f } };
	GetVertices().push_back(fill6);
	Vertex fill7 = { { 0.5f*METER, 0.5f*METER, -0.5f*METER }, { 1.0f, 0.0f, 0.0f } };
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


	shape = new btBoxShape(btVector3(0.5f * METER, 0.5f * METER, 0.5f * METER));

	btDefaultMotionState* fallMotionState =
		new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 50*METER, 0)));
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

BoundingBox::BoundingBox(int l, BoundingBox *p)
{
	layer = l;
	parent = p;
}


BoundingBox::~BoundingBox()
{
}

BoundingBox* BoundingBox::getParent() {
	return parent;
}

std::list<BoundingBox> BoundingBox::getChildren() {
	return children;
}

int BoundingBox::getLayer() {
	return layer;
}

uint BoundingBox::numChildren() {
	return uint(children.size());
}

bool BoundingBox::addChild(BoundingBox b) {
	if ((b.getLayer() <= layer + 1) && b.getLayer() >= layer - 1) {
		children.push_back(b);
		return true;
	}
	else
		return false;
}
