#pragma once
#include "entity.h"
class pickup : public entity
{
public:
	//Function
	pickup();
	void update();
	// Variable
	bool isCoin = true;
	int coinValue = 5;
	bool destroy = false;

};

