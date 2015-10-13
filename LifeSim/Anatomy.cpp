#include "Anatomy.h"



Anatomy::Anatomy(btDiscreteDynamicsWorld* worldN){

	world = worldN;
	mainPart = new BoundingBox(world);
}

Anatomy::~Anatomy(){

	delete mainPart;
}

void Anatomy::Load(){

}
void  Anatomy::Draw(Camera& camera){
	mainPart->Draw(camera);
}
void  Anatomy::Update(){
	mainPart->Update();
}


//Convert Anatomy to unsigned int for use in hashing
Anatomy::operator unsigned int() const {
	/*
		Implement this function once Anatomy member variables are deifned
	*/

	return 0;
}