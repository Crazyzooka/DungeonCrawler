#include "Equipment.h"
#include "Item.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

Equipment::Equipment(string i_Name, int i_Value, int i_Weight):Item(i_Name, i_Value, i_Weight) {
    Condition = 0;
    Limb = " ";
}

void Equipment::SetEquipment(int i_Condition, Entity i_Limb) {
    Condition = i_Condition;
    Limb = i_Limb;
}

Equipment::~Equipment() {

}