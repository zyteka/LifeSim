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

	float GetHeight(float, float); //returns the height in WORLD coordinates

	float* continuousHeightData;
};

