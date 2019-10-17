#include "Ability.h"
#include "Effect.h"
#include "Item.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

Ability::Ability(){}

int Ability::ApplyCost(Entity user, int cost)
{
	return 0;
}

Ability::~Ability(){}

Physical::Physical(){}

int Physical::ApplyCost(Entity user, int cost)
{
	return 0;
}

Physical::~Physical(){}

Magical::Magical(){}

int Magical::ApplyCost(Entity user, int cost)
{
	return 0;
}

Magical::~Magical(){}
