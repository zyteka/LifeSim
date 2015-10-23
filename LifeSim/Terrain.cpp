#include "Terrain.h"


Terrain::Terrain(btDiscreteDynamicsWorld* worldN)
{
	isStatic=true;
	world = worldN;
	position = glm::mat4();

	GetVertices().push_back({ { -1.0f*KILOMETER, 0.0f, -1.0f*KILOMETER }, { 0.9f, 0.9f, 0.9f } });
	GetVertices().push_back({ { 1.0f*KILOMETER, 0.0f, 1.0f*KILOMETER }, { 0.9f, 0.9f, 0.9f } });
	GetVertices().push_back({ { -1.0f*KILOMETER, 0.0f, 1.0f*KILOMETER }, { 0.9f, 0.9f, 0.9f } });
	GetVertices().push_back({ { 1.0f*KILOMETER, 0.0f, -1.0f*KILOMETER }, { 0.9f, 0.9f, 0.9f } });

	GetIndices().push_back({ glm::uvec3(0, 2, 1) });
	GetIndices().push_back({glm::uvec3(0, 1, 3)});


	shape = new btStaticPlaneShape(btVector3(0, 1, 0), 0);

	Load(); //loads drawing related stuff. Call after vertices/indices have been defined
}


Terrain::~Terrain()
{
}
