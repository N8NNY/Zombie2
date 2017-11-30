#include "Gameplay.h"



Gameplay::Gameplay()
{

}

void Gameplay::update(sf::Event& event)
{
	//Play Game!!
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return && play == false) {
		play = true;
		pause = false;
		level = 1;
		check = 1;
		spawnCount = 0;
	}
	// Puase game !!
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P && play == true) {
		pause = true;
		check = 0;
	}
	//Re Game!!
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space && pause == true) {
		play = true;
		pause = false;
		check = 6;
		spawnCount = 0;
	}
	//Menu Game!!
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Q && pause == true) {
		play = false;
		check = 1;
		spawnCount = 0;
	}
}

void Gameplay::levelupdate(int hp)
{
	if (level == 1 && check == 1 && play == true)
	{
		printf("Level 1\n");
		spawnCount = 10;
		check = 6;
	}
	else if (level == 2 && check == 2)
	{
		printf("Level 2\n");
		spawnCount = 20;
		level = 2;
		check = 6;
	}
	else if (level == 3 && check == 3)
	{
		printf("Level 3\n");
		spawnCount = 30;
		level = 3;
		check = 6;
	}
	else if (level == 4 && check == 4)
	{
		printf("Level 4\n");
		spawnCount = 40;
		//level = 1;
		check = 6;
	}
	else if (level == 5 && check == 5)
	{
		printf("Level 5\n");
		spawnCount = 50;
		//level = 6;
		check = 6;
	}
	else if (level == 5)
	{
		/*std::fstream readscore;
		readscore.open("hightscore.txt", std::ios::in | std::ios::out | std::ios::app);
		readscore << name << " " << score << " ";
		readscore.close();*/


		play = false;
		check = 1;
		spawnCount = 0;
	}
	else if (hp <= 0)
	{
		std::fstream readscore;
		readscore.open("hightscore.txt", std::ios::in | std::ios::out | std::ios::app);
		readscore << name << " " << score << " ";
		readscore.close();


		play = false;
		check = 1;
		spawnCount = 0;
	}
}

void Gameplay::levelcheck(vector<enemy> checksp)
{
	//std::cout << checksp.size() << endl;
	if (checksp.size() == 0) {
		if (check == 6 && level == 1)
		{
			level = 2;
			check = 2;
		}
		else if (check == 6 && level == 2)
		{
			level = 3;
			check = 3;
		}
		else if (check == 6 && level == 3)
		{
			level = 4;
			check = 4;
		}
		else if (check == 6 && level == 4)
		{
			level = 5;
			check = 5;
		}
	}
}

