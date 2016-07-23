//
//  Core.hpp
//  GLFW3
//
//  Created by William Meaton on 08/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//
#ifndef Core_hpp
#define Core_hpp
#include <CoreMain.h>
#include <exampleComponent.hpp>
#include <Destroyable.hpp>

class Core : public BaseCore{
public:
    void draw();
    void update();
    void setup();
    Scene* scene1 = 0;
    Entity* character1 = 0;
    Entity* character2 = 0;
};

#endif /* Core_hpp */
