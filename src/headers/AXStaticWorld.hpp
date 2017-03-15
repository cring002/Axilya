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
 * This class describes a AXStaticWorld, it holds and draws a single texture as a background.
 */
#ifndef AXStaticWorld_hpp
#define AXStaticWorld_hpp

#include "AXResourceManager.hpp"
#include "AXWorld.hpp"

class AXStaticWorld : public AXWorld {
    AXTexture* texture;
    AXResourceManager* resourceManager = AXResourceManager::getInstance();
public:
    AXStaticWorld();
    void loadTexture(int textureID);
    void loadTexture(AXTexture* t);
    void draw();
    void update();
};


#endif //Axilya_STATICWORLD_HPP
