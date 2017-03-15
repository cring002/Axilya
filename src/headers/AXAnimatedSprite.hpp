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
 * This class describes an AXAnimatedSprite, it loops through textures at a set frame count.
 *
 */
#ifndef AXAnimatedSprite_hpp
#define AXAnimatedSprite_hpp
#include "AXSprite.hpp"
class AXAnimatedSprite : public AXSprite {
    //the amount of frames per image
    int frameLength;
    std::vector<AXTexture*> textures;
    //current frame we're on
    int frameCount;
    //the current texture being drawn
    int texturePosition;
public:
   /*!
   * The destructor of an AXAnimatedSprite
   *
   * This will destruct the current class but will not delete the AXTexture's attached.
   */
    ~AXAnimatedSprite();
   /*!
   * The constructor of an AXAnimatedSprite
   * @param name the name of this AXAnimatedSprite
   * @param frameLength how many frames each AXTexture will be displayed for
   */
    AXAnimatedSprite(const std::string& name, int frameLength);
   /*!
   * A method to draw the AXAnimatedSprite
   * @param x the x position to draw the sprite
   * @param y the y position to draw the sprite
   * @param w the width to draw the sprite
   * @param h the height to draw the sprite
   */
    void draw(float x, float y, float w, float h);
   /*!
   * A method to add another frame to the AXAnimatedSprite
   * @param textureID the ID of a texture given by the AXResourceManager
   */
    void addTexture(int textureID);
   /*!
   * A method to add another frame to the AXAnimatedSprite
   * @param filename the filename of an image to be loaded by the AXResourceManager
   * @return the ID of the AXTexture loaded by the AXResourceManager
   */
    int addTexture(const std::string& filename);
   /*!
   * A method to clone this AXSprite
   * @return a clone of this AXAnimatedSprite
   */
    AXSprite* clone();
};


#endif
