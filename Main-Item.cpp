#include<iostream>

#include"Item.cpp"

using namespace std;

int main() {
    Weapon Sword = Weapon("Sword", 25, 10);
    Sword.Damage = 70;
    Sword.Condition = 100;
    Sword.Limb = 1;

    Weapon Axe = Weapon("Axe", 25, 20);
    Axe.Damage = 75;
    Axe.Condition = 110;
    Axe.Limb = 1;

    Weapon Dagger = Weapon("Dagger", 15, 5);
    Sword.Damage = 30;
    Sword.Condition = 100;
    Sword.Limb = 1;

    Armour Shield = Armour("Shield", 20, 20);
    Shield.Defense = 100;
    Shield.Condition = 100;
    Shield.Limb = 2;

    Consumable MedKit = Consumable("Medkit", 25, 10);
    MedKit.size = 100;

    Consumable Bandages = Consumable("Bandages", 15, 5);
    Bandages.size = 50;

    Consumable HealPotion = Consumable("Healing Potion", 35, 5);
    HealPotion.size = 150;

    cout << Sword.Name << " " << Sword.Value << " "<< Sword.Weight << " " << Sword.Damage << " " << endl;
    cout << Shield.Name << " " << Shield.Value << " "<< Shield.Weight << " " << Shield.Defense << " " << endl;
    cout << MedKit.Name << " " << MedKit.Value << " "<< MedKit.Weight << " " << MedKit.size << " " << endl;

    return 0;
}