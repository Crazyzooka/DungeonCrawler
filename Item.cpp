#include "Item.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

Item::Item() 
{
    Name	= "?";
    Value	= 0;
    Weight	= 0;
}

Item::Item(string i_Name, int i_Value, int i_Weight) {
    Name = i_Name;
    Value = i_Value;
    Weight = i_Weight;
}

Item::~Item() {

}
