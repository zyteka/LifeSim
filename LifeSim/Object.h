#pragma once

#include "BasicIncludes.h"
#include "ShaderSupport.h"
#include "Camera.h"

//This class represents anything that is drawable onscreen. 
class Object
{
public:
	Object();
	~Object();

	void Draw(Camera&);
	void Load();

	std::vector<Index>& GetIndices();
	std::vector<Vertex>& GetVertices();
private:
	std::vector<Vertex> vertices;
	std::vector<Index> indices;

	//a matrix defining rotation, translation, and scaling of the object
	//only use if the vertices are object space and not world space
	glm::mat4 position;
	GLuint cameraUniform;

	shading::ShaderSupport* shader;
	GLuint vao;
	GLuint vbo;
	GLuint ibo;
};

