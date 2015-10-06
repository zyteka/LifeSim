#include "Terrain.h"


Terrain::Terrain()
{

	Vertex fill = { { -1.0f*KILOMETER, 0.0f, -1.0f*KILOMETER }, { 0.0f, 0.0f, 1.0f }, { 0.9f, 0.9f, 0.9f } };
	GetVertices().push_back(fill);
	Vertex fill1 = { { 1.0f*KILOMETER, 0.0f, 1.0f*KILOMETER }, { 0.0f, 0.0f, 1.0f }, { 0.9f, 0.9f, 0.9f } };
	GetVertices().push_back(fill1);
	Vertex fill2 = { { -1.0f*KILOMETER, 0.0f, 1.0f*KILOMETER }, { 0.0f, 0.0f, 1.0f }, { 0.9f, 0.9f, 0.9f } };
	GetVertices().push_back(fill2);
	Vertex fill3 = { { 1.0f*KILOMETER, 0.0f, -1.0f*KILOMETER }, { 0.0f, 0.0f, 1.0f }, { 0.9f, 0.9f, 0.9f } };
	GetVertices().push_back(fill3);

	Index fill4 = { glm::uvec3(0, 2, 1) };
	GetIndices().push_back(fill4);
	Index fill5 = { glm::uvec3(0, 1, 3) };
	GetIndices().push_back(fill5);


	Load(); //loads drawing related stuff. Call after vertices/indices have been defined
}


Terrain::~Terrain()
{
}
