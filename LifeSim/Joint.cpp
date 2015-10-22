#include "Joint.h"


Joint::Joint(btDiscreteDynamicsWorld* world,glm::vec3 posIn,glm::vec3 bboxSize)
{
	bodyPart = new BoundingBox(world,posIn,bboxSize);
	position = posIn;
}


Joint::~Joint()
{
}


void Joint::Load(){

}
void  Joint::Draw(Camera& camera){
	bodyPart->Draw(camera);
}
void  Joint::Update(){
	bodyPart->Update();
	glm::mat4 pos=bodyPart->GetPosition();
	position = glm::vec3(pos[3]);
}

void Joint::AddBone(Bone* nBone){
	bones.insert(nBone);
}