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

Item::Item(string i_Name, int i_Value, int i_Weight) 
{
    Name	= i_Name;
    Value	= i_Value;
    Weight	= i_Weight;
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

void Armour::SetDefense(int i_Defense) {
	Defense = i_Defense;
}

Armour::~Armour() {

}

Weapon::Weapon() 
{
	Damage = 0;
}

void Weapon::SetDamage(int i_Damage) {
	Damage = i_Damage;
}

Weapon::~Weapon() {

}

Consumable::Consumable() {

}

void Consumable::ApplyToAll(Entity Entity, int amount) {
	for (int i = 0; i < 6; i++) {
		LimbHP[i] -= amount;
	}
}

void Consumable::ApplyToLimb(int Limb, int amount) {
	LimbHP[Limb] -= amount;
}

Consumable::~Consumable() {

}