#include "pch.h"
#include "ClassLib.h"
#include <iostream>

Classlib::Classlib()
{
	std::cout << "Class library created!\n";
}

//testing functions with integers as members

void Classlib::addInt(int number)
{
	int *temp = new int[intSize + 1];

	for (int i = 0; i < intSize; i++)
	{
		temp[i] = Integers[i];
	}

	Integers = new int[intSize + 1];

	for (int i = 0; i < intSize; i++)
	{
		Integers[i] = temp[i];
	}

	Integers[intSize] = number;

	intSize++;

	delete[] temp;
}

int Classlib::getInt(int index)
{
	return Integers[index];
}

void Classlib::displayInt()
{
	for (int i = 0; i < intSize; i++)
	{
		std::cout << "Index: " << i << " " << Integers[i] << "\n";
	}
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

void Classlib::addClass(Item item)
{
	Item *temp = new item[itemSize + 1];

	for (int i = 0; i < itemSize; i++)
	{
		temp[i] = Items[i];
	}

	Items = new Item[itemSize + 1];

	for (int i = 0; i < abilitySize; i++)
	{
		Abilities[i] = temp[i];
	}

	Items[itemSize] = item;

	itemSize++;

	delete[] temp;
}

void Classlib::addClass(NPC npc)
{
	NPC *temp = new NPC[npcSize + 1];

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

Ability Classlib::getAbility(int index)
{
	return Abilities[index];
}

Effect Classlib::getEffect(int index)
{
	return Effects[index];
}

Item Classlib::getItem(int index)
{
	return Items[index];
}

NPC	Classlib::getNPC(int index)
{
	return NPCs[index];
}

void Classlib::displayAbilities()
{
	for (int i = 0; i < abilitySize; i++)
	{
		std::cout << "Index: " << i << " " << Abilities[i].name << "\n";
	}
}

void Classlib::displayEffects()
{
	for (int i = 0; i < effectSize; i++)
	{
		std::cout << "Index: " << i << " " << Effects[i].name << "\n";
	}
}

void Classlib::displayItems()
{
	for (int i = 0; i < itemSize; i++)
	{
		std::cout << "Index: " << i << " " << Items[i].name << "\n";
	}
}

void Classlib::displayNPCs()
{
	for (int i = 0; i < NPCSize; i++)
	{
		std::cout << "Index: " << i << " " << NPCs[i].name << "\n";
	}
}

#endif

Classlib::~Classlib() 
{
#ifdef ABILITY_H
	delete[] Abilities;
	delete[] Effects;
	delete[] Items;
	delete[] NPCs;
#endif

	std::cout << "Class library destroyed!\n";

};