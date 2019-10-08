#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Item {
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
	Equipment(string i_Name, int i_Value, int i_Weight);

	//VARIABLES
	int Condition;
	int Limb;

	vector<int> SkillsRequire[5];

	//FUNCTIONS
	void SetEquipment(int i_Condition, int i_Limb);

	~Equipment();
};

class Consumable : public Item {
public:
	Consumable();

	//VARIABLES
	int size;

	//FUNCTIONS
	void ApplyToAll(Entity Entity);
	void ApplyToLimb(int Limb);

	~Consumable();
};

class Armour : public Equipment {
public:
	Armour(string i_Name, int i_Value, int i_Weight);
	void SetDefense(int DefenseHP);

	//VARIABLES
	int Defense;
	~Armour();
};

class Weapon : public Equipment {
public:
	Weapon(string i_Name, int i_Value, int i_Weight);
	void SetDamage(int DamageHP);

	//VARIABLES
	int Damage;
	~Weapon();
};



#endif