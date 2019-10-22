#ifndef COMBAT_H
#define COMBAT_H

#include <string>
#include "Ability.h"
#include "Item.h"
#include "Room.h"
#include "Combat.h"
#include "Entity.h"

using namespace std;

class Combat
{
public:

	int whosTurn;
	NPC opponent;

	Combat();

	void startCombat(Entity user, NPC RoomNPC);
	void usePhysical(Entity user, Physical action,int limbHP, Weapon Weapon);
	void useMagical(Magical action);
	void applyEffect(Entity person);
	void endCombat (Entity user, NPC RoomNPC);

	~Combat();
};
#endif