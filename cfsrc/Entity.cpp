//
//  Entity.cpp
//  closedFrameworks
//
//  Created by William Meaton on 12/05/2016.
//  Copyright © 2016 WillMeaton.uk. All rights reserved.
//

#include "Entity.hpp"
#include "Scene.hpp"

Entity::Entity(float x, float y, float w, float h){
    transform = new Transform(x, y, w, h);
    transform->setOwner(this);
}

Entity::Entity(const Math::Vector2D& pos, const Math::Vector2D& size){
    transform = new Transform(pos, size);
    transform->setOwner(this);
}

Entity::~Entity(){
    //remove all the components
    delete transform;
    transform = 0;
    delete collider;
    collider = 0;
    delete rigidBody;
    rigidBody = 0;
    for(auto c : components){
        delete c;
        c = 0;
    }
}

void Entity::draw(){
    if(texture){
        // Graphics::fill(255, 255, 255, 255);
        std::cout << "Drawing texture" << std::endl;
        texture->draw(transform->getPos(), transform->getSize().x, transform->getSize().y);
    }else{
        Graphics::fill(colour);
        Graphics::drawRect(transform->getPos(), transform->getSize().x, transform->getSize().y);
    }
}
void Entity::update(){
    if(rigidBody){
        rigidBody->update();
    }
    for(auto c : components){
        //handles exceptions in user made components to a certain degree
        std::exception_ptr eptr;
        //attempt to update the components
        try {  
            c->update();
        }catch(...) {
            //catch an exception if it's thrown
            eptr = std::current_exception();
        }
        //handle the exception if there is one
        handle_eptr(eptr);
    }
}

void Entity::handle_eptr(std::exception_ptr eptr){
    try {
        if (eptr) {
            std::rethrow_exception(eptr);
        }
    } catch(const std::exception& e) {
        std::cout << "Caught exception \"" << e.what() << "\"\n";
    }
}


void Entity::moveEntity(Math::Vector2D v){
    if(collider){
        std::cout << "v1 " << v.x << " " << v.y << std::endl;
        scene->collideCheck(this, v);
        std::cout << "v2 " << v.x << " " << v.y << std::endl;
        collider->getBounds()->set(v, collider->getBounds()->getSize());
        transform->set(v);
    }
    // transform->moveTransform(v);
}

void Entity::onCollision(Entity* e){
    //when a collision happens
    for(auto c : components){
        c->onCollision(e);
    }
}

void Entity::setColour(float r, float g, float b, float a){
    this->colour.set(r, g, b, a);
}

void Entity::setColour(const Graphics::Colour& c){
    this->colour.set(c.getR(), c.getG(), c.getB(), c.getA());
}

const Graphics::Colour& Entity::getColour(){
    return colour;
}

Scene* Entity::getScene(){
    return scene;
}

void Entity::setScene(Scene* s){
    this->scene = s;
}

void Entity::addComponent(Component* c){
    c->setOwner(this);
    components.push_back(c);
}

void Entity::addRigidBody(RigidBody* r){
    r->setOwner(this);
    this->rigidBody = r;
}

void Entity::addRigidBody(bool gravity){
    this->rigidBody = new RigidBody(gravity);
    this->rigidBody->setOwner(this);
}

RigidBody* Entity::getRigidBody(){
    return rigidBody;
}

Transform* Entity::getTransform(){
    return transform;
}

void Entity::addTexture(std::string s){
    this->texture = new Graphics::Image(s);
}

void Entity::addTexture(Graphics::Image* i){
    this->texture = i;
}

void Entity::addCollider(Collider* c){
    if(c){
        c->setOwner(this);
        //this is temporary, it was causing a seg fault if set in the BoxCollider constructor 
        //because owner was not set until after the creation of the collider
        c->bounds = new Graphics::Rect(transform->getPos(), transform->getSize());
        c->center = Math::Vector2D(transform->getPos()+(transform->getSize()/2));
        c->halfSize = transform->getSize()/2;
        this->collider = c;
    }
}

Graphics::Image* Entity::getTexture(){
    return this->texture;
}

Collider* Entity::getCollider(){
    return collider;
}