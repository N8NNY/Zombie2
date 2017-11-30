#include "Player.h"



Player::Player()
{
	//Player
	hp = 50;
	arrow = 15;
	rect.setSize(sf::Vector2f(36, 55));
	rect.setPosition(300, 500);
	rect.setOrigin(18, 27);
	rect.setFillColor(sf::Color::Blue);
	sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
	sprite.setOrigin(32, 32);
}

void Player::update()
{
	sprite.setPosition(rect.getPosition());
	Item.setPosition(rect.getPosition());
}

void Player::updateMovement(sf::Image bg)
{
	// w = -10 s= 535 a=-15 d= 750
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (bg.getPixel(rect.getPosition().x, rect.getPosition().y - movementSpeed) != sf::Color::Black) {
			rect.move(0, -movementSpeed);
			sprite.setTextureRect(sf::IntRect(counterWalking * 64, 64 * 0, 64, 64));
			direction = 1;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (bg.getPixel(rect.getPosition().x, (rect.getPosition().y + movementSpeed + 28)) != sf::Color::Black) {
			rect.move(0, movementSpeed);
			sprite.setTextureRect(sf::IntRect(counterWalking * 64, 2 * 64, 64, 64));
			direction = 2;
		}

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if (bg.getPixel(rect.getPosition().x - movementSpeed - 10, rect.getPosition().y) != sf::Color::Black) {
			rect.move(-movementSpeed, 0);
			sprite.setTextureRect(sf::IntRect(counterWalking * 64, 64 * 1, 64, 64));
			direction = 3;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (bg.getPixel(rect.getPosition().x + movementSpeed + 10, rect.getPosition().y) != sf::Color::Black) {
			rect.move(movementSpeed, 0);
			sprite.setTextureRect(sf::IntRect(counterWalking * 64, 64 * 3, 64, 64));
			direction = 4;
		}
	}

	counterWalking++;

	if (counterWalking == 8)
	{
		counterWalking = 0;
	}
}

void Player::updateMovementDragger(int countwalk, float radi, float deltatime)
{
	delayItem -= deltatime;
	// w = -10 s= 535 a=-15 d= 750
	//printf("Dragger\n");
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && radi >= -145 && radi < -45) //up
	{
		sprite.setTextureRect(sf::IntRect(countWalk * 64, 64 * 8, 64, 64));
		direction = 1;
		checkItem = true;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && radi  > 45 && radi <= 145) //Down
	{
		sprite.setTextureRect(sf::IntRect(countWalk * 64, 10 * 64, 64, 64));
		direction = 2;
		checkItem = true;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (radi  > 145 && radi <= 180 || radi >= -180 && radi < -145)) //Left
	{
		sprite.setTextureRect(sf::IntRect(countWalk * 64, 64 * 9, 64, 64));
		direction = 3;
		checkItem = true;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && radi >= -45 && radi < 45) //Right
	{
		sprite.setTextureRect(sf::IntRect(countWalk * 64, 64 * 11, 64, 64));
		direction = 4;
		checkItem = true;
	}
	if (countWalk == 5)
	{
		countWalk = 0;
	}
	if (delayItem <= 0) {
		countWalk++;
		delayItem = 0.1f;
	}
}

void Player::updateMovementSpear(int countwalk, float radi, float deltatime)
{
	delayItem -= deltatime;
	// w = -10 s= 535 a=-15 d= 750
	//printf("Spear\n");
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && radi >= -145 && radi < -45) //up
	{
		sprite.setTextureRect(sf::IntRect(countWalk * 64, 64 * 16, 64, 64));
		direction = 1;
		checkItem = true;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && radi  > 45 && radi <= 145) //Down
	{
		sprite.setTextureRect(sf::IntRect(countWalk * 64, 18 * 64, 64, 64));
		direction = 2;
		checkItem = true;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (radi  > 145 && radi <= 180 || radi >= -180 && radi < -145)) //Left
	{
		sprite.setTextureRect(sf::IntRect(countWalk * 64, 64 * 17, 64, 64));
		direction = 3;
		checkItem = true;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && radi >= -45 && radi < 45) //Right
	{
		sprite.setTextureRect(sf::IntRect(countWalk * 64, 64 * 19, 64, 64));
		direction = 4;
		checkItem = true;
	}
	if (delayItem <= 0) {
		countWalk++;
		delayItem = 0.1f;
		if (countWalk == 7)
		{
			countWalk = 0;
		}
	}

}

void Player::updateMovementBow(int countwalk, float radi, float deltatime)
{
	delayItem -= deltatime;
	// w = -10 s= 535 a=-15 d= 750
	//printf("Bow\n");
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && radi >= -145 && radi < -45) //up
	{
		sprite.setTextureRect(sf::IntRect(countWalk * 64, 64 * 20, 64, 64));
		direction = 1;
		checkItem = true;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && radi  > 45 && radi <= 145) //Down
	{
		sprite.setTextureRect(sf::IntRect(countWalk * 64, 22 * 64, 64, 64));
		direction = 2;
		checkItem = true;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && (radi  > 145 && radi <= 180 || radi >= -180 && radi < -145)) //Left
	{
		sprite.setTextureRect(sf::IntRect(countWalk * 64, 64 * 21, 64, 64));
		direction = 3;
		checkItem = true;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && radi >= -45 && radi < 45) //Right
	{
		sprite.setTextureRect(sf::IntRect(countWalk * 64, 64 * 23, 64, 64));
		direction = 4;
		checkItem = true;
	}
	if (delayItem <= 0) {
		countWalk++;
		delayItem = 0.1f;
	}
	if (countWalk == 13)
	{
		countWalk = 0;
	}
}