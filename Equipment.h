#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include "Item.h"
#include "Entity.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Equipment : public Item {
    public:
    Equipment(string i_Name, int i_Value, int i_Weight);

    //VARIABLES
    int Condition;
    vector<Entity> SkillsRequire[];
    Entity Limb; 

    //FUNCTIONS
    void SetEquipment(int i_Condition, Entity i_Limb);

    ~Equipment();
};
#endif