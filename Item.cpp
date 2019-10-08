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

Item::Item(string i_Name, int i_Value, int i_Weight) {
    Name = i_Name;
    Value = i_Value;
    Weight = i_Weight;
}

Item::~Item() {

}

Equipment::Equipment(string i_Name, int i_Value, int i_Weight) {
	Condition = 0;
	Limb = 0;
}

void Equipment::SetEquipment(int i_Condition, int i_Limb) {
	Condition = i_Condition;
	Limb = i_Limb;
}

Equipment::~Equipment() {

}

Armour::Armour(string i_Name, int i_Value, int i_Weight) :Item(i_Name, i_Value, i_Weight) {
	Defense = 0;
}

void Armour::SetDefense(int DefenseHP) {
	Defense = DefenseHP;
}

Armour::~Armour() {

}

Weapon::Weapon(string i_Name, int i_Value, int i_Weight) :Item(i_Name, i_Value, i_Weight) {
	Damage = 0;
}

void Weapon::SetDamage(int DamageHP) {
	Damage = DamageHP;
}

Weapon::~Weapon() {

}

Consumable::Consumable() {

}

void Consumable::ApplyToAll(Entity Entity) {
	size = LimbHP.size();
	for (int i = 0; i < size; i++) {

	}
}

void Consumable::ApplyToLimb(int Limb) {

}

Consumable::~Consumable() {

}