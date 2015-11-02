#pragma once
#include "Object.h"

class Terrain : public Object
{
private:
	uint width;

public:
	Terrain(btDiscreteDynamicsWorld*, uint);
	~Terrain();
};

