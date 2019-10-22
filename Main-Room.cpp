#include "pch.h"
#include "Room.h"
#include "Item.h"
#include "Entity.h"
#include "Effect.h"
#include "Classlib.h"
#include "Functions.h"

#include<iostream>
#include<vector>
#include<string>

using namespace std;

void createRoom(Classlib *library, int Description, Entity Player) {
    Room Room;
    int numItems = myRandom(5);

    Room.GenerateRoom(library->getNPC(myRandom(library->NPCSize)), library->getEffect(myRandom(library->effectSize)), Player);
    Room.Player = Player;
    Room.RoomName = "Room";

    for(int i = 0; i < numItems; i++) {
        Room.RoomItems[i] = library->getItem(myRandom(library->itemSize));
    }
    
}

/*int main() {
    //ENTITIES
    Player Player1;
    NPC Merchant;
    NPC Monk;    
    NPC Ghost;
    NPC Monster1;
    NPC Boss1;

    Weapon Sword = Weapon("Sword", 10, 5);
    Armour Shield = Armour("Shield", 10, 20);
    Consumable MedKit = Consumable("Medkit", 50, 5);
    Consumable Bandages = Consumable("Bandages", 15, 5);
    Consumable HealPotion = Consumable("Healing Potion", 35, 5);
    Weapon Axe = Weapon("Axe", 25, 20);
    Weapon Dagger = Weapon("Dagger", 15, 5);

    std::vector<Item> ItemsEmpty;

    std::vector<Item> ItemsShop;
    ItemsShop.push_back(Axe);
    ItemsShop.push_back(Dagger);
    ItemsShop.push_back(Sword);
    ItemsShop.push_back(Shield);
    ItemsShop.push_back(Medkit);

    std::vector<Item> ItemsTemple;
    ItemsTemple.push_back(MedKit);
    ItemsTemple.push_back(Bandages);
    ItemsTemple.push_back(HealPotion);

    //EFFECTS
    Effect Warm;
    Effect Spooky;  
    Effect Cold;

    //SHOP
    Room Shop;
    Shop.GenerateRoom(Merchant, Warm, 3);
    Shop.RoomItems = ItemsShop;
    Shop.Player = Player1;
    Shop.RoomName = "Shop"

    //TEMPLE
    Room Temple;
    Temple.GenerateRoom(Monk, Warm, 3);
    Temple.RoomItems = ItemsTemple;
    Temple.Player = Player1;
    Temple.RoomName = "Temple"

    //EMPTY
    Room EmptyRoom;
    EmptyRoom.GenerateRoom(Ghost, Cold, 0);
    EmptyRoom.RoomItems = ItemsEmpty;
    EmptyRoom.Player = Player1;
    EmptyRoom.RoomName = "Empty Room"

    //MONSTER ROOM 1


    //MONSTER ROOM 1
    Room BossRoom1;
    BossRoom1.GenerateRoom(Boss1, Cold, 0);
    BossRoom1.RoomItems = ItemsEmpty;
    BossRoom1.Player = Player1;
    BossRoom1.RoomName = "BossRoom1"


    return 0;
}
*/
