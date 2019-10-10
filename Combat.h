#ifndef COMBAT_H
#define COMBAT_H

#include <string>

using namespace std;

class Combat
{
public:
	int whosTurn;
	NPC opponent;

	Combat();

	void startCombat(Player user, NPC Room.NPC);
	void useAbility(int whosTurn, Ability action);
	void applyEffect(Entity person);
	void endCombat(Player user, NPC Room.NPC);

	~Combat();
};
#endif