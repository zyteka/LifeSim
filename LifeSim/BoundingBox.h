#pragma once

#include "BasicIncludes.h"
#include "Object.h"

class BoundingBox : public Object
{
public:
	BoundingBox();
	BoundingBox(int l, BoundingBox *p);
	~BoundingBox();

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

