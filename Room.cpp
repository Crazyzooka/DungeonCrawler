#include "pch.h"
#include "Item.h"
#include "Room.h"
#include "Entity.h"
#include "Functions.h"
#include "Classlib.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

Room::Room() {

}

void Room::GenerateNPCS(Entity newNPC)
{   

}

void Room::ApplyEffect(Entity Entity)
{

}

//Generates Room when called with random NPC and items
void Room::GenerateRoom(NPC NPCs, Player Player, Classlib *library)
{
	int numItems = myRandom(5);

	RoomItems.resize(numItems);
	nonPlayer	= NPCs;
	Player		= Player;
	RoomName	= "Room";

	for (int i = 0; i < numItems; i++) {
		RoomItems[i] = library->getItem(myRandom(library->itemSize-1));
	}
}

Entity Room::GetNPC() {
    return nonPlayer;
}

Room::~Room() {

}