#ifndef CLASSLIB_H
#define CLASSLIB_H

#include <iostream>

class Classlib
{
private:

	int intSize = 0;
	int *Integers = new int[0];

#ifdef ABILITY_H
	int abilitySize = 1;
	int effectSize  = 1;
	int itemSize	= 1;
	int NPCSize		= 1;
	Ability *Abilities	= new Ability[1];
	Effect	*Effects	= new Effect[1];
	Item	*Items		= new Item[1];
	NPC		*NPCs		= new NPC[1];
#endif

public:

	Classlib();

	void addInt(int number);

	int getInt(int index);

	void displayInt();

#ifdef ABILITY_H
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
#endif

	~Classlib();
};

#endif
