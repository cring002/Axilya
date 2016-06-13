#include "BoxCollider.hpp"
#include "Entity.hpp"

BoxCollider::BoxCollider(Entity* owner) : Collider(owner){
    bounds = new Graphics::Rect(owner->getTransform()->getPos(), owner->getTransform()->getSize());
}

void BoxCollider::worldCollideCheck(Math::Vector2D& v){
    Math::Vector2D newPos = bounds->getPosition();
    Math::Vector2D size = Math::Vector2D(bounds->getWidth(), bounds->getHeight());
    int screenWidth = Runner::getWidth();
    int screenHeight = Runner::getHeight();
    if(newPos.y+size.y+v.y >= screenHeight){
        v.y = 0;
        newPos.y = screenHeight-size.y;
    }
    if(newPos.y+v.y < 0){
        v.y = 0;
        newPos.y = 0;
    }
    if(newPos.x+size.x+v.x >= screenWidth){
        v.x = 0;
        newPos.x = screenWidth-size.x;
    }
    if(newPos.x+v.x < 0){
        v.x = 0;
        newPos.x = 0;
    }
    owner->getTransform()->getPos() = newPos;
}

void BoxCollider::collisionEntityCheck(Entity* e){
    if(!e){
        return;
    }
}