#include "pch.h"

#include <iostream>
#include <string>

#include "Combat.h"
#include "Ability.h"
#include "Entity.h"
#include "Room.h"

using namespace std;

Combat::Combat()
{
}

void Combat::startCombat(Player user, NPC RoomNPC)
{

}

void Combat::usePhysical(Player user, Physical action, int limb)
{
	NPC.limbHP[limb] -= Player.stats[0] +
}

void Combat::useMagical(Magical action)
{

}

void Combat::applyEffect(Entity person)
{

}

void Combat::endCombat (Player user, NPC RoomNPC)
{

}

Combat::~Combat()
{
}
