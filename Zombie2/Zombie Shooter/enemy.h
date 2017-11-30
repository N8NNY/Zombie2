#pragma once
#include "entity.h"
#include "random.h"
#include "Player.h"
class enemy : public entity
{
public:
	//functions
	enemy();
	void update();
	void updateMovement(float deltatime);

	//varaibles
	float movementSpeed;
	int movementLength = 100;
	int attackDamage = 5;
	int counterWalking = 0;
	int direction = 0; // 1 - up, 2 - down, 3 - left, 4 - right
	int counter = 0;
	int hp;
	bool alive = true;
	float enemydelay;
	bool enemybullet = false;


};

