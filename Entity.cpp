#include "pch.h"

#include <iostream>
#include <string>
#include <vector>

#include "Entity.h"
#include "Item.h"

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
{}