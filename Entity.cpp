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
	cout << "I used to be someone..." << endl;
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
			cout << "Strength: " << stats[i] << endl;
			break;
			case 1:
			cout << "Perception: " << stats[i] << endl;
			break;
			case 2:
			cout << "Endurance: " << stats[i] << endl;
			break;
			case 3:
			cout << "Charisma: " << stats[i] << endl;
			break;
			case 4:
			cout << "Intelligence: " << stats[i] << endl;
			break;
			case 5:
			cout << "Agility: " << stats[i] << endl;
			break;
			case 6:
			cout << "Luck: " << stats[i] << endl;
			break;
		}
	}
}

void Player::levelUp()
{

}
void Player::makeMove()
{

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
