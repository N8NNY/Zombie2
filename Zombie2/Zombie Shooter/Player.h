#pragma once
#include "entity.h"
#include "random.h"
class Player : public entity
{
public:
	//functions
	Player();
	void update();
	void updateMovement(sf::Image bg);

	void updateMovementSpear(int countwalk, float radi, float deltatime);

	void updateMovementBow(int countwalk, float radi, float deltatime);

	void updateMovementDragger(int countwalk, float rad, float deltatime);

	//varaibles
	int movementSpeed = 1;
	int attackDamage = 10;
	int counterWalking = 0;
	int direction = 0; // 1 - up, 2 - down, 3 - left, 4 - right
	int hp = 50;
	int countWalk = 0;
	int arrow;
	float delayItem = 0;
	bool checkItem = false;
	//Sprite
	sf::Sprite Item;
};

