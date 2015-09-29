#include "Object.h"


Object::Object()
{
	position = glm::mat4();
	Load();

}


Object::~Object()
{
}

void Object::Draw(Camera& camera)
{
	
	shader->use();
	glBindVertexArray(vao);
	shader->setUniform(cameraUniform, camera.matrix());
	glDrawElements(GL_TRIANGLES, (6), GL_UNSIGNED_INT, (GLvoid*)0);
	glBindVertexArray(0);
	shader->stopUsing();


}
void Object::Load(){
	shader = LoadShaders("Resource Files\\vertex-shader[basic].txt", "Resource Files\\fragment-shader[basic].txt");
	cameraUniform = shader->uniform("camera");
	

	Vertex fill = { { 0.0f*METER, 0.0f*METER }, { 0.0f, 0.0f,1.0f }, { 0.5f, 0.0f, 0.0f } };
	vertices.push_back(fill);
	Vertex fill1 = { { 1.0f*METER, 1.0f*METER }, { 0.0f, 0.0f, 1.0f }, { 0.5f, 0.0f, 0.0f } };
	vertices.push_back(fill1);
	Vertex fill2 = { { 0.0f*METER, 1.0f*METER }, { 0.0f, 0.0f, 1.0f }, { 0.5f, 0.0f, 0.0f } };
	vertices.push_back(fill2);
	Vertex fill3 = { { 1.0f*METER, 0.0f*METER }, { 0.0f, 0.0f, 1.0f }, { 0.5f, 0.0f, 0.0f } };
	vertices.push_back(fill3);

	Index fill4 = { glm::uvec3(0, 2, 1) };
	indices.push_back(fill4);
	Index fill5 = { glm::uvec3(0, 1, 3) };
	indices.push_back(fill5);


	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)*vertices.size(), vertices.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(shader->attrib("vert_VS_in"));
	glVertexAttribPointer(shader->attrib("vert_VS_in"), 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), NULL);
	glEnableVertexAttribArray(shader->attrib("normal_VS_in"));
	glVertexAttribPointer(shader->attrib("normal_VS_in"), 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (const GLvoid*)(2 * sizeof(GLfloat)));
	glEnableVertexAttribArray(shader->attrib("color_VS_in"));
	glVertexAttribPointer(shader->attrib("color_VS_in"), 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (const GLvoid*)(5 * sizeof(GLfloat)));

	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Index)*indices.size(), indices.data(), GL_STATIC_DRAW);

	glBindVertexArray(0);
}

std::vector<Index>& Object::GetIndices(){
	return indices;
}
std::vector<Vertex>& Object::GetVertices(){
	return vertices;
}