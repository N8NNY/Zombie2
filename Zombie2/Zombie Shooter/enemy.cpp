#include "enemy.h"

enemy::enemy()
{
	rect.setSize(sf::Vector2f(34, 52));
	rect.setPosition(400, 200);
	rect.setFillColor(sf::Color::Blue);
	sprite.setTextureRect(sf::IntRect(0, 0, 32, 45));
	hp = 10;
	movementSpeed = 1.6f;
}

void enemy::update()
{
	sprite.setPosition(rect.getPosition());
}

void enemy::updateMovement(float deltatime)
{
	enemydelay -= deltatime;
	if (direction == 1 && rect.getPosition().y > -5) // Up
	{
		rect.move(0, -movementSpeed);
		sprite.setTextureRect(sf::IntRect(0 + (32 * counterWalking), 3 * 48, 32, 45));

		//enemydelay = 0.04f;
	}
	else if (direction == 2 && rect.getPosition().y < 550) // Down
	{

		rect.move(0, movementSpeed);
		sprite.setTextureRect(sf::IntRect(0 + (32 * counterWalking), 0, 32, 45));
		//enemydelay = 0.04f;
	}
	else if (direction == 3 && rect.getPosition().x > -5) // Left
	{
		rect.move(-movementSpeed, 0);
		sprite.setTextureRect(sf::IntRect(0 + (32 * counterWalking), 48 * 1, 32, 45));
		//enemydelay = 0.04f;
	}
	else if (direction == 4 && rect.getPosition().x < 760) // Right
	{
		rect.move(movementSpeed, 0);
		sprite.setTextureRect(sf::IntRect(0 + (32 * counterWalking), 48 * 2, 32, 45));
		//enemydelay = 0.04f;
	}
	else
	{
		// No movement
	}
	if (enemydelay <= 0) {
		counterWalking++;
		enemydelay = 0.16f;
	}

	if (counterWalking == 3)
	{
		counterWalking = 0;
	}

	counter++;
	if (counter >= movementLength)
	{
		direction = generateRandom(5);
		counter = 0;
	}

}