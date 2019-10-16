#include "pch.h"

#include "Functions.h"
#include "GameData.h"
#include "ClassLib.h"
#include "Ability.h"
#include "Effect.h"
#include "Item.h"
#include "Entity.h"

#include <iostream>

Entity createCharacter()
{
	std::string input;

	std::cout << "Would you like to skip the intro? ";
	std::cin >> input;

	Entity x;
	Player player;
	player.isPlayer = true;
	std::cout << player.ID;

	if (input == "No" || input == "no" || input == "N" || input == "n") {

		wait(1.75);
		display("Hey, you're awake. You're so close already, the tower's just up ahead, don't give up now. Relax, everyone's gone through it before. It's just a matter of getting used to it. 'Cause once you know it from the inside-out, you'll be fine.");


		display("Say, what's your name?\n");

		std::string temp;
		std::cin >> temp;
		player.Name = temp;

		clear();
		wait(1.75);

		display(temp + " is it? That's a cool name, it's not one I hear a lot around these parts. Now I'm curious, what makes you SPECIAL?");
	}

	clear();

	int * tempPtr = new int[7];
	for (int i = 0; i < 7; i++)
	{
		tempPtr[i] = 0;
	}

	int points = 35;
	int allocate = 0;

	while (points > 0)
	{

		std::cout << "STRENGTH governs your heavy-lifting capabilities. \nThis affects your carry-weight and the physical abilities you can use.\n\n";
		std::cout << "STRENGTH: " << tempPtr[Strength] << "\n";
		std::cout << "Skill points left: " << points << "\n\n";

		while (true)
		{
			std::cout << "Points to allocate: ";
			std::cin >> allocate;

			if (tempPtr[Strength] + allocate > 100 || tempPtr[Strength] + allocate < 0)
			{
				std::cout << "Can't exceed 0 or 100.\n";
			}
			else
			{
				break;
				std::cout << std::endl;
			}
		}

		tempPtr[Strength] = tempPtr[Strength] + allocate;
		points = points - allocate;

		std::cout << "PERCEPTION governs your sight capabilities. \nThis affects your accuracy and critical chance.\n\n";
		std::cout << "PERCEPTION: " << tempPtr[Perception] << "\n";
		std::cout << "Skill points left: " << points << "\n\n";

		while (true)
		{
			std::cout << "Points to allocate: ";
			std::cin >> allocate;

			if (tempPtr[Perception] + allocate > 100 || tempPtr[Perception] + allocate < 0)
			{
				std::cout << "Can't exceed 0 or 100.\n";
			}
			else
			{
				break;
				std::cout << std::endl;
			}
		}

		tempPtr[Perception] = tempPtr[Perception] + allocate;
		points = points - allocate;

		std::cout << "ENDURANCE governs your survivability. \nThis affects your resistance to debuffs.\n\n";
		std::cout << "ENDURANCE: " << tempPtr[Endurance] << "\n";
		std::cout << "Skill points left: " << points << "\n";

		while (true)
		{
			std::cout << "Points to allocate: ";
			std::cin >> allocate;

			if (tempPtr[Endurance] + allocate > 100 || tempPtr[Endurance] + allocate < 0)
			{
				std::cout << "Can't exceed 0 or 100.\n";
			}
			else
			{
				break;
				std::cout << std::endl;
			}
		}

		tempPtr[Endurance] = tempPtr[Endurance] + allocate;
		points = points - allocate;

		std::cout << "CHARISMA governs your charming capabilities. \nThis affects vendor prices.\n\n";
		std::cout << "CHARISMA: " << tempPtr[Charisma] << "\n";
		std::cout << "Skill points left: " << points << "\n\n";

		while (true)
		{
			std::cout << "Points to allocate: ";
			std::cin >> allocate;

			if (tempPtr[Charisma] + allocate > 100 || tempPtr[Charisma] + allocate < 0)
			{
				std::cout << "Can't exceed 0 or 100.\n";
			}
			else
			{
				break;
				std::cout << std::endl;
			}
		}

		tempPtr[Charisma] = tempPtr[Charisma] + allocate;
		points = points - allocate;

		std::cout << "INTELLIGENCE governs your brain capabilities. \nThis affects your mana and the magic abilities you can use.\n\n";
		std::cout << "INTELLIGENCE: " << tempPtr[Intelligence] << "\n";
		std::cout << "Skill points left: " << points << "\n\n";

		while (true)
		{
			std::cout << "Points to allocate: ";
			std::cin >> allocate;

			if (tempPtr[Intelligence] + allocate > 100 || tempPtr[Intelligence] + allocate < 0)
			{
				std::cout << "Can't exceed 0 or 100.\n";
			}
			else
			{
				break;
				std::cout << std::endl;
			}
		}

		tempPtr[Intelligence] = tempPtr[Intelligence] + allocate;
		points = points - allocate;

		std::cout << "AGILITY governs your nimble capabilities. \nThis affects your dodge, sneak, and speed\n\n";
		std::cout << "AGILITY: " << tempPtr[Agility] << "\n";
		std::cout << "Skill points left: " << points << "\n\n";

		while (true)
		{
			std::cout << "Points to allocate: ";
			std::cin >> allocate;

			if (tempPtr[Agility] + allocate > 100 || tempPtr[Agility] + allocate < 0)
			{
				std::cout << "Can't exceed 0 or 100.\n";
			}
			else
			{
				break;
				std::cout << std::endl;
			}
		}

		tempPtr[Agility] = tempPtr[Agility] + allocate;
		points = points - allocate;

		std::cout << "LUCK governs your luck capabilities. \nThis affects your critical hit chance\n\n";
		std::cout << "LUCK: " << tempPtr[Luck] << "\n";
		std::cout << "Skill points left: " << points << "\n\n";

		while (true)
		{
			std::cout << "Points to allocate: ";
			std::cin >> allocate;

			if (tempPtr[Luck] + allocate > 100 || tempPtr[Luck] + allocate < 0)
			{
				std::cout << "Can't exceed 0 or 100.\n";
			}
			else
			{
				break;
				std::cout << std::endl;
			}
		}

		tempPtr[Luck] = tempPtr[Luck] + allocate;
		points = points - allocate;

		if (points > 0)
		{
			std::cout << "You still have left over skill points, would you like to go back? ";
			cin >> input;

			if (input == "No" || input == "no" || input == "N" || input == "n")
			{
				break;
			}
		}
	}

	return player;
}

Classlib createGameData()
{
	Classlib classes;

	return classes;
}