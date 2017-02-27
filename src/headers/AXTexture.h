/**
 * @file
 * @author William Meaton <will.meaton@gmail.com>
 *
 * @section LICENSE
 *
 * The MIT License
 * 
 * Copyright (c) 2017 WillMeaton http://willmeaton.com
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * @section DESCRIPTION
 *
 * This is used to hold texture data and the ID given by the ResourceManager.
 */
#ifndef AXTexture_H
#define AXTexture_H
#include "AXImage.hpp"

class AXTexture{
	AXImage* img = 0;
    int id = -1;
public:
	/*!
   * The constructor of an AXTexture 
   * @param id the ID provided when created by the ResourceManager
   * @param img the AXImage data that's loaded by the ResourceManager
   */  
    AXTexture(int id, AXImage* img) : id(id), img(img){}
    /*!
   * The deconstructor of an AXTexture 
   * 
   * This will free the image data, do not manually delete resources loaded by the ResourceManger
   */  
    ~AXTexture(){ delete img; img = 0;}
  /*!
   * A method to get the ID of this AXTexture 
   * 
   * @return The ID of this texture
   */  
    int getID(){ return id; }
  /*!
   * A method to get the AXImage data of this AXTexture 
   * 
   * @return The image data of this texture
   */  
	AXImage* getImage(){ if(img) {return img;} else {return 0;} }
};
#endif