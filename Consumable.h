#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include "Item.h"
#include "Entity.h"
#include "Effect.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Consumable : public Item {
    public:
    Consumable();

    //VARIABLES
    int size;

    //FUNCTIONS
    void ApplyToAll(Entity Entity);
    void ApplyToLimb(int Limb);

    ~Consumable();
};
#endif