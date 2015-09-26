#include "Object.h"


Object::Object()
{
}


Object::~Object()
{
}

void Object::Draw()
{
}

std::vector<Index> Object::GetIndices(){
	return indices;
}
std::vector<Vertex> Object::GetVertices(){
	return vertices;
}