#include "pch.h"

#include "Classlib.h"
//#include "Ability.h"
#include "Effect.h"
//#include "Item.h"
#include "Entity.h"
#include <iostream>

Classlib::Classlib()
{
	std::cout << "Class library created!\n";
}

#ifdef ABILITY_H

void Classlib::addClass(Ability ability)
{
	Ability *temp = new Ability[abilitySize + 1];

	for (int i = 0; i < abilitySize; i++)
	{
		temp[i] = Abilities[i];
	}

	Abilities = new Ability[abilitySize + 1];

	for (int i = 0; i < abilitySize; i++)
	{
		Abilities[i] = temp[i];
	}

	Abilities[abilitySize] = ability;

	abilitySize++;

	delete[] temp;
}

Ability Classlib::getAbility(int index)
{
	return Abilities[index];
}

void Classlib::displayAbilities()
{
	for (int i = 0; i < abilitySize; i++)
	{
		std::cout << "Index: " << i << " " << Abilities[i].Name << "\n";
	}
}

#endif

#ifdef EFFECT_H

void Classlib::addClass(Effect effect)
{
	Effect *temp = new Effect[effectSize + 1];

	for (int i = 0; i < effectSize; i++)
	{
		temp[i] = Effects[i];
	}

	Effects = new Effect[effectSize + 1];

	for (int i = 0; i < effectSize; i++)
	{
		Effects[i] = temp[i];
	}

	Effects[effectSize] = effect;

	effectSize++;

	delete[] temp;
}

Effect Classlib::getEffect(int index)
{
	return Effects[index];
}

void Classlib::displayEffects()
{
	for (int i = 0; i < effectSize; i++)
	{
		std::cout << "Index: " << i << " " << Effects[i].Name << "\n";
	}
}

#endif

#ifdef ITEM_H

void Classlib::addClass(Item item)
{
	Item *temp = new Item[itemSize + 1];

	for (int i = 0; i < itemSize; i++)
	{
		temp[i] = Items[i];
	}

	Items = new Item[itemSize + 1];

	for (int i = 0; i < itemSize; i++)
	{
		Items[i] = temp[i];
	}

	Items[itemSize] = item;

	itemSize++;

	delete[] temp;
}

Item Classlib::getItem(int index)
{
	return Items[index];
}

void Classlib::displayItems()
{
	for (int i = 0; i < itemSize; i++)
	{
		std::cout << "Index: " << i << " " << Items[i].Name << "\n";
	}
}

#endif

#ifdef ENTITY_H

void Classlib::addClass(NPC npc)
{
	NPC *temp = new NPC[NPCSize + 1];

	for (int i = 0; i < NPCSize; i++)
	{
		temp[i] = NPCs[i];
	}

	NPCs = new NPC[NPCSize + 1];

	for (int i = 0; i < NPCSize; i++)
	{
		NPCs[i] = temp[i];
	}

	NPCs[NPCSize] = npc;

	NPCSize++;

	delete[] temp;
}

NPC	Classlib::getNPC(int index)
{
	return NPCs[index];
}

void Classlib::displayNPCs()
{
	for (int i = 0; i < NPCSize; i++)
	{
		std::cout << "Index: " << i << " " << NPCs[i].Name << "\n";
	}
}

#endif

Classlib::~Classlib() 
{

#ifdef ABILITY_H
	delete[] Abilities;
#endif
#ifdef EFFECT_H
	delete[] Effects;
#endif
#ifdef ITEM_H
	delete[] Items;
#endif
#ifdef ENTITY_H
	delete[] NPCs;
#endif

	std::cout << "Class library destroyed!\n";
};
