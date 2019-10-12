#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "Entity.h"
#include <string>

const int FLOORSIZE = 7;

int random(int limit);

void wait(float time);
void display(std::string str);
void clear();

void printFloor(int matrix[FLOORSIZE][FLOORSIZE], int size);
void generatePath(int matrix[FLOORSIZE][FLOORSIZE], int length);
void generateFloor(int matrix[FLOORSIZE][FLOORSIZE], int size);

#endif