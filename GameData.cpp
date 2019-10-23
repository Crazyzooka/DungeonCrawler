#include "pch.h"

#include "Functions.h"
#include "GameData.h"
#include "Classlib.h"
#include "Ability.h"

#include "Item.h"
#include "Entity.h"

#include <vector>
#include <iostream>
#include <cmath>

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
	display("I'm curious, what makes you SPECIAL?");
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

	while (true)
	{
		std::cout << "\n";
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

		std::cout << "AGILITY governs your nimble capabilities. \nThis affects your dodge, sneak, and speed.\n\n";
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

		std::cout << "LUCK governs your luck capabilities. \nThis affects your critical hit chance.\n\n";
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
				std::cout << "\n";
				break;
			}
		}
		else
		{
			std::cout << "You've allocated all your points. Would you like to continue? ";
			std::cin >> u_input;
			u_input = input(u_input);

			if (u_input == "Yes" || u_input == "Y")
			{
				std::cout << "\n";
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

	player->abilities.resize(player->stats[Endurance]);

	int tempsize = player->abilities.size();

	for (int i = 0; i < tempsize; i++)
	{
		player->abilities[i] = -1;
	}

	delete[] tempPtr;
}

void ChooseAbilities(Player * player, Classlib * library)
{
	std::string u_input;
	int counter = 0;
	int valid = 0;
	int selected = 0;
	int printed = 0;
	
	//displays what abilities the player is eligible for
	std::cout << "\nChoose from the following abilities that you're eligible for: \n";

	for (int i = 0; i < library->abilitySize; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (player->stats[j] < library->getAbility(i).SkillsRequire[j])
			{
				valid = 0;
				break;
			}

			valid++;
		}

		if (valid == 7)
		{
			std::cout << "- " << library->getAbility(i).Name << "\n";
			printed++;
			valid = 0;
		}
	}

	if (printed > player->abilities.size())
	{
		printed = player->abilities.size();
	}

	while (true)
	{
		std::cout << "\nYou can learn " << printed - counter << " more abilities.\n\n";

		std::cin >> u_input;
		u_input = input(u_input);

		for (int i = 0; i < library->abilitySize; i++)
		{
			if (u_input == library->getAbility(i).Name)
			{
				for (int j = 0; j < 7; j++)
				{
					if (player->stats[j] < library->getAbility(i).SkillsRequire[j])
					{
						valid = 0;
						break;
					}

					valid++;
				}

				if (valid == 7)
				{
					for (int k = 0; k < counter; k++)
					{
						if (player->abilities[k] == i)
						{
							selected = 1;
							break;
						}
					}

					if (selected == 0)
					{
						player->abilities[counter] = i;
						std::cout << "You've learnt " << library->getAbility(i).Name << "!\n";
						counter++;
					}
					else
					{
						std::cout << "You've already learnt " << library->getAbility(i).Name << ".\n";
					}

					selected = 0;
					valid = 0;
				}
				else
				{
					std::cout << "You don't have enough stats for " << library->getAbility(i).Name << ".\n";
					valid = 0;
				}
			}
		}

		if (printed - counter <= 0)
		{
			std::cout << "You've learnt all the skills you can. Would you like to continue? ";
			std::cin >> u_input;
			u_input = input(u_input);

			if (u_input == "Yes" || u_input == "Y")
			{
				std::cout << "\n";
				break;
			}
			else
			{
				counter = 0;
				for (int k = 0; k < player->abilities.size(); k++)
				{
					player->abilities[k] = -1;
				}
			}
		}
	}

	display("Ah, so you know how to do a " + library->getAbility(player->abilities[myRandom(counter)]).Name + "? Yeah, I think you'll be alright.");
}

std::vector<Item> ChooseItems(std::vector<Item> playerInv, Player * player, Classlib * library)
{
	if (player->stats[Strength] > 0)
	{
		//display("Anywho, do you have any gear? It looks like you could use a hand.");
	//display("I've got some gear I can sell off if you need.");

		std::vector<Item> temp;
		temp.resize(6);

		int inventory = 0;
		std::string u_input;

		float haggle = (100 - (player->stats[Charisma] + 50));

		std::cout << "\n";

		std::cout << "Charisma price bonus: -" << player->stats[Charisma] << "%\n";
		std::cout << "'A good friend' price bonus: -50%\n";

		std::cout << "What would you like to buy? Type 'Done' when you're ready to go.\n";

		for (int i = 0; i < temp.size(); i++)
		{
			temp[i] = library->getItem(myRandom(library->itemSize));
		}

		while (playerInv.size() - inventory != 0)
		{
			std::cout << "\n";

			//displays what items the user can buy

			for (int i = 0; i < temp.size(); i++)
			{
				std::cout << "- " << temp[i].Name << " : " << floor(temp[i].Value * haggle / 100) << " gold\n";
			}

			std::cout << "Your gold: " << player->gold << "\n";
			std::cout << "Your inventory space: " << playerInv.size() - inventory << "\n\n";

			//displays user input to choose what items to buy

			std::cin >> u_input;
			u_input = input(u_input);

			if (u_input == "Done")
			{
				break;
			}

			//adds the purchased item to the players inventory

			for (int i = 0; i < temp.size(); i++)
			{
				if (u_input == temp[i].Name)
				{
					std::cout << "You purchased a " << temp[i].Name << "!\n";
					playerInv[inventory] = temp[i];

					player->gold -= floor(temp[i].Value * haggle / 100);

					inventory++;

					//resizes the backpack as the player buys item from the dude
					if (i != temp.size() - 1)
					{
						temp[i] = temp[temp.size() - 1];
						temp.resize(temp.size() - 1);
					}
					else
					{
						temp.resize(temp.size() - 1);
					}

					break;
				}
			}
		}
	}
	else
	{
		display("I was going to offer you some items but... it doesn't look like you can carry any.");
	}
	
	//display("Well, this is where I say my goodbye. It's tough up in there, good luck.");

	return playerInv;
}