#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"
#include "Equipment.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Weapon : public Equipment,Item {
    public:
    Weapon(string i_Name, int i_Value, int i_Weight);
    void SetDamage(int DamageHP);

    //VARIABLES
    int Damage;
    ~Weapon();
};
#endif