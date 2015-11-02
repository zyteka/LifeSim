#include "Terrain.h"


Terrain::Terrain(btDiscreteDynamicsWorld* worldN, uint widthN)
{
	width = widthN;
	isStatic=true;
	world = worldN;

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < width; j++) {
			GetVertices().push_back({ { ((i / width)*KILOMETER) - (width / 2.0f), 0.0f, ((j / width)*KILOMETER) - (width / 2.0f) }, { 0, 0.5f, 0.5f } });
		}
	}

	for (int i = 0; i < width-1; i++) {
		for (int j = 0; j < width-1; j++) {
			GetIndices().push_back({ glm::uvec3((i + (j*width)), (i + (j*width)) + 1, i + ((1 + j)*(width - 1))) });
			GetIndices().push_back({ glm::uvec3(((i + (j*width)) + 1, i + (((1 + j)*(width - 1))) + 1, i + ((1 + j)*(width - 1)))) });
		}
	}

	shape = new btStaticPlaneShape(btVector3(0, 1, 0), 0);

	Load(); //loads drawing related stuff. Call after vertices/indices have been defined
}


Terrain::~Terrain()
{
}
