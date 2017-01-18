#ifndef Input_hpp
#define Input_hpp

#include <vector>
#include <unordered_map>
#include "Key.h"
#include <SDL2/SDL.h>
#define AX_INPUT_CONTROLLER_OFFSET 300
class Input{
    Input(){};
    ~Input(){};
    static std::unordered_map<int, Key*> keyCodes;
    static std::unordered_map<std::string, Key*> keyNames;
    static std::vector<Key*> keys;
    
    static int keysPressed, mouseButtonsPressed;
    public:
    static SDL_GameController* controller;
    static bool keyIsPressed, mouseIsPressed;
    static int keyCode, mouseButton;
    static int mouseX, mouseY;
    static void init();
    static void setKeyDown(int key);
    static void setKeyUp(int key);
    static void mousePressed(int button);
    static void mouseReleased(int button);
    static bool keyUp();
    static bool keyDown();
    static bool keyRight();
    static bool keyLeft();
    static bool getKey(const std::string& key);
};

#endif
