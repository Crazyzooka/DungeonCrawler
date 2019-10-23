#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <vector>

using namespace std;

class Item;

class Entity
{
public:
		static int currentID;		//Defines the number of the entity created

		//VARIABLES
		string Name;
		string species;

		vector<int> abilities;		//Array to store abilities

		vector<int> limbHP = { 100,100,100,100,100,100 };		//Array for the health of limbs
		vector<int> limbEquip;								//Array for equipment of every limb
		vector<int> stats = { 0,0,0,0,0,0,0,0 };			//Array for player or NPC's statistics

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

		//VARIABLES
		int expDrop;				//Value given when an enemy is killed by the player in order to level up
		bool isBoss;				//Defines whether an NPC created is a Boss
		bool isFriendly;			//Defines whether an NPC created is friendly
		bool isMerchant;			//Defines whether an NPC created is a merchant

		NPC();
		~NPC();
};

class Player : public Entity
{
public:
		Player();
		
		//FUNCTIONS

		void takeItem(Item item);					//Takes an object of the Item class
		void giveItem(Item item);					//Gives an object of the Item class
		void useItem(Item item, Entity entity);		//Uses an object of the Item class
		void viewCharacter();						//View stats of character
		void levelUp();								//Increases level, and thus stats increase
		void attack(NPC person);

		~Player();
};
#endif