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
		//VARIABLES

		string Name;
		vector<string> Effects;
		int Value;
		int Weight;

		~Item();
};

class Equipment : public Item {
public:
	Equipment();

	//VARIABLES
	int Condition;
	int Limb;

	vector<int> SkillsRequire[5];

	~Equipment();
};

class Consumable : public Item {
public:
	Consumable();

	//VARIABLES
	int size;

	//FUNCTIONS
	void ApplyToAll(Entity user, int amount);
	void ApplyToLimb(int Limb, int amount);

	~Consumable();
};

class Armour : public Equipment {
public:
	Armour();

	//VARIABLES
	int Defense;

	//FUNCTIONS
	void SetDefense(int i_Damage);
	~Armour();
};

class Weapon : public Equipment {
public:
	Weapon();

	//VARIABLES
	int Damage;

	//FUNCTIONS
	void SetDamage(int i_Damage);
	~Weapon();
};



#endif