#include "pch.h"
#include <iostream>

#include "Item.h"
#include "Classlib.h"
#include "GameData.h"

using namespace std;

void createItems(Classlib *library)
{
    Weapon Sword = Weapon("Sword", 25, 10);
    Sword.Damage = 70;
    Sword.Condition = 100;
    Sword.Limb = RightArm;

	library->addClass(Sword);

    Weapon Axe = Weapon("Axe", 25, 20);
    Axe.Damage = 75;
    Axe.Condition = 110;
    Axe.Limb = RightArm;

	library->addClass(Axe);

    Weapon Dagger = Weapon("Dagger", 15, 5);
    Dagger.Damage = 30;
    Dagger.Condition = 100;
    Dagger.Limb = RightArm;

	library->addClass(Dagger);

    Armour Shield = Armour("Shield", 20, 20);
    Shield.Defense = 100;
    Shield.Condition = 100;
    Shield.Limb = LeftArm;

	library->addClass(Shield);

    Consumable MedKit = Consumable("Medkit", 25, 10);
    MedKit.size = 100;

	library->addClass(MedKit);

    Consumable Bandages = Consumable("Bandages", 15, 5);
    Bandages.size = 50;

	library->addClass(Bandages);
}