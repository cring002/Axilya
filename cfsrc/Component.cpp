//
//  Component.cpp
//  closedFrameworks
//
//  Created by William Meaton on 12/05/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#include "Component.hpp"
#include "Entity.hpp"

Component::Component(){
    this->start();
}

Component::~Component(){
}

Entity* Component::getOwner(){
    return owner;
}

Scene* Component::getScene() {
    return owner->getScene();
}

void Component::setOwner(Entity* o){
    this->owner = o;
}