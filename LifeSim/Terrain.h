#pragma once
#include "Object.h"

class Terrain : public Object
{
public:
	Terrain(btDiscreteDynamicsWorld*);
	~Terrain();
};

