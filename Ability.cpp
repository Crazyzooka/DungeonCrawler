#include "pch.h"
#include "Ability.h"
#include "Effect.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

Ability::Ability() 
{
    Name	= " ";
    Damage	= 0;
    //toApply	= Effect;
}

Ability::Ability(string i_Name, int i_Damage, Effect i_Effect) 
{
    Name = i_Name;
    Damage = i_Damage;
    //Effect = i_Effect;
}

Ability::~Ability() {

}