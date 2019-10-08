#ifndef ABILITY_H
#define ABILITY_H

#include"Effect.h"

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
    Effect Effect;

    vector<Entity> SkillsRequired[];

    int ApplyCost()=0;

    ~Ability();
}
#endif