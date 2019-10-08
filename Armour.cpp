#include "Armour.h"
#include "Item.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

Armour::Armour(string i_Name, int i_Value, int i_Weight):Item(i_Name, i_Value, i_Weight) {
    Defense = 0;
}

void Armour::SetDefense(int DefenseHP) {
    Defense = DefenseHP;
}

Armour::~Armour() {

}