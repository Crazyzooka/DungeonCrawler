#ifndef ROOM_H
#define ROOM_H

#include "Item.h"
#include "Entity.h"
#include "Effect.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Room {

public:
    Room();

    //VARIABLES
    string RoomName;
    Entity Player;
    Entity NPC;
    vector<Item> RoomItems;
    string Description;
    Effect RoomEffect;
    int numItems;
    
    //FUNCTIONS
    void GenerateNPCS(Entity newNPC);
    void ApplyEffect(Entity EffectEntity);
    void GenerateRoom(Entity NPCs, Effect Effects, Entity Player);
    Entity GetNPC();

    ~Room();
};
#endif