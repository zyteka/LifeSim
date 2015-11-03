#pragma once
#include "Object.h"
#include "Perlin.h"
#include "BulletCollision/CollisionShapes/btHeightfieldTerrainShape.h"

class Terrain : public Object
{
private:
	uint width;

public:
	Terrain(btDiscreteDynamicsWorld*, uint, int);
	~Terrain();

	float* continuousHeightData;
};

