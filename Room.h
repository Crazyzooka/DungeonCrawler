#ifndef ROOM_H
#define ROOM_H

#include "Item.h"
#include "Entity.h"
#include "Classlib.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Room {

public:
    Room();

    //VARIABLES
    string RoomName;
    Player User;
    NPC nonPlayer;
    vector<Item> RoomItems;
    string Description;
    int numItems;
    
    //FUNCTIONS
    void GenerateNPCS(Entity newNPC);
    void ApplyEffect(Entity EffectEntity);
    void GenerateRoom(NPC NPCs, Player Player, Classlib * library); //Generates Room when called with random NPC and items
    Entity GetNPC();

    ~Room();
};
#endif