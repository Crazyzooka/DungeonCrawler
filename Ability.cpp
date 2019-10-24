#include "pch.h"

#include "Ability.h"

#include "Item.h"
#include "GameData.h"
#include "Functions.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

Ability::Ability(){
	Name = "?";
	Damage = 50;
	Cost = 10;
}

void Ability::ApplyCost(Entity * player) {}

bool Ability::CalculateChance(Entity * user) {

	if ((myRandom(user->stats[Perception]) + myRandom(user->stats[Luck]) + myRandom(100)) >= 50)
	{
		return true;
	}

	return false;
}

Ability::~Ability(){}

Physical::Physical(){}

void Physical::ApplyCost(Entity * user)
{

	user->stamina -= Cost;
}

bool Physical::CalculateChance(Entity * user)
{
	int random = (myRandom(user->stats[Intelligence]) + myRandom(user->stats[Perception]) + myRandom(100));
	std::cout << random;

	if (random >= 50)
	{
		return true;
	}

	return false;
}

Physical::~Physical(){}

Magical::Magical(){}

bool Magical::CalculateChance(Entity * user)
{
	int random = (myRandom(user->stats[Intelligence]) + myRandom(user->stats[Perception]) + myRandom(100));
	std::cout << random;

	if (random >= 50)
	{
		return true;
	}

	return false;
}

void Magical::ApplyCost(Entity * user)
{
	user->mana -= Cost;
}

Magical::~Magical(){}
