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
		string Name;
		int Value;
		int Weight;

		void test();

		~Item();
};

class Equipment : public Item {
public:
	Equipment(string i_Name, int i_Value, int i_Weight);
	int Condition;
	int Limb;
	vector<int> SkillsRequire = { 0,0,0,0,0,0,0 };
	~Equipment();
};

class Consumable : public Item {
public:
	Consumable(string i_Name, int i_Value, int i_Weight);
	int size;
	void ApplyToAll(Entity Entity);
	void ApplyToLimb(Entity Entity, int Limb);

	~Consumable();
};

class Armour : public Equipment {
public:
	Armour(string i_Name, int i_Value, int i_Weight);
	int Defense;
	~Armour();
};

class Weapon : public Equipment {
public:
	Weapon(string i_Name, int i_Value, int i_Weight);
	int Damage;
	~Weapon();
};



#endif