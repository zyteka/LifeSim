#pragma once

#include "BasicIncludes.h"
//This class represents anything that is drawable onscreen. 
class Object
{
public:
	Object();
	~Object();

	std::vector<Index>* GetIndices();
	std::vector<Vertex>* GetVertices();
private:
	std::vector<Vertex> vertices;
	std::vector<Index> indices;

	//a matrix defining rotation, translation, and scaling of the object
	//only use if the vertices are object space and not world space
	glm::mat4 position;
};

