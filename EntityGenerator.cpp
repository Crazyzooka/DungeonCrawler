#include <iostream>
#include <string>
#include <vector>

#include "Entity.h"
#include "Item.h"
#include "Room.h"
#include "Classlib.h"
#include "GameData.h"
#include "Functions.h"
using namespace std;

void createEntity(Classlib library)
{
	if (Description == "Enemy")	//Can also be isEnemy==1 from entity.h
	{
		Entity orc;
		orc.species = "Orc";		//write an equation that uses the player's level to scale the stats of the enemies
		orc.level = random(2*Player.level-(Player.level-1))+(2*Player.level-5);
		orc.stats = { 12,3,6,0,0,2,1,0 };
		expDrop = 0;
		expDrop = 40*player.level;
		library.addClass(orc);

		Entity skeleton;
		skeleton.species = "Skeleton";		//Using skeleton archer from MC as base
		skeleton.level = random();
		skeleton.stats = { 6,7,5,0,0,4,4,0 };
		expDrop = 0;
		expDrop = 20*player.level;
		library.addClass(skeleton);

		Entity spider;
		spider.species = "Spider";
		spider.level = random();
		spider.stats = { 7,3,4,0,1,7,2,0 };
		expDrop = 0;
		expDrop = 20*player.level;
		library.addClass(spider);

		Entity goblin;
		goblin.species = "Goblin";	//Goblin from BGO
		goblin.level = random();
		goblin.stats = { 3,4,2,0,2,7,7,0 };
		expDrop = 0;
		expDrop = 2*player.level;
		library.addClass(goblin);

		Entity zombie;
		zombie.species = "Zombie";
		zombie.level = random();
		zombie.stats = { 8,3,4,0,1,2,0,0 };
		expDrop = 0;
		expDrop = 20*player.level;
		library.addClass(zombie);

		Entity bat;
		bat.species = "Bat";
		bat.level = random();
		bat.stats = { 2,0,2,0,1,9,0,0 };
		expDrop = 0;
		expDrop = 20*player.level;
		library.addClass(bat);

		Entity rat;
		rat.species = "Rat";
		rat.level = random();
		rat.stats = { 1,1,2,0,1,6,0,0 };
		expDrop = 0;
		expDrop = 20*player.level;
		library.addClass(rat);
	}
	else if (Description == "Merchant")
	{
		Entity merchant;
		merchant.name = "Bob the Merchant"
		merchant.species = "Human";
		merchant.level = random();
		merchant.stats = { 50,50,50,50,50,50,50,0 };
		expDrop = 0;
		expDrop = 120*player.level;
		library.addClass(merchant);
	}
	else if (Description == "Boss")
	{
		Entity dragon;
		dragon.species = "Dragon";
		dragon.level = random();
		dragon.stats = { 50,50,50,50,50,50,50,0 };
		expDrop = 0;
		expDrop = 500*player.level;
		library.addClass(dragon);
	}  
}