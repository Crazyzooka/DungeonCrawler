#include "pch.h"
#include "Functions.h"
#include "GameData.h"
#include <iostream>
#include <string>

int main()
{
	// creates character
	Entity player = createCharacter();

	//initialise floor array to generate floors on
	int length = FLOORSIZE;
	int floor[FLOORSIZE][FLOORSIZE];

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			floor[j][i] = 0;
		}
	}
	
	//generates floor
	generateFloor(floor, length);
	//prints floor
	//printFloor(floor, length);

	//initialises game variables to be used
	std::string userInput;
	int userx, usery, newFloor, lastRoom, currentRoom;
	newFloor = 1;

	while (true)
	{
		if (newFloor == 1)
		{
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
						
						display("You grab onto the ladder, one step at a time, and descend further into the abyss.");
					}
				}
			}
		}

		printFloor(floor, length);

		/*
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
		*/

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

				display("You can't go that way.");
			}
			else if (userInput == "Open")
			{

			}
			else if (userInput == "Take")
			{

			}
			else if (userInput == "Give")
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
			}
			else if (userInput == "Attack")
			{

			}
			else
			{
				display("You stand there in confusion, what is " + userInput + "?");
			}
		}
	}


	return 0;
}