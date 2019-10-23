#ifndef COMBAT_H
#define COMBAT_H

#include <string>
#include "Ability.h"
#include "Entity.h"

using namespace std;

class Combat
{
public:

	int whosTurn;		//Value which determines whether the player or the enemy can perform an action
	NPC opponent;		//Enemy faced by the player

	Combat();

	void startCombat(Player user, NPC RoomNPC);
	void usePhysical(Physical action);
	void useMagical(Magical action);
	void applyEffect(Entity person);
	void endCombat (Player user, NPC RoomNPC);

	~Combat();
};
#endif