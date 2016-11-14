//
//  main.cpp
//  Axilya
//
//  Created by William Meaton on 07/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//
#include "CoreMain.h"
#include "myCore/frameworkCore.hpp"
#include "myCore/engineCore.hpp"

int main(int argc, char *argv[])
{
	//set the run path
	Runner::runPath = argv[0];
    //start a new runner with the constructor
    //Runner(int width, int height, const char* title, new "corename");
    //there are two example cores given with the repo, frameworkCore and engineCore
    //framework core is for showing off the simple framework code
    //engine core is for showing off the ECS and engine code
    Runner(720, 480, "Axilya", new engineCore());
}