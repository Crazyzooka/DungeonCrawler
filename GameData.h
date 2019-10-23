#ifndef GAMEDATA_H
#define GAMEDATA_H

#include "Entity.h"
#include "Classlib.h"
#include "Item.h"
#include <vector>

enum stats
{
	Strength = 0,
	Perception = 1,
	Endurance = 2,
	Charisma = 3,
	Intelligence = 4,
	Agility = 5,
	Luck = 6,
	Experience = 7,
};

enum limbs
{
	Head = 0,
	Body = 1,
	RightArm = 2,
	LeftArm = 3,
	RightLeg = 4,
	LeftLeg = 5,
};

void CreateChar(Player * player);
void ChooseStats(Player * player);
void ChooseAbilities(Player * player, Classlib * library);
std::vector<Item> ChooseItems(vector<Item> playerInv, Player * player, Classlib * library);

#endif