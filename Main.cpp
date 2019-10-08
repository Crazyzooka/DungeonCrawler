#include "pch.h"
#include "Floorgen.h"
#include "Room.h"
#include "Functions.h"
#include <iostream>
//testing
int main()
{
	int length = FLOORSIZE;
	int floor[FLOORSIZE][FLOORSIZE];

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			floor[j][i] = 0;
		}
	}

	generateFloor(floor, length);
	generatePath(floor, length - 2);

	printFloor(floor, length);

	return 0;
}