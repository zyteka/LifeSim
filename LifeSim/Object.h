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

	virtual void Draw(Camera&);
	virtual void Load();
	virtual void Update(double );
	btRigidBody* GetRigidBody();
	glm::vec3 GetPosition();
	glm::mat4 GetMatrix();

	virtual void UpdatePosition();

	std::vector<Index>& GetIndices();
	std::vector<Vertex>& GetVertices();

protected:
	bool isStatic;
	bool isGhost;
	btDiscreteDynamicsWorld* world;
	btCollisionShape* shape;
	btRigidBody* rigidBody;
	glm::mat4 position;
private:
	std::vector<Vertex> vertices;
	std::vector<Index> indices;

	//a matrix defining rotation, translation, and scaling of the object
	//only use if the vertices are object space and not world space
	
	GLuint cameraUniform;
	GLuint posUniform;

	shading::ShaderSupport* shader;
	GLuint vao;
	GLuint vbo;
	GLuint ibo;

	
};

