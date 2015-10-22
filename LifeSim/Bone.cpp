#include "Bone.h"


Bone::Bone(btDiscreteDynamicsWorld* world, Joint * left, Joint*right,glm::vec3 pos,glm::vec3 size)
{

	bodyPart = new BoundingBox(world,pos,size);
	endRight = right;
	endLeft = left;
}


Bone::~Bone()
{
	delete bodyPart;
}

void Bone::Load(){

}
void  Bone::Draw(Camera& camera){
	bodyPart->Draw(camera);
}
void  Bone::Update(){
	bodyPart->Update();
}
