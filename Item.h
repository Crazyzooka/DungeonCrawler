#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <vector>


#include "Entity.h"

using namespace std;

class Item 
{
public:

		Item();
		Item(string i_Name, int i_Value, int i_Weight);
		string Name; // Name of Item
		int Value; // Item Value
		int Weight; // Item Weight
		int Limb;
		bool Equipped;

		void test();

		~Item();
};

class Equipment : public Item {
public:
	Equipment(string i_Name, int i_Value, int i_Weight);
	int Condition; // Condition of the Equipment
	vector<int> SkillsRequire = { 0,0,0,0,0,0,0 };
	~Equipment();
};

class Consumable : public Item {
public:
	Consumable(string i_Name, int i_Value, int i_Weight);
	int size;
	void ApplyToAll(Entity Entity); //Apply to all limbs
	void ApplyToLimb(Entity Entity, int Limb); //Apply to a specific limb

	~Consumable();
};

class Armour : public Equipment {
public:
	Armour(string i_Name, int i_Value, int i_Weight);
	int Defense; //Defense level
	~Armour();
};

class Weapon : public Equipment {
public:
	Weapon(string i_Name, int i_Value, int i_Weight);
	int Damage; //Damage level
	~Weapon();
};



#endif