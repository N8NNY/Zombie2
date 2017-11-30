#pragma once
#include "entity.h"
#define PI 3.14159265
class Shooter : public entity
{
public:
	//functions
	Shooter();
	void update(sf::Vector2f window, sf::RectangleShape pyPosition);
	void updateMovement();

	//varaibles
	float movementSpeed = 30.f;
	int attackDamage;
	bool destroy = false;
	int counterLifetime = 0;
	float Lifetime = 1.f;
	double rad;
	sf::CircleShape o;
	sf::Vector2f playerCenter;
	sf::Vector2f aimDir;
	sf::Vector2f mousPosWindow;
	sf::Vector2f currVelocity;
	sf::Vector2f aimDirNorm;
};

