#pragma once
#include <list>
#include "Object.h"
class BoundingBox : public Object
{
public:
	BoundingBox(int l, BoundingBox *p);
	~BoundingBox();

	BoundingBox* getParent();
	std::list<BoundingBox> getChildren();
	int numChildren();
	int getLayer();
	bool addChild(BoundingBox b);

private:
	BoundingBox *parent;
	std::list<BoundingBox> children;
	int layer;

};

