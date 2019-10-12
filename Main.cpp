#include "pch.h"
#include "Functions.h"
#include "GameData.h"
#include <iostream>
#include <string>

int main()
{
	Entity player = createCharacter();

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
	
	clear();

	return 0;
}