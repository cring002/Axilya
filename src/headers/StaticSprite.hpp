//
// Created by William Meaton on 02/09/2016.
//

#ifndef StaticSprite_hpp
#define StaticSprite_hpp

#include "Sprite.hpp"
class StaticSprite : public Sprite{
    AXTexture* texture = 0;
public:
    StaticSprite(const std::string& name);
    StaticSprite(const std::string& name, const std::string& filename);
    ~StaticSprite();
    void draw(float x, float y, float w, float h);
    void setTexture(int textureID);
    AXTexture* getTexture();
    Sprite* clone();
};


#endif
