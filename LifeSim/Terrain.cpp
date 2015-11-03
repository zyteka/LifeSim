#include "Terrain.h"


Terrain::Terrain(btDiscreteDynamicsWorld* worldN, uint widthN, int seed)
{


	float amplitude = 50 * METER;
	Perlin* perlin = new Perlin(5, 0.1, amplitude, seed);
	width = widthN;
	isStatic=true;
	world = worldN;

	continuousHeightData = new float[width*width];

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < width; j++) {
			float x = ((i / (width - 1.0f)) - (0.5f))*KILOMETER;
			float z = ((j / (width - 1.0f)) - (0.5f))*KILOMETER;
			float y =  perlin->Get(i, j);
			GetVertices().push_back({ { x, y, z }, { 0.9f, 0.9f, 0.9f } });

			continuousHeightData[i + j*width] = y;
		}
	}

	for (int i = 0; i < width-1; i++) {
		for (int j = 0; j < width-1; j++) {
			GetIndices().push_back({ glm::uvec3((i + (j*width)), (i + (j*width)) + 1, i + (1 + j)*(width)) });
			GetIndices().push_back({ glm::uvec3((i + (j*width)) + 1, i + (1 + j)*(width)+1, i + (1 + j)*(width)) });
		}
	}

	shape = new btHeightfieldTerrainShape(width, width, continuousHeightData, 1.0f, -amplitude, amplitude, 1, PHY_FLOAT, false);

	btVector3 localScaling = btVector3(KILOMETER / (float)width, 1.0f, KILOMETER / (float)width);
	shape->setLocalScaling(localScaling);

	Load(); //loads drawing related stuff. Call after vertices/indices have been defined
}


Terrain::~Terrain()
{
}
