#include "Item.h"
#include "Consumable.h"
#include "Entity.h"
#include "Effect.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

Consumable::Consumable() {

}

void Consumable::ApplyToAll(Entity Entity) {
    size = LimbHP.size();
    for(int i = 0; i < size; i++) {

    }
}

bool Consumable::ApplyToLimb(int Limb) {

}

Consumable::~Consumable() {

}