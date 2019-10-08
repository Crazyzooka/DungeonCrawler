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

Entity Room::GenerateNPCS(Entity newNPC){

}
void Room::ApplyEffect(Entity EffectEntity){

}

void Room::GenerateRoom(int numNPCs, Entity NPCs, Effect Effects, Item Items[], int numItems){
    NPC = NPCs;
    Effect Afflict = Effects;
    
    for(int i = 0; i < numItems; i++) {
        RoomItems[i].push_back(Items[i]);
    }
}

Room::~Room() {

}