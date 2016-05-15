//
//  RigidBody.cpp
//  closedFrameworks
//
//  Created by William Meaton on 12/05/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#include "RigidBody.hpp"


RigidBody::RigidBody(Entity* owner) : owner(owner){
    
}

void RigidBody::update(){
    if(gravity){
        owner->getTransform()->getPos().x++;
    }
}