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

void createEntity(Entity Player, int Description)
{	int Trigger = 0;
	//int Trigger = random(Player.level-3)+(Player.level+3);		//Used to select specific enemies based on player level
	if (Description == 1)	//Can also be isEnemy==1 from entity.h
	{
		if (Player.level <= 5)
		{
			switch (Trigger)
			{
				case 0:
				{
					NPC bat = NPC();
					bat.species = "Bat";
					//bat.level = random(2*Player.level-(Player.level-1))+(2*Player.level-5);
					bat.stats = { 2,0,2,0,1,9,0,0 };
					bat.expDrop = 0;
					bat.expDrop = 20*Player.level;
					//library.addClass(bat);
					cout << bat.species << endl;
					cout << "STATS: ";
					for (int i=0; i<8; i++)
						{
							cout << bat.stats[i] << " ";
						}
					cout << endl;
					break;
				}
				case 1:
				{
					NPC rat = NPC();
					rat.species = "Rat";
					//rat.level = random(Player.level+5)+(Player.level-5);		//Level 
					/*if (rat.level <= 0)
					{
							abs(rat.level); 
					}
					
					rat.stats = { 1,1,2,0,1,6,0,0 };
					
					for(int i=0; i<8; i++) 
					{
					rat.stats[i] *= (2*Player.level)-(Player.level-3);
					}

					for(int i=0; i<8; i++) 
					{
						if (rat.stats[i] < 0)
						abs(rat.stats[i]);
					}*/
					rat.expDrop = 0;
					rat.expDrop = 20*Player.level;
					cout << rat.species << endl;
					//library.addClass(rat);
					break;
				}
				case 2:
				{
					NPC zombie = NPC();
					zombie.species = "Zombie";
					//zombie.level = random(2*Player.level-(Player.level-1))+(2*Player.level-5);
					zombie.stats = { 8,3,4,0,1,2,0,0 };
					zombie.expDrop = 0;
					zombie.expDrop = 20*Player.level;
					cout << zombie.species << endl;
					//library.addClass(zombie);
					break;
				}
			}
		}
		else if (Player.level <=15)
		{
			//Trigger = random(Player.level-6)+(Player.level+3)	//Between 3 and 6
			switch (Trigger)
			{
				case 3:
				{
					NPC skeleton = NPC();
					skeleton.species = "Skeleton";		//Using skeleton archer from MC as base
					//skeleton.level = random(100);
					skeleton.stats = { 6,7,5,0,0,4,4,0 };
					skeleton.expDrop = 0;
					skeleton.expDrop = 20*Player.level;
					cout << skeleton.species << endl;
					//library.addClass(skeleton);
					break;
				}
				case 4:
				{
					NPC goblin = NPC();
					goblin.species = "Goblin";	//Goblin from BGO
					//goblin.level = random(2*Player.level-(Player.level-1))+(2*Player.level-5);
					goblin.stats = { 3,4,2,0,2,7,7,0 };
					goblin.expDrop = 0;
					goblin.expDrop = 2*Player.level;
					//library.addClass(goblin);
					cout << goblin.species << endl;
					break;
				}
				case 5:
				{
					NPC spider = NPC();
					spider.species = "Giant Spider";
					//spider.level = random(2*Player.level-(Player.level-1))+(2*Player.level-5);
					spider.stats = { 7,3,2,0,1,7,2,0 };
					spider.expDrop = 0;
					spider.expDrop = 20*Player.level;
					cout << spider.species << endl;
					//library.addClass(spider);
					break;
				}
				case 6:
				{
					NPC bandit = NPC();
					bandit.Name = "Bandit";
					//bandit.level = random(2*Player.level-(Player.level-1))+(2*Player.level-5);
					bandit.stats = { 8,5,4,4,1,5,3,0 };
					bandit.expDrop = 0;
					bandit.expDrop = 20*Player.level;
					cout << bandit.Name << endl;
					//library.addClass(bandit);
					break;
				}
			}
		}
		else if (Player.level <= 25)
		{
			//Trigger = random(Player.level-7)+(Player.level+6);
			switch (Trigger)
			{
				case 7:
				{
					NPC orc = NPC();
					orc.species = "Orc";		//write an equation that uses the player's level to scale the stats of the enemies
					//orc.level = random(2*(Player.level)-(((Player.level)-1)))+(2*(Player.level)-5);
					orc.stats = { 12,3,6,0,1,2,1,0 };
					orc.expDrop = 0;
					orc.expDrop = 40*(Player.level);
					cout << orc.species << endl;
					//library.addClass(orc);
					break;
				}
				case 8:
				{
					NPC golem = NPC();
					golem.species = "Golem";
					//golem.level
					golem.stats = { 20,1,10,0,1,0,2,0 };
					golem.expDrop = 0;
					golem.expDrop = 50*(Player.level);
					cout << golem.species << endl;
					//library.addClass(golem);
					break;
				}
			}
		}
	}

	else if (Description == 2)
	{
		NPC merchant = NPC();
		merchant.Name = "Bob the Merchant";
		merchant.species = "Human";
		//merchant.level = random(100);
		merchant.stats = { 50,50,50,50,50,50,50,0 };
		merchant.expDrop = 0;
		merchant.expDrop = 120*Player.level;
	/*for (int i=0; i<5; i++)
	{
		merchant.inventory[i] = 
	}*/
		//library.addClass(merchant);
		cout << merchant.Name << endl;
	}

	else if (Description == 3)
	{
		NPC dragon = NPC();
		dragon.species = "Dragon";
		for(int i =0; i < 8; i++) {}
		//dragon.level = random(100);
		dragon.stats = { 50,50,50,50,50,50,50,0 };
		dragon.expDrop = 0;
		dragon.expDrop = 500*Player.level;
		cout << dragon.species << endl;
		//library.addClass(dragon);

		//minotaur
		//demon
	}
}
/*
int main()
{
	int Description = 1;

	Player player = Player();
	player.species = "Human";
	player.level = 1;

	createEntity(player, Description);
	return 0;
}*/