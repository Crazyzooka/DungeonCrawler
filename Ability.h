#ifndef ABILITY_H
#define ABILITY_H

#include "Effect.h"
#include "Entity.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Ability
{
public:

    Ability();
    Ability(string i_Name, int i_Damage, Effect i_Effect);

    //VARIABLES

    string Name;
    int Damage;
    Effect toApply;

    vector<Entity> SkillsRequire[];

    virtual int ApplyCost() = 0;

    ~Ability();
};

#endif