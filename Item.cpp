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

Equipment::Equipment(string i_Name, int i_Value, int i_Weight):Item(i_Name, i_Value, i_Weight) {
	Condition = 0;
	Limb = 0;
}

Equipment::~Equipment() {

}

Armour::Armour(string i_Name, int i_Value, int i_Weight):Equipment(i_Name, i_Value, i_Weight)
{
	Defense = 0;
}

void Armour::SetDefense(int i_Defense) {
	Defense = i_Defense;
}

Armour::~Armour() {

}

Weapon::Weapon(string i_Name, int i_Value, int i_Weight):Equipment(i_Name, i_Value, i_Weight)
{
	Damage = 0;
}

void Weapon::SetDamage(int i_Damage) {
	Damage = i_Damage;
}

Weapon::~Weapon() {

}

Consumable::Consumable(string i_Name, int i_Value, int i_Weight):Item(i_Name, i_Value, i_Weight) {
	size = 0;
}

void Consumable::setSize(int i_size) {
	size = i_size;
}

void Consumable::ApplyToAll(Entity Entity) {
	for (int i = 0; i < 6; i++) {
		Entity.limbHP[i] -= size;
	}
}

void Consumable::ApplyToLimb(Entity Entity, int Limb) {
	Entity.limbHP[Limb] -= size;
}

Consumable::~Consumable() {

}
