#ifndef GAMEDATA_H
#define GAMEDATA_H

#include "Classlib.h"
#include "Entity.h"

enum stats
{
	Strength = 0,
	Perception = 1,
	Endurance = 2,
	Charisma = 3,
	Intelligence = 4,
	Agility = 5,
	Luck = 6
	Experience = 7;
};

enum limbs
{
	Head = 0,
	Body = 1,
	ArmR = 2,
	ArmL = 3,
	LegR = 4,
	LegL = 5
};

Entity createCharacter();
Classlib createGameData();

#endif