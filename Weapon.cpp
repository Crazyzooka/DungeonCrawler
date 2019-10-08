#include "Weapon.h"
#include "Equipment.h"
#include "Item.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

Weapon::Weapon(string i_Name, int i_Value, int i_Weight):Item(i_Name, i_Value, i_Weight) {
    Damage = 0;
}

void Weapon::SetDamage(int DamageHP) {
    Damage = DamageHP;
}

Weapon::~Weapon() {

}