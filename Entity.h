#ifndef ENTITY_H
#define ENTITY_H

#include "Item.h"
#include <string>
#include <vector>

using namespace std;

class Entity
{
public:
		//static int currentID = 0;

		string name;
		string species;

		vector<string> abilities;		//Array to store abilities
		vector<string> skills;			//Array to store skills
		vector<string> inventory;		//Array for items/equipment
		vector<int> limbHP [6];			//Array for the health of limbs
		vector<int> stats [5];			//Array for player or NPC's statistics
		int mana;						//Used for using skills and abilities
		int level;
		int ID;							//Number of entity created
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

		void setName(string entityName);			//Defines the name of the entity
		string getName();							//Calls back the name given to the entity
		
		void takeItem(Item item);					//Takes an object of the Item class
		void giveItem(Item item);					//Gives an object of the Item class
		void useItem(Item item, Entity entity);		//Uses an object of the Item class
		void viewCharacter();						//View stats of character
		void levelUp();
		void makeMove();
		void attack(Ability action, NPC person);

		~Player();
};
#endif