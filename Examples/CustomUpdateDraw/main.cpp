//
//  main.cpp
//  Axilya
//
//  Created by William Meaton on 31/01/2017.
//  Copyright © 2017 willmeaton.com. All rights reserved.
//
#include <Axilya/AXMain.h>

int x = 0;
void update(){
    if(AXInput::getValue("D")){
        x++;
    }
}

void draw(){
    //using the AXGraphics namespace you can draw raw shapes, lines and points 
    AXGraphics::drawRect(x, 50, 50, 50);
}

int main(int argc, char *argv[])
{
    //You can use axilya like a framework by passing the window update and draw methods
    if(!AXWindow::init(720, 480, AX_WINDOWED, "Custom Update Draw", update, draw)){
    	std::cout << "AXWindow failed to initialise" << std::endl;
    	return -1;
    }
    //return the window run, this is where the update and draw will be called
    return AXWindow::run();
}