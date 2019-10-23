#include "pch.h"

#include "Functions.h"
#include "GameData.h"
#include "Classlib.h"
#include "Room.h"

#include <iostream>
#include <string>
#include <vector>

extern void createItems(Classlib * library);
extern void createAbilities(Classlib * library);
extern void createEntity(Classlib * library);

int main()
{
	//creates game library with all content
	Classlib * library = new Classlib();
	createItems(library);
	createAbilities(library);
	createEntity(library);

	//Character creation phase
	Player * player = new Player();
	/*
	//starting gear for player
	CreateChar(player);
	ChooseStats(player);
	ChooseAbilities(player, library);
	*/
	//creates player inventory
	std::vector<Item> playerInv;
	playerInv.resize(player->stats[Strength]);

	for (int i = 0; i < playerInv.size(); i++)
	{
		playerInv[i] = Item();
	}

	playerInv = ChooseItems(playerInv, player, library);
	
	std::cout << "\n";

	//display("...Leaves crunch as you approach the fortress, the forest darkens as it starts to rain. You shamble into a dark gate house and find a ladder going down.");

	//initialise floor array to generate floors on
	int length = FLOORSIZE;
	int floor[FLOORSIZE][FLOORSIZE];

	Room * genRoom = new Room();

	//initialises game variables to be used
	std::string userInput;
	int userx, usery, newFloor, lastRoom, currentRoom, totalItems;
	totalItems = 0;
	newFloor = 1;

	while (true)
	{
		//only generates when a call to new floor is needed
		if (newFloor == 1)
		{
			//sets all indices of the floor array to 0 to start anew
			for (int i = 0; i < length; i++)
			{
				for (int j = 0; j < length; j++)
				{
					floor[j][i] = 0;
				}
			}

			//Generates new floor
			generateFloor(floor, length);

			//Floor loop that sets the player's initial position
			for (int i = 0; i < length; i++)
			{
				for (int j = 0; j < length; j++)
				{
					if (floor[j][i] == 1)
					{
						//sets the player position at entrance
						currentRoom = 1;
						floor[j][i] = PlayerMark;

						//records player initial coords from entrance
						userx = j;
						usery = i;

						newFloor = 0;

						wait(1.75);
						
						display("You grab onto the ladder, and descend further into the abyss, one step at a time.");
					}
				}
			}
		}

		//prints out floor map
		printFloor(floor, length);

		//displays information based on surroundings
		if (currentRoom == 1)
		{
			display("There's an entrance here.");
		}
		if (currentRoom == 3)
		{
			display("There's an exit here.");
		}

		std::cout << std::endl;

		//displays information based on surroundings
		display("There are paths going: ");
		if (usery - 1 >= 0 && floor[userx][usery - 1] != 0)
		{
			display("- North");
		}
		if (userx + 1 < FLOORSIZE && floor[userx + 1][usery] != 0)
		{
			display("- East");
		}
		if (usery + 1 < FLOORSIZE && floor[userx][usery + 1] != 0)
		{
			display("- South");
		}
		if (userx - 1 >= 0 && floor[userx - 1][usery] != 0)
		{
			display("- West");
		}

		genRoom->GenerateRoom(library->getNPC(myRandom(library->NPCSize)),*player,library);

		std::cout << genRoom->nonPlayer.species << "\n";

		//player exploration phase where they can make commands to interact with room and map
		while (true)
		{
			std::cin >> userInput;
			userInput = input(userInput);

			if (userInput == "Move" || userInput == "Go")
			{
				std::cin >> userInput;
				userInput = input(userInput);

				if (userInput == "North" && usery - 1 >= 0 && floor[userx][usery - 1] != 0)
				{
					floor[userx][usery] = currentRoom;
					lastRoom = currentRoom;

					usery = usery - 1;
					currentRoom = floor[userx][usery];
					floor[userx][usery] = PlayerMark;

					break;
				}
				if (userInput == "East" && userx + 1 < FLOORSIZE && floor[userx + 1][usery] != 0)
				{
					floor[userx][usery] = currentRoom;
					lastRoom = currentRoom;

					userx = userx + 1;
					currentRoom = floor[userx][usery];
					floor[userx][usery] = PlayerMark;

					break;
				}
				if (userInput == "South" && usery + 1 < FLOORSIZE && floor[userx][usery + 1] != 0)
				{
					floor[userx][usery] = currentRoom;
					lastRoom = currentRoom;

					usery = usery + 1;
					currentRoom = floor[userx][usery];
					floor[userx][usery] = PlayerMark;

					break;
				}
				if (userInput == "West" && userx - 1 >= 0 && floor[userx - 1][usery] != 0)
				{
					floor[userx][usery] = currentRoom;
					lastRoom = currentRoom;

					userx = userx - 1;
					currentRoom = floor[userx][usery];
					floor[userx][usery] = PlayerMark;

					break;
				}
				if (userInput == "Up" && currentRoom == 1)
				{
					display("You've already been up there.");
					/*
					floor[userx][usery] = currentRoom;
					newFloor = 1;
					*/
					break;
				}
				if (userInput == "Down" && currentRoom == 3)
				{
					floor[userx][usery] = currentRoom;
					newFloor = 1;
					break;
				}

				display("You can't go that way.");
			}
			else if (userInput == "View")
			{
				std::cin >> userInput;
				userInput = input(userInput);

				if (userInput == "Map")
				{
					printFloor(floor, length);
				}

				if (userInput == "Character")
				{
					player->viewCharacter();
					std::cout << "\nAbilities I can perform in combat: \n";
					for (int k = 0; k < player->abilities.size(); k++)
					{
						if (player->abilities[k] != -1)
						{
							std::cout << "- " << library->getAbility(player->abilities[k]).Name << "\n";
						}
					}
				}
				
				if (userInput == "Inventory")
				{
					display("You open your backpack:");

					for (int i = 0; i < playerInv.size(); i++)
					{
						std::cout << "- " << playerInv[i].Name << "\n";
					}
				}

				if (userInput == "Room")
				{
					display("The room is dark, you try your best to look around and see: ");
					for (int i = 0; i < genRoom->RoomItems.size(); i++)
					{
						std::cout << "- " << genRoom->RoomItems[i].Name << "\n";
					}

					display("One" + genRoom->nonPlayer.species + " is also in the room.");
				}

				if (userInput == genRoom->nonPlayer.species && (genRoom->nonPlayer.isDead || genRoom->nonPlayer.isMerchant))
				{
					display("You take a look at the " + genRoom->nonPlayer.species + ":");
				}

			}
			else if (userInput == "Attack")
			{
				
			}
			else if (userInput == "Help")
			{
				std::cout << "(Move/Go) (North/East/South/West/Up/Down)\n";
				std::cout << "(Use/Equip/Take/Drop/Buy/Sell) (Item)\n";
				std::cout << "(View) (Map/Character/Inventory/Room/NPC)\n";
				std::cout << "(Attack) (NPC)\n";
			}
			else
			{
				display("What is " + userInput + "? If you need help, type 'help'.");
			}
		}
	}

	delete library;

	return 0;
}
