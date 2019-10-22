#ifndef EFFECT_H
#define EFFECT_H

#include <string>
#include <vector>

#include "Entity.h"

using namespace std;

class Effect
{
public:
	string Name;
	vector<int> statModify[5];

	Effect();

	void removeItem(Entity person);
	void changeStats(Entity person);

	~Effect();
};
#endif