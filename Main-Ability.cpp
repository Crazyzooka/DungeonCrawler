#include "Ability.cpp"
#include "Effect.cpp"

#include <iostream>

using namespace std;

int main() {
    Ability Burning = Ability();
    Burning.Name = "Burning";
    Burning.Damage = 100;

    cout << Burning.ApplyCost() << endl;

    return 0;
}