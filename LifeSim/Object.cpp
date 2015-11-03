#include "Object.h"


Object::Object()
{
	isStatic = false;
	isGhost = false;
	position = glm::mat4();
}


Object::~Object()
{
}

void Object::Draw(Camera& camera)
{
	if (shader == NULL){
		std::cout << "Forgot to call Load()" << std::endl;
	}
		shader->use();
		glBindVertexArray(vao);
		shader->setUniform(cameraUniform, camera.matrix());
		//shader->setUniform(cameraUniform, glm::ortho(0.0f, 1.0f*METER, 0.0f, 1.0f*METER, 2.0f*METER, -2.0f*METER));//camera.matrix() otherwise
		shader->setUniform(posUniform, position);
		glDrawElements(GL_TRIANGLES, (indices.size() * 3), GL_UNSIGNED_INT, (GLvoid*)0);
		glBindVertexArray(0);
		shader->stopUsing();
}
void Object::Load(){

	if (!isStatic){
		btTransform trans;
		trans.setFromOpenGLMatrix(glm::value_ptr(position));
		btDefaultMotionState* motState =
			new btDefaultMotionState(trans);
		btScalar mass = 1;
		btVector3 fallInertia(0, 0, 0);
		shape->calculateLocalInertia(mass, fallInertia);
		btRigidBody::btRigidBodyConstructionInfo fallRigidBodyCI(mass, motState, shape, fallInertia);
		rigidBody = new btRigidBody(fallRigidBodyCI);
		rigidBody->setFriction(1.35f);
		if (isGhost){
			rigidBody->setCollisionFlags(rigidBody->getCollisionFlags() | rigidBody->CF_NO_CONTACT_RESPONSE);
		}
		world->addRigidBody(rigidBody);
	}
	else{
		btTransform trans;
		trans.setFromOpenGLMatrix(glm::value_ptr(position));
		btDefaultMotionState* motState =
			new btDefaultMotionState(trans);
		btRigidBody::btRigidBodyConstructionInfo
			groundRigidBodyCI(0, motState, shape, btVector3(0, 0, 0));
		rigidBody = new btRigidBody(groundRigidBodyCI);
		rigidBody->setFriction(1.35f);
		if (isGhost){
			rigidBody->setCollisionFlags(rigidBody->getCollisionFlags() | rigidBody->CF_NO_CONTACT_RESPONSE);
		}
		world->addRigidBody(rigidBody);
	}

	shader = LoadShaders("vertex-shader[basic].txt", "geometry-shader[basic].txt","fragment-shader[basic].txt");
	cameraUniform = shader->uniform("camera");
	posUniform = shader->uniform("position");


	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)*vertices.size(), &vertices.front(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(shader->attrib("vert_VS_in"));
	glVertexAttribPointer(shader->attrib("vert_VS_in"), 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), NULL);
	glEnableVertexAttribArray(shader->attrib("color_VS_in"));
	glVertexAttribPointer(shader->attrib("color_VS_in"), 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid*)(3 * sizeof(GLfloat)));

	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Index)*indices.size(), &indices.front(), GL_STATIC_DRAW);

	glBindVertexArray(0);
}

void Object::Update(double dt){
	
}
void Object::UpdatePosition(){
	btTransform trans;
	rigidBody->getMotionState()->getWorldTransform(trans);
	trans.getOpenGLMatrix(glm::value_ptr(position));
}
std::vector<Index>& Object::GetIndices(){
	return indices;
}
std::vector<Vertex>& Object::GetVertices(){
	return vertices;
}
btRigidBody* Object::GetRigidBody(){
	return rigidBody;
}
glm::vec3 Object::GetPosition(){
	return glm::vec3(position[3]);
}

glm::mat4 Object::GetMatrix(){
	return position;
}
