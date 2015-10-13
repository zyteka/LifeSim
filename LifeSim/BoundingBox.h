#pragma once

#include "Object.h"

class BoundingBox : public Object
{
public:
	BoundingBox(btDiscreteDynamicsWorld*);
	BoundingBox(int l, BoundingBox *p);
	~BoundingBox();


	void Update();

	BoundingBox* getParent();
	std::list<BoundingBox> getChildren();
	uint numChildren();
	int getLayer();
	bool addChild(BoundingBox b);

private:
	BoundingBox *parent;
	std::list<BoundingBox> children;
	int layer;

};

