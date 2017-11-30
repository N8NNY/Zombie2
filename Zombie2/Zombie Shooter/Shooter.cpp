#include "Shooter.h"
using namespace sf;


Shooter::Shooter()
{
	rect.setSize(sf::Vector2f(10, 10));
	rect.setPosition(0, 0);
	rect.setFillColor(sf::Color::Blue);
	o.setRadius(5.f);
	o.setFillColor(sf::Color::Red);
	attackDamage = 5;

	//sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
}

void Shooter::update(sf::Vector2f worldPos, sf::RectangleShape pyPosition)
{
	playerCenter = sf::Vector2f(pyPosition.getPosition().x, pyPosition.getPosition().y);
	mousPosWindow = sf::Vector2f(worldPos.x, worldPos.y);
	aimDir = mousPosWindow - playerCenter;
	aimDirNorm = aimDir / sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));
	rad = atan2f(aimDir.y, aimDir.x) * 180 / PI;

}

void Shooter::updateMovement()
{
	if (Mouse::isButtonPressed(Mouse::Left) && rad >= -90 && rad <= 0)
	{
		o.move(0, -1.f);
	}
	else if (Mouse::isButtonPressed(Mouse::Left) && rad >= 0 && rad <= 90)
	{
		o.move(0, 1.f);
	}
	else if (Mouse::isButtonPressed(Mouse::Left) && rad >= 90 && rad <= 180)
	{
		o.move(-1.f, 0);
	}
	else if (Mouse::isButtonPressed(Mouse::Left) && rad >= 180 && rad <= -90)
	{
		o.move(1.f, 0);
	}
	counterLifetime++;
	if (counterLifetime >= Lifetime)
	{
		destroy = true;
	}
}