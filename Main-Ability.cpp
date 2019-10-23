#include "pch.h"

#include "Ability.h"

#include "Classlib.h"

#include <iostream>

using namespace std;

void createAbilities(Classlib * library)
{
	Ability Slash = Ability();
	Slash.Name = "Slash";
	Slash.Damage = 100;

	library->addClass(Slash);

    Magical Firebolt = Magical();
	Firebolt.Name = "Firebolt";
	Firebolt.Damage = 100;
	Firebolt.SkillsRequire = { 0,0,0,0,10,0,0 };

	library->addClass(Firebolt);

	Ability Riposte = Ability();
	Riposte.Name = "Riposte";
	Riposte.Damage = 100;
	Riposte.SkillsRequire = { 10,0,0,0,0,0,0 };

	library->addClass(Riposte);

	Ability Stab = Ability();
	Stab.Name = "Stab";
	Stab.Damage = 100;

	library->addClass(Stab);
}