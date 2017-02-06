//  RigidBody.cpp
//  Axilya
//
//  Created by William Meaton on 12/05/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//
#include "headers/RigidBody.hpp"
#include "headers/Entity.hpp"

RigidBody::RigidBody(bool gravity): velocity(0, 0), drag(0.5, 0.5), gravity(gravity){
    wasGrounded = false;
    isGrounded = false;
    maxVelocityY = 8;
    maxVelocityX = 7;
}

void RigidBody::update(){
    //get the last frame
    previousVelocity = velocity;
    wasGrounded = isGrounded;
    this->applyDrag();
    this->applyGravity();
    this->terminalVelocity();
    this->owner->moveEntity(velocity);
}

void RigidBody::applyGravity(){
    if(gravity){
        velocity.y += 1;
    }
}

void RigidBody::terminalVelocity(){
    if(velocity.x > maxVelocityX){
        velocity.x = maxVelocityX;
    }else if(velocity.x < - maxVelocityX){
        velocity.x = -maxVelocityX;
    }
    if(velocity.y > maxVelocityY){
        velocity.y = maxVelocityY;
    }else if(velocity.y < -maxVelocityY){
        velocity.y = -maxVelocityY;
    }
}

void RigidBody::applyDrag(){
    if(velocity.x < drag.x && velocity.x > drag.x){
        velocity.x = 0;
    }else if(velocity.y > 0){
        velocity.y -= drag.y;
    }else if(velocity.y < 0){
        velocity.y += drag.y;
    }
    if(velocity.y < drag.y && velocity.y > drag.y){
        velocity.y = 0;
    }else if(velocity.x > 0){
        velocity.x -= drag.x;
    }else if(velocity.x < 0){
        velocity.x += drag.x;
    }
}

bool RigidBody::isMoving(){
    return (velocity.x != 0 && velocity.y != 0);
}

void RigidBody::setGravity(bool g){
    this->gravity = g;
}

bool RigidBody::getGravity(){
    return this->gravity;
}

void RigidBody::addForce(float x, float y){
    this->velocity.x += x;
    this->velocity.y += y;
}

void RigidBody::addForce(const Math::Vector2D& f){
    velocity += f;
}

const Math::Vector2D& RigidBody::getForce(){
    return velocity;
}

void RigidBody::setDrag(float x, float y){
    this->drag.x = x;
    this->drag.y = y;
}

void RigidBody::setDrag(const Math::Vector2D& drag){
    this->drag = drag;
}

bool RigidBody::isOnGround(){
    return isGrounded;
}

void RigidBody::setForce(float x, float y){
    this->velocity.x = x;
    this->velocity.y = y;
}

void RigidBody::setForce(const Math::Vector2D& force){
    this->setForce(force.x, force.y);
}
Component* RigidBody::clone(){
    return new RigidBody(this->gravity);
}
