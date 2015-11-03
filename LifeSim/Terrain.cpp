#include "Terrain.h"


Terrain::Terrain(btDiscreteDynamicsWorld* worldN, uint widthN, int seed)
{
	Perlin* perlin = new Perlin(5, 0.2, 100*METER, seed);
	width = widthN;
	isStatic=true;
	world = worldN;

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < width; j++) {
			float x = ((i / (width - 1)) - (0.5f))*KILOMETER;
			float z = ((j / (width - 1)) - (0.5f))*KILOMETER;
			GetVertices().push_back({ { x, perlin->Get(i, j), z}, { 0, 0.5f, 0.5f } });
		}
	}

	for (int i = 0; i < width-1; i++) {
		for (int j = 0; j < width-1; j++) {
			GetIndices().push_back({ glm::uvec3((i + (j*width)), (i + (j*width)) + 1, i + (1 + j)*(width)) });
			GetIndices().push_back({ glm::uvec3((i + (j*width)) + 1, i + (1 + j)*(width)+1, i + (1 + j)*(width)) });
		}
	}

	shape = new btStaticPlaneShape(btVector3(0, 1, 0), 0);

	Load(); //loads drawing related stuff. Call after vertices/indices have been defined
}


Terrain::~Terrain()
{
}
