#include <iostream>
#include <string>
#include <vector>
#include "Entity.h"

using namespace std;

Entity::Entity()					//Creating an empty entity
{
	name = "?";
	species = "?";
	level = 0;
	ID = currentID++;
	mana = 100;
}

Entity::Entity(string entitySpecies)
{
	name = "?"
	species = entitySpecies;
	level = 0;
	ID = currentID++;
	mana = 100;
}

Entity::~Entity()
{
	cout << "I used to be someone..." << endl;
}

Player::Player()
{
}

void Player::setName(string entityName)
{
	name = entityName;
}

string Player::getName()
{
	return name;
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

}

void Player::levelUp()
{

}
void Player::makeMove()
{

}

void Player::attack(Ability action, NPC person)
{

}

Player::~Player()
{
}

NPC::NPC()
{

}

NPC::~NPC()
{}