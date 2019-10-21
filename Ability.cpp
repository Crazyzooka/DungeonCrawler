#include "pch.h"

#include "Ability.h"
#include "Effect.h"
#include "Item.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

Ability::Ability(){
	Name = "?";
}

int Ability::ApplyCost()
{
	return Damage;
}

Ability::~Ability(){}

Physical::Physical(){}

int Physical::ApplyCost()
{
	return Damage;
}

Physical::~Physical(){}

Magical::Magical(){}

int Magical::ApplyCost()
{
	return Damage;
}

Magical::~Magical(){}
