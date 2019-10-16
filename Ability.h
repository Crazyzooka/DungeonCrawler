#ifndef ABILITY_H
#define ABILITY_H

#include "Effect.h"
#include "Entity.h"
#include "Item.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Ability
{
public:

    Ability();

    //VARIABLES

    string Name;
    int Damage;
    Effect toApply;

    vector<int> SkillsRequire[7];

    int ApplyCost(Entity user, int cost);

    ~Ability();
};

class Physical : public Ability
{
public:
	Physical();#include "Entity.h"

	virtual int ApplyCost(Entity user, int cost);

	~Physical();
};

class Magical : public Ability
{
public:
	Magical();

	virtual int ApplyCost(Entity user, int cost);

	~Magical();
};

#endif