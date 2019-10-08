#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Item {
    public:

		Item();
		Item(string i_Name, int i_Value, int i_Weight);

		//VARIABLES
		string Name;
		vector<string> Effects;
		int Value;
		int Weight;

		~Item();
};

#endif