#pragma once
#include "entity.h"
using namespace std;
class text : public entity
{
public:
	//Function
	text(string load, string textt, int size, sf::Color cl);
	void update(int x, int y);
	//Variable
	sf::Font Font;
	sf::Text Text;
};

