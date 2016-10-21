//
//  RigidBody.hpp
//  closedFrameworks
//
//  Created by William Meaton on 12/05/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#ifndef RigidBody_hpp
#define RigidBody_hpp

#include <stdio.h>
#include "Component.hpp"

class RigidBody : public Component{
    bool gravity;
    Math::Vector2D velocity, drag, previousVelocity;
    bool wasGrounded = false, isGrounded = false;
    bool screenBound = true;
    float maxVelocityY = 8, maxVelocityX = 8;
    void applyDrag();
    void applyGravity();
    void terminalVelocity();
public:
    /*!
    * Adds a force to the rigid body 
    * @param owner the Entity which this component belongs too
    * @param gravity wheather this RigidBody has gravity
    */
    RigidBody(bool gravity);
    /*!
    * Adds a force to the rigid body 
    * @param x directional force
    * @param y directional force
    * @see RigidBody::addForce(cont Math::Vector2D& force)
    */
    void addForce(float x, float y);
    void addForce(const Math::Vector2D& force);
    const Math::Vector2D& getForce();
    /*!
    * Sets the force on an object
    */
    void setForce(const Math::Vector2D& force);
    void setForce(float x, float y);

    void setDrag(const Math::Vector2D& drag);
    void setDrag(float x, float y);
    /*!
    * returns if this rigidbody is moving
    */
    bool isMoving();

    bool isOnGround();
    /*!
    * Called every game loop
    * Called from the Entity which owns this component
    */
    void update();
    /*!
    * A method to set the gravity value
    */
    void setGravity(bool);
    bool getGravity();

    bool isScreenBound();
    void setScreenBound(bool);
    Component* clone();
};


#endif /* RigidBody_hpp */
