#include "pch.h"

#include <iostream>
#include <string>

#include "Combat.h"
#include "Ability.h"
#include "Item.h"
#include "Entity.h"
#include "Room.h"

using namespace std;

Combat::Combat()
{
}

void Combat::startCombat(Entity user, NPC RoomNPC)
{

}

void Combat::usePhysical(Entity user, Physical action, int limbHP, Weapon Weapon)
{
	user.limbHP[limbHP] -= user.stats[0] + action.Damage + Weapon.Damage;
}

void Combat::useMagical(Magical action)
{

}

void Combat::applyEffect(Entity person)
{

}

void Combat::endCombat (Entity user, NPC RoomNPC)
{

}

Combat::~Combat()
{
}
