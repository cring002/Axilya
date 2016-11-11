//
//  Runner.cpp
//  GLFW3
//
//  Created by William Meaton on 09/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//

#include "Runner.hpp"
float Runner::r;
float Runner::g;
float Runner::b;
float Runner::a;
BaseCore* Runner::c = 0;
Scene* Runner::activeScene = 0;
std::string Runner::runPath = "";
int Runner::go = 1;
Runner::Runner(float windowWidth, float windowHeight, int frameRate, const char* title, BaseCore* c){
    //The window we'll be rendering to

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    //Create window
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if( window == NULL )
    {
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
    }
    //make a renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    Runner::c = c;
    gladLoadGLLoader(SDL_GL_GetProcAddress);

    //set blend mode
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

    c->setWindow(window);
    c->windowHeight = windowHeight;
    c->windowWidth = windowWidth;
    Input::init();
    c->setup();
    if(activeScene){
       activeScene->start();
    }
    SDL_Event event;
    // glColor4f(1, 1, 1, 1);
    while(go == 1){
        while( SDL_PollEvent( &event ) != 0 ){
            //User requests quit
            if(event.type == SDL_QUIT){
                c->exitCalled();
            }else if( event.type == SDL_KEYDOWN){
                Input::setKeyDown(event.key.keysym.scancode);
            }else if(event.type == SDL_KEYUP){
                if(event.key.keysym.scancode == SDL_SCANCODE_ESCAPE){
                    c->exitCalled();
                    break;
                }
                Input::setKeyUp(event.key.keysym.scancode);
            }else if(event.type == SDL_MOUSEMOTION){
                Input::mouseX = event.motion.x;
                Input::mouseY = event.motion.y;
            }else if(event.type == SDL_MOUSEBUTTONDOWN){
                Input::mousePressed(event.button.button);
            }else if(event.type == SDL_MOUSEBUTTONUP){
                Input::mouseReleased(event.button.button);
            }
        }
        if(activeScene) {
            activeScene->update();
        }
        //Fill the surface white
        // std::cout << Runner::r << " " << std::cout << g << std::endl;
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        if(activeScene) {
            activeScene->draw();
        }
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyWindow(window);
    //Quit SDL subsystems
    SDL_Quit();
    exit(EXIT_SUCCESS);
}

void Runner::setCurrentScene(Scene *s) {
    if(s) {
        activeScene = s;
    }
}

int Runner::getHeight(){
    return Runner::c->windowHeight;
}

int Runner::getWidth(){
    return Runner::c->windowWidth;
}

void Runner::shutdown(){
    Runner::go = 0;
}
