#include "Bone.h"
#include "Joint.h"

Bone::Bone(btDiscreteDynamicsWorld* worldN, Joint * left, Joint*right, glm::vec3 pos, float radiusN, float heightN)
{
	isStatic = false;
	world = worldN;
	position = glm::mat4();
	position=glm::translate(position, pos);
	position=glm::rotate(position, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	//position = glm::rotate(position, glm::radians(90.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	height = heightN;
	radius = radiusN;
	endRight = right;
	endLeft = left;

	GetVertices().push_back({ { -radius, -height / 2.0f, -radius }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { radius, -height / 2.0f, radius }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { -radius, -height / 2.0f, radius }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { radius, -height / 2.0f, -radius }, { 1.0f, 0.0f, 0.0f } });

	GetVertices().push_back({ { -radius, height / 2.0f, -radius }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { radius, height / 2.0f, radius }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { -radius, height / 2.0f, radius }, { 1.0f, 0.0f, 0.0f } });
	GetVertices().push_back({ { radius, height / 2.0f, -radius }, { 1.0f, 0.0f, 0.0f } });

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

	shape = new btCapsuleShape(radius, height - (radius*2));

	Load();
}

Bone::~Bone()
{
}