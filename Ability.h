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

    virtual int ApplyCost();

    ~Ability();
};

class Physical : public Ability
{
public:
	Physical();

	int ApplyCost();

	~Physical();
};

class Magical : public Ability
{
public:
	Magical();

int ApplyCost();

	~Magical();
};

#endif
