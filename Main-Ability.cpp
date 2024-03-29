#include "pch.h"

#include "Ability.h"

#include "Classlib.h"

#include <iostream>

using namespace std;

void createAbilities(Classlib * library)
{
	Ability * Slash = new Physical();

	Slash->Name		= "Slash";
	Slash->Damage	= 30;
	Slash->Cost		= 10;

	library->addClass(*Slash);

    Ability * Firebolt = new Magical();

	Firebolt->Name			= "Firebolt";
	Firebolt->Damage			= 30;
	Firebolt->Cost			= 20;
	Firebolt->SkillsRequire	= { 0,0,0,0,10,0,0 };

	library->addClass(*Firebolt);

	Physical * Riposte = new Physical();

	Riposte->Name			= "Riposte";
	Riposte->Damage			= 25;
	Riposte->SkillsRequire	= { 10,0,0,0,0,0,0 };
	Riposte->Cost			= 20;

	library->addClass(*Riposte);

	Physical * Stab = new Physical();

	Stab->Name	= "Stab";
	Stab->Damage = 50;
	Stab->Cost	= 50;

	library->addClass(*Stab);
}