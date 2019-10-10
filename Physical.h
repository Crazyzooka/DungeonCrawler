#ifndef PHYSICAL_H
#define PHYSICAL_H

#include "Ability.h"

#include <iostream>
#include <vector>
#include <string.h>

class Physical : public Ability {
public:
	Physical();
	int ApplyCost(Item inputItem);
	~Physical();
};
#endif 