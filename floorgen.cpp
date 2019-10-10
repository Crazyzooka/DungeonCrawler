#include "Floorgen.h"
#include "Functions.h"
#include <cmath>
#include <iostream>

//prints out the entire floor using characters as ASCII picture

void printFloor(int matrix[FLOORSIZE][FLOORSIZE], int size)
{
	std::cout << "\n";

	//switch case for each type of cell in the array possible, and displays the character

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			switch (matrix[j][i])
			{
			case 0:
			{
				std::cout << "- ";
				break;
			}
			case 1:
			{
				std::cout << "1 ";
				break;
			}
			case 2:
			{
				std::cout << "O ";
				break;
			}
			case 3:
			{
				std::cout << "2 ";
				break;
			}
			}
		}

		std::cout << "\n";
	}
}

//generates a random path from the entrance and exit

void generatePath(int matrix[FLOORSIZE][FLOORSIZE], int length)
{
	int xentry, yentry, xexit, yexit, xfirst, yfirst, counter, direction;

	counter = 0;
	direction = 0;

	//starting position to draw path from

	for (int i = 0; i < FLOORSIZE; i++)
	{
		for (int j = 0; j < FLOORSIZE; j++)
		{
			if (matrix[j][i] == 1)
			{
				xentry = j;
				yentry = i;
			}

			if (matrix[j][i] == 3)
			{
				xexit = j;
				yexit = i;
			}
		}
	}

	for (int i = 0; i < 2; i++)
	{
		//if statement to draw random path from entrance first, then the exit

		if (i == 0)
		{
			xfirst = xentry;
			yfirst = yentry;
		}
		if (i == 1)
		{
			xfirst = xexit;
			yfirst = yexit;
		}

		std::cout << "generating path\n";

		//while loop for the amount of steps it should take
		while (counter < length)
		{
			//gets direction it should walk

			direction = random(4);
			std::cout << direction << "\n";

			//switch case depending on the random number to walk towards, if not possible it will go to the next case until it finds something possible

			switch (direction)
			{
			case 0:
			{
				//walk right
				if (xfirst + 1 < FLOORSIZE && (matrix[xfirst + 1][yfirst] == 0 || matrix[xfirst + 1][yfirst] == 2))
				{
					xfirst++;
					matrix[xfirst][yfirst] = 2;
					counter++;
					break;
				}
			}
			case 1:
			{
				//walk left
				if (xfirst - 1 >= 0 && (matrix[xfirst - 1][yfirst] == 0 || matrix[xfirst - 1][yfirst] == 2))
				{
					xfirst--;
					matrix[xfirst][yfirst] = 2;
					counter++;
					break;
				}
			}
			case 2:
			{
				//walk down
				if (yfirst + 1 < FLOORSIZE && (matrix[xfirst][yfirst + 1] == 0 || matrix[xfirst][yfirst + 1] == 2))
				{
					yfirst++;
					matrix[xfirst][yfirst] = 2;
					counter++;
					break;
				}
			}
			case 3:
			{
				//walk up
				if (yfirst - 1 >= 0 && (matrix[xfirst][yfirst - 1] == 0 || matrix[xfirst][yfirst - 1] == 2))
				{
					yfirst--;
					matrix[xfirst][yfirst] = 2;
					counter++;
					break;
				}
			}
			default:
			{
				break;
			}
			}

			//test code that didn't allow the path to overlap already generated path, decided not to use for now
			/*if ((matrix[xfirst][yfirst + 1] == 2 || yfirst + 1 >= FLOORSIZE) && (matrix[xfirst][yfirst - 1] == 2 || yfirst - 1 < 0) && (matrix[xfirst + 1][yfirst] == 2 || xfirst + 1 >= FLOORSIZE) && (matrix[xfirst - 1][yfirst] == 2 || xfirst - 1 < 0))
			{
				std::cout << "trapped\n";

				if (i == 0)
				{
					xfirst = xentry;
					yfirst = yentry;
				}
				if (i == 1)
				{
					xfirst = xexit;
					yfirst = yexit;
				}
			}*/

		}

		std::cout << "path generated!\n";
		counter = 0;

	}
}

//generates entrance, exit, and connects both doors with a path

void generateFloor(int matrix[FLOORSIZE][FLOORSIZE], int size)
{
	//randomly generates entrance position

	int xentry, yentry, xexit, yexit;

	xentry = random(FLOORSIZE);
	yentry = random(FLOORSIZE);

	//randomly generates exit position at a certain distance away from the entrance

	while (true)
	{
		xexit = random(FLOORSIZE);
		yexit = random(FLOORSIZE);

		if (matrix[xexit][yexit] != 1 && std::abs(yexit - yentry) > FLOORSIZE / 4 && std::abs(xexit - xentry) > FLOORSIZE / 4)
		{
			break;
		}
	}

	int xfirst, yfirst, xsecond, ysecond, direction;

	//starting position to draw path from

	xfirst = xentry;
	yfirst = yentry;

	xsecond = xexit;
	ysecond = yexit;

	direction = 0;

	std::cout << "generating connection\n";

	while (true)
	{
		//same switch case algorithm as the path generator

		direction = random(2);
		std::cout << direction << "\n";

		//these if statements filter the switch cases so that it leads the walk towards the exit
		
		if (xfirst <= xsecond)
		{
			if (yfirst <= ysecond)
			{
				switch (direction)
				{
				case 0:
				{
					if (xfirst + 1 < FLOORSIZE)
					{
						xfirst++;
						matrix[xfirst][yfirst] = 2;
						break;
					}
				}
				case 1:
				{
					if (yfirst + 1 < FLOORSIZE)
					{
						yfirst++;
						matrix[xfirst][yfirst] = 2;
						break;
					}
				}
				default:
				{
					if (xfirst + 1 < FLOORSIZE)
					{
						xfirst++;
						matrix[xfirst][yfirst] = 2;
						break;
					}
					break;
				}
				}
			}
			if (yfirst > ysecond)
			{
				switch (direction)
				{
				case 0:
				{
					if (xfirst + 1 < FLOORSIZE)
					{
						xfirst++;
						matrix[xfirst][yfirst] = 2;
						break;
					}
				}
				case 1:
				{
					if (yfirst - 1 >= 0)
					{
						yfirst--;
						matrix[xfirst][yfirst] = 2;
						break;
					}
				}
				default:
				{
					if (xfirst + 1 < FLOORSIZE)
					{
						xfirst++;
						matrix[xfirst][yfirst] = 2;
						break;
					}
					break;
				}
				}
			}

		}
		if (xfirst > xsecond)
		{
			if (yfirst <= ysecond)
			{
				switch (direction)
				{
				case 0:
				{
					if (xfirst - 1 >= 0)
					{
						xfirst--;
						matrix[xfirst][yfirst] = 2;
						break;
					}
				}
				case 1:
				{
					if (yfirst + 1 < FLOORSIZE)
					{
						yfirst++;
						matrix[xfirst][yfirst] = 2;
						break;
					}
				}
				default:
				{
					if (xfirst - 1 >= 0)
					{
						xfirst--;
						matrix[xfirst][yfirst] = 2;
						break;
					}
					break;
				}
				}
			}
			if (yfirst > ysecond)
			{
				switch (direction)
				{
				case 0:
				{
					if (xfirst - 1 >= 0)
					{
						xfirst--;
						matrix[xfirst][yfirst] = 2;
						break;
					}
				}
				case 1:
				{
					if (yfirst - 1 >= 0)
					{
						yfirst--;
						matrix[xfirst][yfirst] = 2;
						break;
					}
				}
				default:
				{
					if (xfirst - 1 >= 0)
					{
						xfirst--;
						matrix[xfirst][yfirst] = 2;
						break;
					}
					break;
				}
				}
			}

		}

		//detects when the walker walks next to exit coordinate

		if ((xfirst == xsecond && yfirst + 1 == ysecond) || (xfirst == xsecond && yfirst - 1 == ysecond) || (xfirst + 1 == xsecond && yfirst == ysecond) || (xfirst - 1 == xsecond && yfirst == ysecond))
		{
			std::cout << "second coordinate reached!\n";
			break;
		}
	}

	//sets the entrance and exit position as unique numbers

	matrix[xentry][yentry] = 1;
	matrix[xexit][yexit] = 3;
}