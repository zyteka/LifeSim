#include "Object.h"


Object::Object()
{
}


Object::~Object()
{
}

void Draw() {

}

std::vector<Index> Object::GetIndices(){
	return indices;
}
std::vector<Vertex> Object::GetVertices(){
	return vertices;
}