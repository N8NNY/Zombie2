#pragma once
#include "entity.h"
#include <vector>
#include "enemy.h"
#include "Player.h"
#include <string.h>
#include<iostream>
#include<fstream>

class Gameplay : public entity
{
public:
	// Functions
	Gameplay();

	void readScore(string name, int score)
	{
		this->name = name;
		this->score = score;
	}
	void update(sf::Event& event);
	void levelupdate(int hp);
	void levelcheck(vector<enemy>);
	// Variable
	int level = 1;
	int check = 1;
	bool play = false;
	bool pause = false;
	int spawnCount = 0;
private:
	string name;
	int score;

};

