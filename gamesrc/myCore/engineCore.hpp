//
//  engineCore.hpp
//
//  Created by William Meaton on 08/12/2015.
//  Copyright © 2015 WillMeaton.uk. All rights reserved.
//
#ifndef engineCore_hpp
#define engineCore_hpp

#include <CoreMain.h>
#include <RigidBodyMove.hpp>
#include <TransformMove.hpp>
#include <Destroyable.hpp>
#include <exampleTileComponent.hpp>
#include <GameMaster.hpp>


class engineCore : public BaseCore{
public:
    void setup();
    void loadTiles();
    Scene* scene1 = 0;
    TiledWorld* tileWorld = 0;
    StaticWorld* staticWorld = 0;
    Entity* barrier = 0;
    Entity* character2 = 0;
    Entity* gameMaster = 0;
    int tile1ID, backgroundID;
};

#endif /* engineCore_hpp */
