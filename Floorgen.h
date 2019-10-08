#ifndef FLOORGEN_H
#define FLOORGEN_H

const int FLOORSIZE = 7;

void printFloor(int matrix[FLOORSIZE][FLOORSIZE], int size);
void generatePath(int matrix[FLOORSIZE][FLOORSIZE], int length);
void generateFloor(int matrix[FLOORSIZE][FLOORSIZE], int size);

#endif
