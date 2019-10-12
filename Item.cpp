#include "pch.h"

#include "Item.h"
#include "Entity.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

Item::Item() 
{
    Name	= "?";
    Value	= 0;
    Weight	= 0;
}

Item::~Item() {

}

Equipment::Equipment() {
	Condition = 0;
	Limb = 0;
}

Equipment::~Equipment() {

}

Armour::Armour()
{
	Defense = 0;
}

Armour::~Armour() {

}

Weapon::Weapon() 
{
	Damage = 0;
}

Weapon::~Weapon() {

}

Consumable::Consumable() {

}

void Consumable::ApplyToAll(Entity Entity) {
	size = 0;
	for (int i = 0; i < size; i++) {

	}
}

void Consumable::ApplyToLimb(int Limb) {

}

Consumable::~Consumable() {

}