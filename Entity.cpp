#include "pch.h"

#include <iostream>
#include <string>
#include <vector>

#include "Entity.h"
#include "Item.h"
#include "GameData.h"

using namespace std;
int Entity::currentID = 0;

Entity::Entity()					//Creating an empty entity
{
	Name = "?";
	level = 1;
	ID = currentID++;
	mana = 100;
	gold = 300;
}

Entity::~Entity()
{
	cout << "This room is warm..." << endl;
}

Player::Player()
{

}

void Player::takeItem(Item item)
{

}

void Player::giveItem(Item item)
{
	
}

void Player::useItem(Item item, Entity entity)
{

}

void Player::viewCharacter()
{
  for (int i = 0; i<stats.size(); i++)
	{
		switch (i)
		{
			case 0:
			cout << "STRENGTH: " << stats[i] << endl;
			break;
			case 1:
			cout << "PERCEPTION: " << stats[i] << endl;
			break;
			case 2:
			cout << "ENDURANCE: " << stats[i] << endl;
			break;
			case 3:
			cout << "CHARISMA: " << stats[i] << endl;
			break;
			case 4:
			cout << "INTELLIGENCE: " << stats[i] << endl;
			break;
			case 5:
			cout << "AGILITY: " << stats[i] << endl;
			break;
			case 6:
			cout << "LUCK: " << stats[i] << endl;
			break;
			case 7:
			cout << "EXPERIENCE: " << stats[i] << endl;
			break;
		}
	}
}

void Player::levelUp()
{
	if (stats[7] == 100)
	{
		level = level++;
		stats[7] = 0;
	}
}


void Player::attack(NPC person)
{

}

Player::~Player()
{

}

NPC::NPC()
{

}

NPC::~NPC()
{

}
