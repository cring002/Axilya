//
//  BaseCore.cpp
//  GLFW3
//
//  Created by William Meaton on 09/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#include "BaseCore.hpp"
#include "Runner.hpp"

GLFWwindow*& BaseCore::getWindow(){
    return window;
}

BaseCore::~BaseCore(){
    if(Client::getInstance()->isConnected()){
        Client::getInstance()->disconnect();
    }
}

void BaseCore::exitCalled(){
	Runner::shutdown();
}