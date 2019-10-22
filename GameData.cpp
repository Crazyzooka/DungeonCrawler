#include "pch.h"

#include "Functions.h"
#include "GameData.h"
#include "Classlib.h"
#include "Ability.h"
#include "Effect.h"
#include "Item.h"
#include "Entity.h"

#include <iostream>

void CreateChar(Player * player)
{
	std::string u_input;

	display("Would you like to skip the intro? ");
	std::getline(std::cin, u_input);
	u_input = input(u_input);

	std::cout << "\n\n";

	player->isPlayer = true;

	if (u_input == "No" || u_input == "N")
	{
		wait(1.75);
		display("Hey, you're awake. You're so close already, the tower's just up ahead, don't give up now. Relax, everyone's gone through it before. It's just a matter of getting used to it. 'Cause once you know it from the inside-out, you'll be fine.");
	}
	display("Say, what's your name?\n");

	std::string temp;
	std::getline(std::cin, temp);
	player->Name = temp;

	std::cout << "\n\n";
	wait(1.75);

	display(temp + " is it? That's a cool name, it's not one I hear a lot around these parts.");
}

void ChooseStats(Player * player)
{
	std::string u_input;

	int points = 35;
	int allocate = 0;

	int * tempPtr = new int[7];
	for (int i = 0; i < 7; i++)
	{
		tempPtr[i] = 0;
	}

	while (points > 0)
	{

		std::cout << "STRENGTH governs your heavy-lifting capabilities. \nThis affects your carry-weight and the physical abilities you can use.\n\n";
		std::cout << "STRENGTH: " << tempPtr[Strength] << "\n";
		std::cout << "Skill points left: " << points << "\n\n";

		while (true)
		{
			std::cout << "Points to allocate: ";
			std::cin >> allocate;

			if (std::cin.good())
			{
				if (tempPtr[Strength] + allocate > 100 || tempPtr[Strength] + allocate < 0)
				{
					std::cout << "Can't exceed 0 or 100.\n";
				}
				else if (points - allocate < 0)
				{
					std::cout << "Not enough points.\n";
				}
				else
				{
					break;
					std::cout << std::endl;
				}
			}

			std::cin.clear();
			std::cin.ignore();

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

			if (std::cin.good())
			{
				if (tempPtr[Perception] + allocate > 100 || tempPtr[Perception] + allocate < 0)
				{
					std::cout << "Can't exceed 0 or 100.\n";
				}
				else if (points - allocate < 0)
				{
					std::cout << "Not enough points.\n";
				}
				else
				{
					break;
					std::cout << std::endl;
				}
			}
			std::cin.clear();
			std::cin.ignore();

		}

		tempPtr[Perception] = tempPtr[Perception] + allocate;
		points = points - allocate;

		std::cout << "ENDURANCE governs your persistance. \nThis affects your resistance to debuffs and how many spells you can remember at once.\n\n";
		std::cout << "ENDURANCE: " << tempPtr[Endurance] << "\n";
		std::cout << "Skill points left: " << points << "\n";

		while (true)
		{
			std::cout << "Points to allocate: ";
			std::cin >> allocate;

			if (std::cin.good())
			{
				if (tempPtr[Endurance] + allocate > 100 || tempPtr[Endurance] + allocate < 0)
				{
					std::cout << "Can't exceed 0 or 100.\n";
				}
				else if (points - allocate < 0)
				{
					std::cout << "Not enough points.\n";
				}
				else
				{
					break;
					std::cout << std::endl;
				}
			}
			std::cin.clear();
			std::cin.ignore();
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

			if (std::cin.good())
			{
				if (tempPtr[Charisma] + allocate > 100 || tempPtr[Charisma] + allocate < 0)
				{
					std::cout << "Can't exceed 0 or 100.\n";
				}
				else if (points - allocate < 0)
				{
					std::cout << "Not enough points.\n";
				}
				else
				{
					std::cout << std::endl;
					break;
				}
			}
			std::cin.clear();
			std::cin.ignore();
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

			if (std::cin.good())
			{
				if (tempPtr[Intelligence] + allocate > 100 || tempPtr[Intelligence] + allocate < 0)
				{
					std::cout << "Can't exceed 0 or 100.\n";
				}
				else if (points - allocate < 0)
				{
					std::cout << "Not enough points.\n";
				}
				else
				{
					std::cout << std::endl;
					break;
				}
			}
			std::cin.clear();
			std::cin.ignore();
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

			if (std::cin.good())
			{
				if (tempPtr[Agility] + allocate > 100 || tempPtr[Agility] + allocate < 0)
				{
					std::cout << "Can't exceed 0 or 100.\n";
				}
				else if (points - allocate < 0)
				{
					std::cout << "Not enough points.\n";
				}
				else
				{
					std::cout << std::endl;
					break;
				}
			}
			std::cin.clear();
			std::cin.ignore();
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

			if (std::cin.good())
			{
				if (tempPtr[Luck] + allocate > 100 || tempPtr[Luck] + allocate < 0)
				{
					std::cout << "Can't exceed 0 or 100.\n";
				}
				else if (points - allocate < 0)
				{
					std::cout << "Not enough points.\n";
				}
				else
				{
					std::cout << std::endl;
					break;
				}
			}
			std::cin.clear();
			std::cin.ignore();
		}

		tempPtr[Luck] = tempPtr[Luck] + allocate;
		points = points - allocate;

		if (points > 0)
		{
			std::cout << "You still have left over skill points, would you like to go back? ";
			std::cin >> u_input;
			u_input = input(u_input);

			if (u_input == "No" || u_input == "N")
			{
				break;
			}
		}

		std::cin.clear();
		std::cin.ignore();
	}

	for (int i = 0; i < 7; i++)
	{
		player->stats[i] = tempPtr[i];
	}

	player->inventory.resize(player->stats[Strength]);
	player->abilities.resize(player->stats[Endurance]);
	delete[] tempPtr;
}

void ChooseAbilities(Player * player, Classlib * library)
{
	
}

void ChooseItems(Player * player, Classlib * library)
{
	
}