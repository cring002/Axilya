//
//  Entity.hpp
//  closedFrameworks
//
//  Created by William Meaton on 12/05/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#ifndef Entity_hpp
#define Entity_hpp

#include <stdio.h>
#include "Math.h"
#include "Graphics.hpp"
//components
#include "Components.h"

#endif /* Entity_hpp */

class Entity{
    //a list of standard components, these are presets
    Transform* transform = 0;
    Collider* collider = 0;
    RigidBody* rigidBody = 0;
    //a list of custom components
    std::vector<Component*> components;
    //the texture/image the Entity owns
    Graphics::Image* texture = 0;
public:
    //constructors
    Entity(const Math::Vector2D& pos, const Math::Vector2D& size);
    Entity(float x, float y, float w, float h);
    virtual ~Entity();
    //update and draws
    virtual void update();
    virtual void draw();
    //add RigidBody
    void addRigidBody(RigidBody*);
    void addRigidBody(bool);
    //get the rigidBody
    RigidBody* getRigidBody();    
    //add a new texture
    void addTexture(std::string);
    void addTexture(Graphics::Image*);
    //get the texture
    Graphics::Image* getTexture();
    //add a collider
    void addCollider(Collider*);
    //get the collider
    Collider* getCollider();
    //add a new component
    void addComponent(Component*);
    //return the transform
    Transform* getTransform();
};