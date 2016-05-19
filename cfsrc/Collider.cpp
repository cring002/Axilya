
#include "Collider.hpp"
#include "Entity.hpp"

Collider::Collider(Entity* owner) : Component(owner){
    
}

bool Collider::collideCheck(){
    return false;
}