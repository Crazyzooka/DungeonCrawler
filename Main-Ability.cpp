#include "pch.h"

#include "Ability.h"
#include "Effect.h"
#include "Classlib.h"

#include <iostream>

using namespace std;

void createAbilities(Classlib * library)
{
    Ability Burning = Ability();
    Burning.Name = "Burning";
    Burning.Damage = 100;

	library->addClass(Burning);

	Ability Slash = Ability();
	Slash.Name = "Slash";
	Slash.Damage = 100;

	library->addClass(Slash);

	Ability Riposte = Ability();
	Riposte.Name = "Riposte";
	Riposte.Damage = 100;

	library->addClass(Riposte);

	Ability Stab = Ability();
	Stab.Name = "Stab";
	Stab.Damage = 100;

	library->addClass(Stab);
}