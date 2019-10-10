#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
#include "Entity.h"

using namespace std;

int Entity::currentID = 1;

Entity::Entity()					//Creating an empty entity
{
	name = "?";
	species = "?";
	level = 0;
	ID = currentID;
	currentID++;
	mana = 100;
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
{

}