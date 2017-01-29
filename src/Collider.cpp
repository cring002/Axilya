
#include "headers/Collider.hpp"
#include "headers/Entity.hpp"
Collider::Collider(){
    
}

Collider::~Collider(){
	delete bounds;
}

Shape* Collider::getBounds(){
    return bounds;
}

void Collider::setOwner(Entity* e){
	this->owner = e;
}



Entity* Collider::getOwner(){
	return owner;
}
