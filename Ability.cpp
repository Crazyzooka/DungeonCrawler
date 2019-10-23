#include "pch.h"

#include "Ability.h"

#include "Item.h"
#include "GameData.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

Ability::Ability(){
	Name = "?";
	Damage = 50;
	Cost = 10;
}

void Ability::ApplyCost()
{

}

Ability::~Ability(){}

Physical::Physical(){}

void Physical::ApplyCost(Entity * user)
{

}

Physical::~Physical(){}

Magical::Magical(){}

void Magical::ApplyCost(Entity * user)
{
	user->mana -= Cost;
}

Magical::~Magical(){}
