#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <vector>

using namespace std;

class Item;
class Ability;

class Entity
{
public:
		static int currentID;

		string Name;

		vector<string> abilities;		//Array to store abilities
		vector<string> skills;			//Array to store skills
		vector<string> inventory;		//Array for items/equipment

		vector<int> limbHP = { 100,100,100,100,100,100 };			//Array for the health of limbs
		vector<int> stats = { 0,0,0,0,0,0,0 };			//Array for player or NPC's statistics

		int mana;						//Used for using skills and abilities
		int level;
		int ID;							//Number of entity created
		int gold;
		bool isDead;
		bool isInCombat;
		bool isPlayer;
		

		Entity();		//Defines the entity's species as it is created
		~Entity();

};

class NPC : public Entity
{
public:

		int expDrop;
		bool isBoss;
		bool isFriendly;
		bool isMerchant;

		NPC();
		~NPC();
};

class Player : public Entity
{
public:
		Player();
		
		void takeItem(Item loot);					//Takes an object of the Item class
		void giveItem(Item loot);					//Gives an object of the Item class
		void useItem(Item loot, Entity user);		//Uses an object of the Item class
		void viewCharacter();						//View stats of character
		void levelUp();
		void makeMove();
		void attack(NPC person);

		~Player();
};
#endif