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

	//starting gear for player
	//CreateChar(player);
	ChooseStats(player);
	ChooseAbilities(player, library);

	//creates player inventory
	std::vector<Item> playerInv;
	playerInv.resize(player->stats[Strength]);

	for (int i = 0; i < playerInv.size(); i++)
	{
		playerInv[i] = Item();
	}

	playerInv = ChooseItems(playerInv, player, library);
	
	std::cout << "\n";
	//display("..Leaves crunch as you step closer to the fortress, the forest darkens as it starts to rain. You shamble into a dark gatehouse and find a ladder going down.");

	//initialise floor array to generate floors on
	int length = FLOORSIZE;
	int floor[FLOORSIZE][FLOORSIZE];

	//initialises game variables to be used
	std::string userInput;
	Room * genRoom = new Room();

	int userx, usery, newFloor, lastRoom, newRoom, currentRoom, totalItems, whosTurn;
	
	userx		= 0;
	usery		= 0;
	newFloor	= 1;
	newRoom		= 1;
	lastRoom	= 0;
	currentRoom = 0;
	totalItems	= 0;
	whosTurn	= 0;

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
						
						//display("You grab onto the ladder, and descend further into the abyss, one step at a time.");
					}
				}
			}
		}

		//prints out floor map
		printFloor(floor, length);

		if (newRoom == 1)
		{
			genRoom->GenerateRoom(library->getNPC(myRandom(library->NPCSize)), *player, library);
			newRoom = 0;
		}

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

		display("One " + genRoom->nonPlayer.species + " is standing idly in the room.");

		//player exploration phase where they can make commands to interact with room and map
		while (player->isInCombat == false)
		{
			//checks to see if the NPC in the room is going to attack or not
			if (genRoom->nonPlayer.isFriendly == false && genRoom->nonPlayer.isDead == false)
			{
				display("The " + genRoom->nonPlayer.species + " is approaching to attack!");
				player->isInCombat = true;
				break;
			}

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
					newRoom = 1;

					break;
				}
				if (userInput == "East" && userx + 1 < FLOORSIZE && floor[userx + 1][usery] != 0)
				{
					floor[userx][usery] = currentRoom;
					lastRoom = currentRoom;

					userx = userx + 1;
					currentRoom = floor[userx][usery];
					floor[userx][usery] = PlayerMark;
					newRoom = 1;

					break;
				}
				if (userInput == "South" && usery + 1 < FLOORSIZE && floor[userx][usery + 1] != 0)
				{
					floor[userx][usery] = currentRoom;
					lastRoom = currentRoom;

					usery = usery + 1;
					currentRoom = floor[userx][usery];
					floor[userx][usery] = PlayerMark;
					newRoom = 1;

					break;
				}
				if (userInput == "West" && userx - 1 >= 0 && floor[userx - 1][usery] != 0)
				{
					floor[userx][usery] = currentRoom;
					lastRoom = currentRoom;

					userx = userx - 1;
					currentRoom = floor[userx][usery];
					floor[userx][usery] = PlayerMark;
					newRoom = 1;

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
					newRoom  = 1;
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

					for (int k = 0; k < library->abilitySize; k++)
					{
						if (player->abilities[k] != -1)
						{
							std::cout << "- " << library->getAbility(player->abilities[k]).Name << "\n";
						}
					}

					std::cout << "\nI currently have equipped: \n";

					for (int i = 0; i < playerInv.size(); i++)
					{
						if (playerInv[i].Equipped == true)
						{
							std::cout << "- " << playerInv[i].Name << "\n";
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
				std::cin >> userInput;
				userInput = input(userInput);

				if (userInput == genRoom->nonPlayer.species)
				{
					genRoom->nonPlayer.isFriendly = false;
				}
			}
			else if (userInput == "Use")
			{
				std::cin >> userInput;
				userInput = input(userInput);
			}
			else if (userInput == "Equip")
			{
				std::cin >> userInput;
				userInput = input(userInput);

				for (int i = 0; i < playerInv.size(); i++)
				{
					if (userInput == playerInv[i].Name)
					{
						//equips player item
						if (player->limbEquip[playerInv[i].Limb] == 0)
						{
							player->limbEquip[playerInv[i].Limb] = 1;
							playerInv[i].Equipped = true;
						}
						else
						{
							for (int j = 0; j < playerInv.size(); j++)
							{
								if (playerInv[j].Limb == i)
								{
									playerInv[j].Equipped = false;
								}
							}
							playerInv[i].Equipped = true;
						}

						break;
					}
				}
			}
			else if (userInput == "Take")
			{
				std::cin >> userInput;
				userInput = input(userInput);
			}
			else if (userInput == "Drop")
			{
				std::cin >> userInput;
				userInput = input(userInput);

				for (int i = 0; i < playerInv.size(); i++)
				{
					if (userInput == playerInv[i].Name)
					{
						std::cout << "You drop your " << playerInv[i].Name << " on the floor.\n";
						genRoom->RoomItems.resize(genRoom->RoomItems.size() + 1);

						genRoom->RoomItems[genRoom->RoomItems.size() - 1] = playerInv[i];

						//resizes the backpack as the player buys item from the dude
						if (i != playerInv.size() - 1)
						{
							playerInv[i] = playerInv[playerInv.size() - 1];
							playerInv.resize(playerInv.size() - 1);
						}
						else
						{
							playerInv.resize(playerInv.size() - 1);
						}

						break;
					}
				}

			}
			else if (userInput == "Buy")
			{
				std::cin >> userInput;
				userInput = input(userInput);
			}
			else if (userInput == "Sell")
			{
				std::cin >> userInput;
				userInput = input(userInput);
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

		if (player->stats[Agility] > genRoom->nonPlayer.stats[Agility])
		{
			display("It seems like you're more nimble than your opponent!");
			whosTurn = 0;
		}
		else
		{
			display("Your opponent bunny hops, summersaults, and backflips towards you. I think they're faster than you are.");
			whosTurn = 1;
		}

		while (player->isInCombat == true)
		{
			std::cout << genRoom->nonPlayer.species << "'s HP: " << genRoom->nonPlayer.HP << "\n";
			std::cout << "Your HP: " << player->HP << "\n";

			if (whosTurn == 0)
			{
				display("It's your move: ");

				std::cout << "Stamina: " << player->stamina << "\n";
				std::cout << "Mana: " << player->mana << "\n";

				std::cout << "\nAbilities: \n";
				for (int k = 0; k < library->abilitySize; k++)
				{
					if (player->abilities[k] != -1)
					{
						std::cout << "- " << library->getAbility(player->abilities[k]).Name << "\n";
					}
				}

				std::cin >> userInput;
				userInput = input(userInput);

				if (userInput == "Attack")
				{
					std::cin >> userInput;
					userInput = input(userInput);

					for (int k = 0; k < library->abilitySize; k++)
					{
						if (userInput == library->getAbility(player->abilities[k]).Name)
						{
							if (library->getAbility(player->abilities[k]).CalculateChance(player) == true)
							{
								genRoom->nonPlayer.HP -= library->getAbility(player->abilities[k]).Damage;

								library->getAbility(player->abilities[k]).ApplyCost(player);
								display("Your attack hits!");

								break;
							}
							else
							{
								display("Your attack misses.");
								break;
							}
						}
					}
					
				}	
				else if (userInput == "Use")
				{
					std::cin >> userInput;
					userInput = input(userInput);
				}
				else if (userInput == "Equip")
				{
					std::cin >> userInput;
					userInput = input(userInput);

					for (int i = 0; i < playerInv.size(); i++)
					{
						if (userInput == playerInv[i].Name)
						{
							//equips player item
							if (player->limbEquip[playerInv[i].Limb] == 0)
							{
								player->limbEquip[playerInv[i].Limb] = 1;
								playerInv[i].Equipped = true;
							}
							else
							{
								for (int j = 0; j < playerInv.size(); j++)
								{
									if (playerInv[j].Limb == i)
									{
										playerInv[j].Equipped = false;
									}
								}
								playerInv[i].Equipped = true;
							}

							break;
						}
					}
				}

				whosTurn++;
			}
			else if (whosTurn == 1)
			{
				display("Your opponent makes a move.");
				int random = myRandom(genRoom->nonPlayer.abilities.size());
				display("The " + genRoom->nonPlayer.species + " attacks you with a " + library->getAbility(genRoom->nonPlayer.abilities[random]).Name + "!");

				if (library->getAbility(genRoom->nonPlayer.abilities[random]).CalculateChance(player) == true)
				{
					player->HP -= library->getAbility(genRoom->nonPlayer.abilities[random]).Damage;
					display("Your opponent's attack hits!");
				}
				else
				{
					display("Your opponent's attack misses!");
				}
				
				player->stamina += player->stats[Agility] + player->stats[Endurance];
				player->mana += player->stats[Intelligence] + player->stats[Endurance];

				display("You regen some stamina and mana");

				whosTurn++;
			}

			if (whosTurn > 1)
			{
				whosTurn = 0;
			}

			if (player->HP <= 0)
			{
				display("It looks like your opponent got the upperhand...");
				break;
			}

			if (genRoom->nonPlayer.HP <= 0)
			{
				display("With a decisive blow, your opponent falls to the ground. They're now dead.");
				player->isInCombat = false;
				genRoom->nonPlayer.isDead = true;
			}
		}

		if (player->HP <= 0)
		{
			display("Your vision fades away, strength draining, you drop to the floor.");
		}
	}

	display("Your corpse is consumed by the dungeon. This was the story of " + player->Name + " may you rest in peace.");
	delete library;
	return 0;
}
