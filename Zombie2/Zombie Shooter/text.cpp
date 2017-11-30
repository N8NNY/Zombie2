#include "text.h"



text::text(string load, string textt, int size, sf::Color cl)
{
	Font.loadFromFile(load);
	Text.setFont(Font);
	Text.setString(textt);
	Text.setCharacterSize(size);
	Text.setFillColor(cl);
}

void text::update(int x, int y)
{
	Text.setPosition(x, y);
}