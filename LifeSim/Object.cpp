#include "Object.h"


Object::Object()
{
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

void Object::Update(){
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