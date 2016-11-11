//
//  Image.cpp
//  GLFW3
//
//  Created by William Meaton on 10/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#include "Image.hpp"
#include "Runner.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace Graphics{
    Image::~Image(){
        //remove the textures from the GL buffer
        glDeleteTextures(1, &textureID);
    }
    
    Image::Image(std::string name){
        this->loadImage(name);
    }
    
    bool Image::fileExists (const std::string& name) {
        return ( access( name.c_str(), F_OK ) != -1 );
    }
    
    bool Image::loadImage(std::string nameInput){
        if(loaded){
            std::cout << "Image: already loaded" << std::endl;
            return false;
        }
        path = nameInput;
        std::string temp = "data/" + nameInput;
        const char* name = temp.c_str();
        if(!fileExists(temp)){
            return false;
        }
        //check if it's already loaded, if so load into the same texture point
        if(!loaded){
            openGlLoad(name);
        }else{
            //delete the texture and reload
            glDeleteTextures(1, &textureID);
            //then load the texture
            openGlLoad(name);
        }
        if(textureID != 0){
            loaded = true;
            return true;
        }
        return false;
    }
    
    void Image::openGlLoad(const char* name){
        glEnable(GL_TEXTURE_2D);
        GLuint texture_id;
        glGenTextures(1, &texture_id);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture_id);
        // *data = stbi_load(filename, &x, &y, &n, 0);
        unsigned char* imageDataPtr = stbi_load(name, &this->w, &this->h, 0, 0);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->w, this->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageDataPtr);
        glEnd();
        stbi_image_free(imageDataPtr);
        this->textureID = texture_id;
    }
    
    void Image::draw(float x, float y){
        this->draw(x, y, this->w, this->h);
    }
    
    void Image::draw(const Math::Vector2D &v){
        this->draw(v.x, v.y, this->w, this->h);
    }
    
    void Image::draw(const Math::Vector2D &v, float w, float h){
        this->draw(v.x, v.y, w, h);
    }
    
    void Image::draw(float x, float y, float width, float height){
        if(textureID == 0 || !loaded){
            std::cout << "No image has been loaded" << std::endl;
            return;
        }
        glBindTexture(GL_TEXTURE_2D, textureID);
        glEnable(GL_TEXTURE_2D);
        glBegin(GL_QUADS);
        glTexCoord2d(0, 1); glVertex2f(x, y+height);
        //bottom left
        glTexCoord2d(0, 0); glVertex2f(x,y);
        //top left
        glTexCoord2d(1, 0); glVertex2f(x+width, y);
        //top right
        glTexCoord2d(1, 1); glVertex2f(x+width, y+height);
        //bottom right
        glEnd();
    }

    bool Image::grabScreen(float x, float y, float w, float h){
        return false;
        // return SOIL_save_screenshot
        // (
        //  "save.bmp",
        //  SOIL_SAVE_TYPE_BMP,
        //  0, 0, 1024, 768
        //  );
    }

    bool Image::isLoaded(){
        return loaded;
    }
    
    std::string Image::getPath(){
        return path;
    }

    GLuint Image::getTextureID(){
        return textureID;
    }
     
    int Image::getHeight(){
        return h;
    }
    
    int Image::getWidth(){
        return w;
    }
    
}