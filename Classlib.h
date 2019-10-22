#ifndef CLASSLIB_H
#define CLASSLIB_H

#include <iostream>

#include "Ability.h"
#include "Effect.h"
#include "Item.h"
#include "Entity.h"

class Classlib
{
private:

	int abilitySize = 0;
	int effectSize  = 0;
	int itemSize	= 0;
	int NPCSize		= 0;

	Ability *Abilities	= new Ability[0];
	Effect	*Effects	= new Effect[0];
	Item	*Items		= new Item[0];
	NPC		*NPCs		= new NPC[0];

public:

	Classlib();

	void addClass(Ability ability);
	void addClass(Effect effect);
	void addClass(Item item);
	void addClass(NPC npc);

	Ability getAbility(int index);
	Effect	getEffect(int index);
	Item	getItem(int index);
	NPC		getNPC(int index);

	void displayAbilities();
	void displayEffects();
	void displayItems();
	void displayNPCs();

	~Classlib();
};

#endif
