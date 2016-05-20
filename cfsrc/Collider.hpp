#ifndef Collider_hpp
#define Collider_hpp

#include <stdio.h>
#include "Component.hpp"
#include "Types.h"

class Collider : public Component{
    Shape* bounds; 
public:
    //take the owner and bounds of the collider 
    Collider(Entity*);
    virtual void collideCheck(Math::Vector2D&) = 0;
};

#endif