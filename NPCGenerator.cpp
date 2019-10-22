#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#include "Entity.h"
#include "Item.h"
#include "Room.h"
#include "Classlib.h"
#include "GameData.h"
#include "Functions.h"


using namespace std;

void createEntity(Classlib *library)
{
	NPC Bat = NPC();
	Bat.species = "Bat";
	Bat.level = 1; 			//Bat.level myRandom(2*Player.level-(Player.level-1))+(2*Player.level-5);
	Bat.stats = { 2,0,2,0,1,9,0,0 };
	Bat.expDrop = 0;		//Bat.expDrop = 20*Player.level;

	library->addClass(Bat);

	NPC Rat = NPC();
	Rat.species = "Rat";
	Rat.stats = { 1,1,2,0,1,6,0,0 };
	Rat.level = 1;
	Rat.expDrop = 0;

	library->addClass(Rat);

	NPC Zombie = NPC();
	Zombie.species = "Zombie";
	Zombie.level = 1;
	Zombie.stats = { 8,3,4,0,1,2,0,0 };
	Zombie.expDrop = 0;

	library->addClass(Zombie);

	NPC Skeleton = NPC();
	Skeleton.species = "Skeleton";
	Skeleton.level = 1;
	Skeleton.stats = { 6,7,5,0,0,4,4,0 };
	Skeleton.expDrop = 0;

	library->addClass(Skeleton);

	NPC Goblin = NPC();
	Goblin.species = "Goblin";
	Goblin.level = 1;
	Goblin.stats = { 3,4,2,0,2,7,7,0 };
	Goblin.expDrop = 0;

	library->addClass(Goblin);

	NPC Spider = NPC();
	Spider.species = "Giant Spider";
	Spider.level = 1;
	Spider.stats = { 7,3,2,0,1,7,2,0 };
	Spider.expDrop = 0;

	library->addClass(Spider);

	NPC Bandit = NPC();
	Bandit.Name = "Bandit";
	Bandit.species = "Human";
	Bandit.level = 1;
	Bandit.stats = { 8,5,4,4,1,5,3,0 };
	Bandit.expDrop = 0;

	library->addClass(bandit);

	NPC Orc = NPC();
	Orc.species = "Orc";
	Orc.level = 1;
	Orc.stats = { 12,3,6,1,1,2,1,0 };
	Orc.expDrop = 0;

	library->addClass(Orc);

	NPC Golem = NPC();
	Golem.species = "Golem";
	Golem.level = 1;
	Golem.stats = { 20,1,10,0,1,0,2,0 };
	Golem.expDrop = 0;

	library->addClass(Golem);

	NPC Merchant = NPC();
	Merchant.Name = "Bob the Merchant";
	Merchant.species = "Human";
	Merchant.level = 1;
	Merchant.stats = { 50,50,50,50,50,50,50,0 };
	Merchant.expDrop = 0;			//Merchant.expDrop = 120*Player.level;

	library.addClass(Merchant);

	NPC Dragon = NPC();
	Dragon.species = "Dragon";
	Dragon.level = 1;
	Dragon.stats = { 20,15,12,0,5,5,8,0 };
	Dragon.expDrop = 0;			//Dragon.expDrop = 500*Player.level;

	library->addClass(Dragon);

	NPC Minotaur = NPC();
	Minotaur.species = "Minotaur";
	Minotaur.level = 1;
	Minotaur.stats = { 25,10,10,0,2,2,10,0 };
	Minotaur.expDrop = 0;			//Minotaur.expDrop = 500*Player.level;

	library->addClass(Minotaur);
}