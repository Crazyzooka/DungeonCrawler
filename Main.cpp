#include "pch.h"

#include "Functions.h"
#include "GameData.h"
#include "Classlib.h"

#include <iostream>
#include <string>

extern void createItems(Classlib * library);

int main()
{
	Classlib * library = new Classlib();
	createItems(library);

	// creates character
	Player * player = new Player();

	CreateChar(player);

	//initialise floor array to generate floors on
	int length = FLOORSIZE;
	int floor[FLOORSIZE][FLOORSIZE];

	//initialises game variables to be used
	std::string userInput;
	int userx, usery, newFloor, lastRoom, currentRoom;
	newFloor = 1;

	while (true)
	{
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

			for (int i = 0; i < length; i++)
			{
				for (int j = 0; j < length; j++)
				{
					if (floor[j][i] == 1)
					{
						currentRoom = 1;
						floor[j][i] = PlayerMark;

						userx = j;
						usery = i;

						newFloor = 0;

						wait(1.75);
						
						display("You grab onto the ladder, and descend further into the abyss, one step at a time.");
					}
				}
			}
		}

		printFloor(floor, length);
		if (currentRoom == 1)
		{
			display("There's an entrance here.");
		}
		if (currentRoom == 3)
		{
			display("There's an exit here.");
		}

		std::cout << std::endl;

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
					floor[userx][usery] = currentRoom;
					newFloor = 1;
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
			else if (userInput == "Open")
			{

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
					player.viewCharacter();
				}
			}
			else if (userInput == "Attack")
			{

			}
			else if (userInput == "Help")
			{
				std::cout << "(Move/Go) (North/East/South/West/Up/Down)\n";
				std::cout << "(Open) (Character/NPC)\n";
				std::cout << "(Use/Equip/Take/Buy/Give/Sell) (Item)\n";
				std::cout << "(Back) To go back from inventories.\n";
				std::cout << "(View) (Map/Character/NPC/Room)\n";
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
