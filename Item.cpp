#include "pch.h"

#include "Item.h"
#include "Entity.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Default constructor
Item::Item() 
{
    Name	 = " ";
    Value	 = 0;
    Weight	 = 0;
	Equipped = false;
}

// Constructor that allocates the parameters to their respective variables.
Item::Item(string i_Name, int i_Value, int i_Weight) 
{
    Name	 = i_Name;
    Value	 = i_Value;
    Weight 	 = i_Weight;
	Equipped = false;
}

void Item::test()
{
	std::cout << "Tested: " << Name << "\n";
}

Item::~Item() {
	
}

Equipment::Equipment(string i_Name, int i_Value, int i_Weight):Item(i_Name, i_Value, i_Weight) {
	Condition = 200;
	Limb = 0;
}

Equipment::~Equipment() {

}

Armour::Armour(string i_Name, int i_Value, int i_Weight):Equipment(i_Name, i_Value, i_Weight)
{
	Defense = 0;
}

Armour::~Armour() {

}

Weapon::Weapon(string i_Name, int i_Value, int i_Weight):Equipment(i_Name, i_Value, i_Weight)
{
	Damage = 0;
}

Weapon::~Weapon() {

}

Consumable::Consumable(string i_Name, int i_Value, int i_Weight):Item(i_Name, i_Value, i_Weight) {
	size = 0;
	Limb = -1;
}

// Function that applies the consumable to all limbs
void Consumable::ApplyToAll(Entity Entity) {

}

// Function that applies the consumable to a specific limbs
void Consumable::ApplyToLimb(Entity Entity, int Limb) {

}

Consumable::~Consumable() {

}