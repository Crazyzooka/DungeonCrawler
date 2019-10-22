#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Entity.h"
#include <string>

enum ROOMS
{
	Entrance = 1,
	Path = 2,
	Exit = 3,
	PlayerMark = 4,
};

const int FLOORSIZE = 7;

int myRandom(int limit);
std::string input(std::string u_input);

void wait(float time);
void display(std::string str);

void printFloor(int matrix[FLOORSIZE][FLOORSIZE], int size);
void generatePath(int matrix[FLOORSIZE][FLOORSIZE], int length);
void generateFloor(int matrix[FLOORSIZE][FLOORSIZE], int size);

#endif