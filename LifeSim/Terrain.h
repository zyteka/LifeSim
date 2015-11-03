#pragma once
#include "Object.h"
#include "Perlin.h"

class Terrain : public Object
{
private:
	uint width;

public:
	Terrain(btDiscreteDynamicsWorld*, uint, int);
	~Terrain();
};

