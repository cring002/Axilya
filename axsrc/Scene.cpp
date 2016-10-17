#include "Entity.hpp"
#include "Runner.hpp"
#include "Scene.hpp"

Scene::Scene(){
}

Scene::~Scene(){
//    for(auto e : entities){
//        delete e;
//        e = 0;
//    }
}

void Scene::draw(){
    if(world) {
        this->world->draw();
    }
    for(auto e : entities){
        if(e->isActive()){
            e->draw();
        }
    }
}

void Scene::update() {
    if (world) {
        this->world->update();
    }
    for(auto e : entities){
        if(e->isActive()){
            e->update();
        }
    } 
}

void Scene::collideCheck(Entity* e, Math::Vector2D& proposedMovement){
    //check this entity against the rest with the proposedMovement
    for(int i = 0; i < entities.size(); i++){
        if(entities[i]->getCollider() && entities[i]->isActive()){
            //don't compare against the proposed
            if(entities[i] != e){
                //if there is a collision then allow it to correct and loop again
                while(entities[i]->getCollider()->checkMovement(e, proposedMovement)){
                    entities[i]->onCollision(e);
                    e->onCollision(entities[i]);
                }
            }
        }
    }
}

bool Scene::addEntity(Entity* e){
    if(e) {
        if(uMap.find(e->getName()) == uMap.end()) {
            e->setScene(this);
            this->entities.push_back(e);
            this->uMap[e->getName()] = e;
            return true;
        }else{
            std::cout << "Entity with the name: " << e->getName() << " already in this scene." << std::endl;
            return false;
        }
    }else{
        return false;
    }
}

void Scene::parseSceneFile(const std::string &path) {
    std::string source = "data/"+path;
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file(source.c_str());
    if(result) {

        for (pugi::xml_node entity = doc.child("Scene").child("Entity"); entity; entity = entity.next_sibling("Entity"))
        {
            Entity* tempEntity;
            std::string name = entity.attribute("name").value();
            pugi::xml_node transform = entity.child("Components").child("Transform");
            if(transform) {
                int xPos = atoi(transform.child("Position").attribute("x").value());
                int yPos = atoi(transform.child("Position").attribute("y").value());
                int xSize = atoi(transform.child("Size").attribute("x").value());
                int ySize = atoi(transform.child("Size").attribute("y").value());
                tempEntity = new Entity(name, xPos, yPos, xSize, ySize);
            }
            if(tempEntity) {
                this->addEntity(tempEntity);
            }
        }
    }

}

Entity* Scene::instantiate(const std::string& name, Entity* e, Transform* t){
    if(e && t && name != ""){
        Entity* temp = e->clone();
        temp->getTransform()->set(t->getPos(), t->getSize());
        if(temp->getCollider()){
            temp->getCollider()->getBounds()->set(t->getPos(), t->getSize());
        }
        temp->setName(name);
        if(this->addEntity(temp)){
            return temp;
        }else{
            return 0;
        }
    }else{
        return 0;
    }
}

Entity* Scene::instantiate(const std::string& name, Entity* e){
    return this->instantiate(name, e, e->getTransform());
}

void Scene::addWorld(World *w) {
    if(w){
        world = w;
    }
}

void Scene::removeEntity(Entity* e){
    for(auto it = entities.begin(); it != entities.end(); it++){
        if(*it == e){
            entities.erase(it);
            uMap.erase(e->getName());
            break;
        }
    }
}

Entity* Scene::findEntity(const std::string &name) {
    if(uMap.find(name) == uMap.end()){
        std::cout << "Entity not found with name: " << name << ". Returning null" << std::endl;
        return 0;
    }else{
        return uMap.at(name);
    }
}

int Scene::numEntities(){
    return this->entities.size();
}
