#ifndef ARMOUR_H
#define ARMOUR_H

#include "Item.h"
#include "Equipment.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Armour : public Equipment {
    public:
    Armour(string i_Name, int i_Value, int i_Weight);
    void SetDefense(int DefenseHP);

    //VARIABLES
    int Defense;
    ~Armour();
};
#endif