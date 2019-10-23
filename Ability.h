#ifndef ABILITY_H
#define ABILITY_H

#include "Item.h"
#include "Entity.h"

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
	int Cost;

	vector<int> SkillsRequire = { 0,0,0,0,0,0,0 };

    virtual void ApplyCost();

    ~Ability();
};

class Physical : public Ability
{
public:
	Physical();

	void ApplyCost(Entity * user);

	~Physical();
};

class Magical : public Ability
{
public:
	Magical();

	void ApplyCost(Entity * user);

	~Magical();
};

#endif
