#include "pch.h"

#include "Item.h"
#include "Room.h"
#include "Entity.h"
#include "Effect.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

Room::Room() {

}

void Room::GenerateNPCS(Entity newNPC)
{   
    NPC = newNPC;
}

void Room::ApplyEffect(Entity Entity)
{
    //Entity.Effect = RoomEffect;
}

void Room::GenerateRoom(int numNPCs, Entity NPCs, Effect Effects, vector<Item> Items, int numItems){
    NPC = NPCs;
    Effect Afflict = Effects;
    
    //RoomItems.push_back(Items);
    
}

Room::~Room() {

}
