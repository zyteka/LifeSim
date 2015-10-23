#include "Joint.h"
#include "Bone.h"

Joint::Joint(btDiscreteDynamicsWorld* worldN, glm::vec3 posIn, float radiusN)
{
	isStatic = false;
	world = worldN;
	radius = radiusN;
	position = glm::mat4();
	position = glm::translate(position, glm::vec3(posIn.x, posIn.y, posIn.z));



	GetVertices().push_back({ { 0.000000f, -1.000000f, 0.000000f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { 0.723607f, -0.447220f, 0.525725f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { -0.276388f, -0.447220f, 0.850649f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { -0.894426f, -0.447216, 0.000000f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { -0.276388f, -0.447220f, -0.850649f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { 0.723607f, -0.447220f, -0.525725f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { 0.276388f, 0.447220f, 0.850649f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { -0.723607f, 0.447220f, 0.525725f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { -0.723607f, 0.447220f, -0.525725f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { 0.276388f, 0.447220, -0.850649f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { 0.894426f, 0.447216, 0.000000f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { 0.000000f, 1.000000f, 0.000000f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { -0.162456f, -0.850654, 0.499995f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { 0.425323f, -0.850654, 0.309011f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { 0.262869f, -0.525738, 0.809012f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { 0.850648f, -0.525736, 0.000000f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { 0.425323f, -0.850654, -0.309011f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { -0.525730f, -0.850652, 0.000000f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { -0.688189f, -0.525736, 0.499997f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { -0.162456f, -0.850654, -0.499995f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { -0.688189f, -0.525736, -0.499997f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { 0.262869f, -0.525738, -0.809012f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { 0.951058f, 0.000000f, 0.309013f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { 0.951058f, 0.000000f, -0.309013f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { 0.000000f, 0.000000f, 1.000000f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { 0.587786f, 0.000000f, 0.809017f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { -0.951058f, 0.000000, 0.309013f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { -0.587786f, 0.000000f, 0.809017f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { -0.587786f, 0.000000f, -0.809017f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { -0.951058f, 0.000000f, -0.309013f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { 0.587786f, 0.000000f, -0.809017f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { 0.000000f, 0.000000f, -1.000000f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { 0.688189f, 0.525736, 0.499997f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { -0.262869f, 0.525738, 0.809012f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { -0.850648f, 0.525736, 0.000000f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { -0.262869f, 0.525738, -0.809012f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { 0.688189f, 0.525736, -0.499997f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { 0.162456f, 0.850654, 0.499995f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { 0.525730f, 0.850652, 0.000000f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { -0.425323f, 0.850654, 0.309011f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { -0.425323f, 0.850654, -0.309011f }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { 0.162456f, 0.850654, -0.499995f }, { 1.0f, 0.0f, 0.0f } });


	for (int i = 0; i < GetVertices().size(); i++){
		GetVertices()[i].position *= (radius);
	}

	GetIndices().push_back({ glm::uvec3(1, 14, 13) });
	GetIndices().push_back({ glm::uvec3(2, 14, 16) });
	GetIndices().push_back({ glm::uvec3(1, 13, 18) });
	GetIndices().push_back({ glm::uvec3(1, 18, 20) });
	GetIndices().push_back({ glm::uvec3(1, 20, 17) });
	GetIndices().push_back({ glm::uvec3(2, 16, 23) });
	GetIndices().push_back({ glm::uvec3(3, 15, 25) });
	GetIndices().push_back({ glm::uvec3(4, 19, 27) });
	GetIndices().push_back({ glm::uvec3(5, 21, 29) });
	GetIndices().push_back({ glm::uvec3(6, 22, 31) });
	GetIndices().push_back({ glm::uvec3(2, 23, 26) });
	GetIndices().push_back({ glm::uvec3(3, 25, 28) });
	GetIndices().push_back({ glm::uvec3(4, 27, 30) });
	GetIndices().push_back({ glm::uvec3(5, 29, 32) });
	GetIndices().push_back({ glm::uvec3(6, 31, 24) });
	GetIndices().push_back({ glm::uvec3(7, 33, 38) });
	GetIndices().push_back({ glm::uvec3(8, 34, 40) });
	GetIndices().push_back({ glm::uvec3(9, 35, 41) });
	GetIndices().push_back({ glm::uvec3(10, 36, 42) });
	GetIndices().push_back({ glm::uvec3(11, 37, 39) });
	GetIndices().push_back({ glm::uvec3(39, 42, 12) });
	GetIndices().push_back({ glm::uvec3(39, 37, 42) });
	GetIndices().push_back({ glm::uvec3(37, 10, 42) });
	GetIndices().push_back({ glm::uvec3(42, 41, 12) });
	GetIndices().push_back({ glm::uvec3(42, 36, 41) });
	GetIndices().push_back({ glm::uvec3(36, 9, 41) });
	GetIndices().push_back({ glm::uvec3(41, 40, 12) });
	GetIndices().push_back({ glm::uvec3(41, 35, 40) });
	GetIndices().push_back({ glm::uvec3(35, 8, 40) });
	GetIndices().push_back({ glm::uvec3(40, 38, 12) });
	GetIndices().push_back({ glm::uvec3(40, 34, 38) });
	GetIndices().push_back({ glm::uvec3(34, 7, 38) });
	GetIndices().push_back({ glm::uvec3(38, 39, 12) });
	GetIndices().push_back({ glm::uvec3(38, 33, 39) });
	GetIndices().push_back({ glm::uvec3(33, 11, 39) });
	GetIndices().push_back({ glm::uvec3(24, 37, 11) });
	GetIndices().push_back({ glm::uvec3(24, 31, 37) });
	GetIndices().push_back({ glm::uvec3(31, 10, 37) });
	GetIndices().push_back({ glm::uvec3(32, 36, 10) });
	GetIndices().push_back({ glm::uvec3(32, 29, 36) });
	GetIndices().push_back({ glm::uvec3(29, 9, 36) });
	GetIndices().push_back({ glm::uvec3(30, 35, 9) });
	GetIndices().push_back({ glm::uvec3(30, 27, 35) });
	GetIndices().push_back({ glm::uvec3(27, 8, 35) });
	GetIndices().push_back({ glm::uvec3(28, 34, 8) });
	GetIndices().push_back({ glm::uvec3(28, 25, 34) });
	GetIndices().push_back({ glm::uvec3(25, 7, 34) });
	GetIndices().push_back({ glm::uvec3(26, 33, 7) });
	GetIndices().push_back({ glm::uvec3(26, 23, 33) });
	GetIndices().push_back({ glm::uvec3(23, 11, 33) });
	GetIndices().push_back({ glm::uvec3(31, 32, 10) });
	GetIndices().push_back({ glm::uvec3(31, 22, 32) });
	GetIndices().push_back({ glm::uvec3(22, 5, 32) });
	GetIndices().push_back({ glm::uvec3(29, 30, 9) });
	GetIndices().push_back({ glm::uvec3(29, 21, 30) });
	GetIndices().push_back({ glm::uvec3(21, 4, 30) });
	GetIndices().push_back({ glm::uvec3(27, 28, 8) });
	GetIndices().push_back({ glm::uvec3(27, 19, 28) });
	GetIndices().push_back({ glm::uvec3(19, 3, 28) });
	GetIndices().push_back({ glm::uvec3(25, 26, 7) });
	GetIndices().push_back({ glm::uvec3(25, 15, 26) });
	GetIndices().push_back({ glm::uvec3(15, 2, 26) });
	GetIndices().push_back({ glm::uvec3(23, 24, 11) });
	GetIndices().push_back({ glm::uvec3(23, 16, 24) });
	GetIndices().push_back({ glm::uvec3(16, 6, 24) });
	GetIndices().push_back({ glm::uvec3(17, 22, 6) });
	GetIndices().push_back({ glm::uvec3(17, 20, 22) });
	GetIndices().push_back({ glm::uvec3(20, 5, 22) });
	GetIndices().push_back({ glm::uvec3(20, 21, 5) });
	GetIndices().push_back({ glm::uvec3(20, 18, 21) });
	GetIndices().push_back({ glm::uvec3(18, 4, 21) });
	GetIndices().push_back({ glm::uvec3(18, 19, 4) });
	GetIndices().push_back({ glm::uvec3(18, 13, 19) });
	GetIndices().push_back({ glm::uvec3(13, 3, 19) });
	GetIndices().push_back({ glm::uvec3(16, 17, 6) });
	GetIndices().push_back({ glm::uvec3(16, 14, 17) });
	GetIndices().push_back({ glm::uvec3(14, 1, 17) });
	GetIndices().push_back({ glm::uvec3(13, 15, 3) });
	GetIndices().push_back({ glm::uvec3(13, 14, 15) });
	GetIndices().push_back({ glm::uvec3(14, 2, 15) });

	for (int i = 0; i < GetIndices().size(); i++){
		GetIndices()[i].indices.x--;
		GetIndices()[i].indices.y--;
		GetIndices()[i].indices.z--;
	}

	shape = new btSphereShape(radius);

	Load();
}


Joint::~Joint()
{
}

void Joint::Update(){
	//rigidBody->applyForce(btVector3(0.0f, 30.0f*NEWTON, 0.0f), btVector3(0.0f, 0.0f, 0.0f));
	Object::Update();
}

void Joint::AddBone(Bone* nBone){

	btVector3 pivotInA = btVector3(0.0f, 0.0f, 0.0f);

	btVector3 pivotInB = nBone->GetRigidBody() ? nBone->GetRigidBody()->getCenterOfMassTransform().inverse()(GetRigidBody()->getCenterOfMassTransform()(pivotInA)) : pivotInA;

	btPoint2PointConstraint* con = new btPoint2PointConstraint(*rigidBody, *nBone->GetRigidBody(), pivotInA, pivotInB);
	world->addConstraint(con, true);
	bones.insert(nBone);
}