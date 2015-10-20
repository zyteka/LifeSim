#pragma once
//place all global structures here




// a point representing data of a point in space
typedef struct Vertex{
	glm::vec3 position; //d for double, i for int ect.
	glm::vec3 color;
}Vertex;

//A single index struct has 3 indices to 3 vertices creating a triangle CW Order!!! for correct shading
typedef struct Face{
	glm::uvec3 indices;
}Index;