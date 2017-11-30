#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include<fstream>
#include<string.h>
#include <iostream>
#include <stdio.h>
#include <Windows.h>
#define PI 3.14159265

//Class 
#include "Player.h"
#include "enemy.h"
#include "random.h"
#include "Shooter.h"
#include "text.h"
#include "Gameplay.h"
#include "pickup.h"

using namespace std;

struct sort_struct
{
	string name;
	int score;
};
sort_struct sortS[30];

bool compare(const sort_struct &lhs, const sort_struct &rhs) { return lhs.score > rhs.score; }


int main(int, char const**)
{
	//Variables
	sf::Clock clock;
	sf::Clock clock2;
	sf::Clock clock3;
	sf::Clock clock4;

	float delayaggro = 0;
	int counter = 0;
	int counter2 = 0;
	int counter3 = 0;
	int spawnCount = 10;
	int bowcount = 15;
	int check = 3;
	int score = 0;
	int boom = 0;
	float delayShoot = 0;
	bool checkitem = false;
	bool checkitem1 = false;
	bool checkitem2 = false;
	bool bulletcount = true;
	bool enemybullet = false;
	string name;
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "Zombie2", sf::Style::Close);
	window.setFramerateLimit(60);
	//------------------------read file------------------------
	std::fstream readscore;
	int  i = 0;
	readscore.open("hightscore.txt", std::ios::in | std::ios::out | std::ios::app);
	while (readscore >> sortS[i].name >> sortS[i].score)
	{
		i = i + 1;
	}
	readscore.close();
	std::sort(begin(sortS), end(sortS), compare);

	for (int j = 0; j < i; j++)
	{
		cout << sortS[j].name << " " << sortS[j].score << "\n";

	}

	//-----------------------------------------Text---------------------------------------------------
	//Text
	text nonny("BebasNeue.otf", "60010421 - Thanat Krasae", 24, sf::Color::Black);
	nonny.update(20, 545);
	text playtext("Font1.ttf", "Play - Enter", 42, sf::Color::Black);
	playtext.update(15, 10);
	text pause("Font1.ttf", "Pause - P", 24, sf::Color::White);
	text black("Font1.ttf", "Menu - Q", 24, sf::Color::White);
	text resume("Font1.ttf", "Resume - Spacebar", 24, sf::Color::White);
	text exit("Font1.ttf", "Exit - Esc", 36, sf::Color::Black);
	exit.update(600, 545);
	text arrow("Font1.ttf", "Arrow", 16, sf::Color::White);
	text howtoplay("Font1.ttf", "How to Play", 24, sf::Color::Red);
	howtoplay.update(315, 150);
	text move("BebasNeue.otf", "W - up, S - Down, A - Left, D - Right", 32, sf::Color::Black);
	move.update(215, 180);
	text htItem("BebasNeue.otf", "1 - Dragger, 2 - Spear, 3 - Bow", 32, sf::Color::Black);
	htItem.update(235, 230);
	text highscore("Font1.ttf", "High Score", 24, sf::Color::Red);
	highscore.update(330, 300);
	text inputname1("Font1.ttf", "Name : ", 24, sf::Color::Red);
	inputname1.update(500, 15);
	text inputname("BebasNeue.otf", " ", 32, sf::Color::Blue);
	inputname.update(600, 10);
	text scoree("BebasNeue.otf", "Scoree : ", 16, sf::Color::White);
	text scoree1("BebasNeue.otf", " ", 24, sf::Color::Black);
	text scoree2("BebasNeue.otf", " ", 24, sf::Color::Black);
	text scoree3("BebasNeue.otf", " ", 24, sf::Color::Black);
	text scoree4("BebasNeue.otf", " ", 24, sf::Color::Black);
	text scoree5("BebasNeue.otf", " ", 24, sf::Color::Black);
	scoree1.update(250, 340);
	scoree2.update(250, 360);
	scoree3.update(250, 380);
	scoree4.update(250, 400);
	scoree5.update(250, 420);
	text scores1("BebasNeue.otf", " ", 24, sf::Color::Black);
	text scores2("BebasNeue.otf", " ", 24, sf::Color::Black);
	text scores3("BebasNeue.otf", " ", 24, sf::Color::Black);
	text scores4("BebasNeue.otf", " ", 24, sf::Color::Black);
	text scores5("BebasNeue.otf", " ", 24, sf::Color::Black);
	scores1.update(450, 340);
	scores2.update(450, 360);
	scores3.update(450, 380);
	scores4.update(450, 400);
	scores5.update(450, 420);

	//-----------------------------------------Text---------------------------------------------------

	//-----------------------------------------Gameplay---------------------------------------------------
	//Gameplay
	Gameplay gameplay;
	//Sount
	sf::Music zombie;
	zombie.openFromFile("zombie-1.wav");
	zombie.setVolume(40);
	sf::Music bow;
	bow.openFromFile("swish_4.wav");
	bow.setVolume(40);
	sf::Music bgsound;
	bgsound.openFromFile("soundbg.wav");
	bgsound.setLoop(true);
	bgsound.setVolume(50);
	bgsound.play();

	//-----------------------------------------Gameplay---------------------------------------------------

	//-----------------------------------------BULLETCOUNT---------------------------------------------------
	// Pickup Vector Array
	vector<pickup>::const_iterator iter11;
	vector<pickup> pickupArray;
	//Class Player
	pickup pickup1;
	// Load a sprite to Enemy																		
	sf::Texture bowbullet;
	if (!bowbullet.loadFromFile("arrow.png")) {
		return EXIT_FAILURE;
	}
	pickup1.sprite.setTexture(bowbullet);
	pickup1.rect.setSize(sf::Vector2f(32, 44));

	//-----------------------------------------BULLETCOUNT---------------------------------------------------
	// Load image
	sf::Image bgcollides;
	bgcollides.loadFromFile("map1.png");
	//-----------------------------------------Player---------------------------------------------------
	// Load a sprite to Player																		
	sf::Texture texturePlayer;
	if (!texturePlayer.loadFromFile("All.png")) {
		return EXIT_FAILURE;
	}
	// Load a sprite to item
	sf::Texture mvDragger;
	if (!mvDragger.loadFromFile("Dagger-move.png")) {
		return EXIT_FAILURE;
	}
	sf::Texture Dragger;
	if (!Dragger.loadFromFile("Dagger.png")) {
		return EXIT_FAILURE;
	}
	//Class Player
	Player Player1;
	Player1.sprite.setTexture(texturePlayer);
	printf("player hp :%d\n", Player1.hp);
	//-----------------------------------------Player---------------------------------------------------

	//---------------------------------------Enemy------------------------------------------------------
	// Load a sprite to Enemy																		
	sf::Texture textureEnemy;
	if (!textureEnemy.loadFromFile("zombie.png")) {
		return EXIT_FAILURE;
	}
	//Enemy Object
	class enemy enemy1;
	enemy1.sprite.setTexture(textureEnemy);
	// Enemy Vector Array5
	vector<enemy>::const_iterator iter4;
	vector<enemy> enemyArray;
	printf("enemy hp : %d\n", enemy1.hp);
	//---------------------------------------Enemy------------------------------------------------------

	//-----------------------------------------Shooter--------------------------------------------------
	//Shooter Object
	class Shooter bullet;
	// Bullet Vector Array
	vector<Shooter>::const_iterator iter;
	vector<Shooter> ShooterArray;
	printf("attackDamage : %d\n", bullet.attackDamage);
	//-----------------------------------------Shooter--------------------------------------------------

	//-----------------------------------------grid---------------------------------------------------
	// Load a Grid																		
	sf::Texture grid;
	if (!grid.loadFromFile("grid.png")) {
		return EXIT_FAILURE;
	}
	sf::Sprite spriteGrid;
	spriteGrid.setTexture(grid);
	sf::Texture bg;
	if (!bg.loadFromFile("map.png")) {
		return EXIT_FAILURE;
	}

	sf::Sprite spbg;
	spbg.setPosition(0, 0);
	spbg.setTexture(bg);
	spriteGrid.setPosition(0, 0);
	//-----------------------------------------grid---------------------------------------------------

	// Start the game loop
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			// Escape pressed: exit
			if (event.type == sf::Event::KeyPressed &&  event.key.code == sf::Keyboard::Escape && gameplay.play == false) {
				window.close();
			}
			if (gameplay.play == false) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
				{
					if (name.size() >= 1)
					{
						name.erase(name.size() - 1, 1);
						inputname.Text.setString(name);
						Sleep(100);
					}
				}
				else if (event.type == sf::Event::TextEntered)
				{

					if (event.text.unicode < 128 && event.text.unicode > 94 && name.size() < 8)
					{
						name += static_cast<char>(event.text.unicode);
						inputname.Text.setString(name);
					}
				}
			}
			//Gameplay
			gameplay.update(event);
		}

		//-----------------------------------------View---------------------------------------------------
		// View
		sf::View viewPlayer(sf::Vector2f(0, 0), sf::Vector2f(533, 400));
		sf::View default(sf::Vector2f(400, 300), sf::Vector2f(800, 600));
		sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
		sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
		//viewPlayer.setCenter(sf::Vector2f(Player1.rect.getPosition().x, Player1.rect.getPosition().y));
		//-----------------------------------------View---------------------------------------------------



		if (Player1.rect.getPosition().x < 264)
		{
			viewPlayer.setCenter(sf::Vector2f(264, Player1.rect.getPosition().y));
		}
		else if (Player1.rect.getPosition().x > 1332) {
			viewPlayer.setCenter(sf::Vector2f(1332, Player1.rect.getPosition().y));
		}
		else if (Player1.rect.getPosition().y < 200) {
			viewPlayer.setCenter(sf::Vector2f(Player1.rect.getPosition().x, 200));
		}
		else if (Player1.rect.getPosition().y >1) {
			viewPlayer.setCenter(sf::Vector2f(Player1.rect.getPosition().x, 1400));
		}
		else
		{
			viewPlayer.setCenter(sf::Vector2f(Player1.rect.getPosition().x, Player1.rect.getPosition().y));
		}

		// Clear screen
		window.clear();




		//Gameplay
		gameplay.levelcheck(enemyArray);
		gameplay.levelupdate(Player1.hp);

		//printf("%f\n", worldPos.x);
		// Clock
		sf::Time elapsed1 = clock.getElapsedTime();
		sf::Time elapsed2 = clock2.getElapsedTime();
		sf::Time elapsed3 = clock3.getElapsedTime();
		sf::Time elapsed4 = clock4.getElapsedTime();
		// Deltatime
		float deltatime = clock3.restart().asSeconds();

		//grid
		if (gameplay.play == false) {
			window.draw(spriteGrid);
			Player1.hp = 50;
			Player1.arrow = 15;
			score = 0;
			check = 3;
			//------------------------read file------------------------
			//std::fstream readscore;
			//int  i = 0;
			//readscore.open("hightscore.txt", std::ios::in | std::ios::out | std::ios::app);
			//while (readscore >> sortS[i].name >> sortS[i].score)
			//{
			//	i = i + 1;
			//}
			//readscore.close();
			//std::sort(begin(sortS), end(sortS), compare);

			//for (int j = 0; j < i; j++)
			//{
			//	//cout << sortS[j].name << " " << sortS[j].score << "\n";

			//}
		}
		else {
			window.draw(spbg);
		}

		// Player collides with Pickup Item
		counter = 0;
		for (iter11 = pickupArray.begin(); iter11 != pickupArray.end(); iter11++)
		{
			if (Player1.rect.getGlobalBounds().intersects(pickupArray[counter].rect.getGlobalBounds()))
			{
				if (pickupArray[counter].isCoin == true)
				{
					Player1.arrow += pickupArray[counter].coinValue;
				}

				pickupArray[counter].destroy = true;
			}

			counter++;
		}

		//Enemy Collides with Player
		if (elapsed2.asSeconds() >= 1)
		{
			clock2.restart();
			// Enemy Collides with Player (Player takes damage)
			counter = 0;
			for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
			{

				if (Player1.rect.getGlobalBounds().intersects(enemyArray[counter].rect.getGlobalBounds()))
				{
					// Text Display

					Player1.hp -= enemyArray[counter].attackDamage;
					zombie.play();
					printf("Player hp : %d\n", Player1.hp);
				}

				counter++;
			}
		}
		// Enemy Aggro (AI)
		counter = 0;
		for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
		{
			if (enemyArray[counter].enemybullet == true && gameplay.play == true && gameplay.pause == false)
			{
				printf("%d\n", counter);
				if (elapsed4.asSeconds() >= 0.3f)
				{
					clock4.restart();
					int tempRand = generateRandom(2);
					if (tempRand == 1) {
						if (Player1.rect.getPosition().y < enemyArray[counter].rect.getPosition().y)
						{
							enemyArray[counter].direction = 1;
						}
						else if (Player1.rect.getPosition().y > enemyArray[counter].rect.getPosition().y)
						{
							enemyArray[counter].direction = 2;
						}
						else if (Player1.rect.getPosition().x < enemyArray[counter].rect.getPosition().x)
						{
							enemyArray[counter].direction = 3;
						}
						else if (Player1.rect.getPosition().x > enemyArray[counter].rect.getPosition().x)
						{
							enemyArray[counter].direction = 4;
						}
					}
					else if (tempRand == 2)
					{
						if (Player1.rect.getPosition().x < enemyArray[counter].rect.getPosition().x)
						{
							enemyArray[counter].direction = 3;
						}
						else if (Player1.rect.getPosition().x > enemyArray[counter].rect.getPosition().x)
						{
							enemyArray[counter].direction = 4;
						}
						else if (Player1.rect.getPosition().y < enemyArray[counter].rect.getPosition().y)
						{
							enemyArray[counter].direction = 1;
						}
						else if (Player1.rect.getPosition().y > enemyArray[counter].rect.getPosition().y)
						{
							enemyArray[counter].direction = 2;
						}
					}
				}

			}
			counter++;
		}


		// Bullet Collides with Enemy
		counter = 0;
		for (iter = ShooterArray.begin(); iter != ShooterArray.end(); iter++)
		{
			counter2 = 0;
			for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
			{
				if (ShooterArray[counter].o.getGlobalBounds().intersects(enemyArray[counter2].rect.getGlobalBounds()))
				{
					//cout << "NON" << endl;
					ShooterArray[counter].destroy = true;
					enemyArray[counter2].hp -= ShooterArray[counter].attackDamage;

					printf("damage : %d\n", enemyArray[counter2].hp);
					if (enemyArray[counter2].hp <= 0)
					{
						enemyArray[counter2].alive = false;
					}
					enemyArray[counter2].enemybullet = true;
				}

				counter2++;
			}

			counter++;
		}

		// Delete Dead Enemy
		counter = 0;
		for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
		{
			if (enemyArray[counter].alive == false)
			{
				//cout << "Enemy has been obliterated! lawlz" << endl;

				// Drop Coin
				if (generateRandom(4) == 1)
				{
					pickup1.rect.setPosition(enemyArray[counter].rect.getPosition());
					pickupArray.push_back(pickup1);
				}
				score += 10;
				enemyArray.erase(iter4);
				break;
			}
			if (gameplay.play == false) {
				enemyArray.erase(iter4);
				break;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) boom = 1;
			if (Player1.hp < 10 && boom == 1) {
				enemyArray.erase(iter4);
				boom = 0;
				break;
			}
			counter++;
		}

		// Delete Projectile
		counter = 0;
		for (iter = ShooterArray.begin(); iter != ShooterArray.end(); iter++)
		{
			if (ShooterArray[counter].destroy == true)
			{
				ShooterArray.erase(iter);
				break;
			}
			counter++;
		}

		// Delete Pickup Items
		counter = 0;
		for (iter11 = pickupArray.begin(); iter11 != pickupArray.end(); iter11++)
		{
			if (pickupArray[counter].destroy == true)
			{
				pickupArray.erase(iter11);
				break;
			}
			counter++;
		}

		if (check == 1)
		{
			check = 0;
		}
		// Shoot Bullet 360
		delayShoot -= deltatime;
		bullet.update(worldPos, Player1.rect);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && delayShoot <= 0 && gameplay.check != 0 && bulletcount == true && check == 2)
		{
			bow.play();
			bullet.o.setPosition(bullet.playerCenter);
			bullet.currVelocity = bullet.aimDirNorm * bullet.movementSpeed;
			ShooterArray.push_back(Shooter(bullet));
			delayShoot = 0.60f;
		}
		else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && delayShoot <= 0 && gameplay.check != 0 && Player1.arrow > 0 && bulletcount == false)
		{
			bow.play();
			bullet.o.setPosition(bullet.playerCenter);
			bullet.currVelocity = bullet.aimDirNorm * bullet.movementSpeed;
			ShooterArray.push_back(Shooter(bullet));
			delayShoot = 0.60f;
			Player1.arrow--;
		}

		// Bullet move & erase
		for (size_t i = 0; i <ShooterArray.size(); i++) {
			ShooterArray[i].o.move(ShooterArray[i].currVelocity);
		}
		// Draw Pickup Items
		counter = 0;
		for (iter11 = pickupArray.begin(); iter11 != pickupArray.end(); iter11++)
		{
			pickupArray[counter].update();
			window.draw(pickupArray[counter].sprite);
			counter++;
		}

		// Draw Bullet
		counter = 0;
		for (iter = ShooterArray.begin(); iter != ShooterArray.end(); iter++)
		{
			ShooterArray[counter].updateMovement();
			if (check == 0)window.draw(ShooterArray[counter].o);
			counter++;
		}
		// Spawn Enemy
		if (gameplay.spawnCount > 0)
		{
			enemy1.rect.setPosition(generateRandom(1500), generateRandom(1500));
			enemyArray.push_back(enemy(enemy1));
			gameplay.spawnCount--;
		}

		// Draw Enemies
		counter = 0;
		for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++)
		{
			enemyArray[counter].update();
			if (gameplay.check != 0) enemyArray[counter].updateMovement(deltatime);
			if (gameplay.play == true) {
				//window.draw(enemyArray[counter].rect);
				window.draw(enemyArray[counter].sprite);

			}
			counter++;
		}
		//Item

		//Update Player
		Player1.update();

		if (gameplay.play == true && gameplay.pause == false) {
			Player1.update();
			Player1.updateMovement(bgcollides);
		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && gameplay.play == true && gameplay.pause == false) //มีด
		{
			checkitem = true;
			checkitem1 = false;
			checkitem2 = false;
			bullet.Lifetime = 1.0f;
			bullet.movementSpeed = 30;
			Player1.countWalk = 0;
			bullet.attackDamage = 2;
			printf("attackDM : %d\n", bullet.attackDamage);
			bulletcount = true;
			check = 2;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && gameplay.play == true && gameplay.pause == false) //หอก
		{
			checkitem1 = true;
			checkitem = false;
			checkitem2 = false;
			bullet.Lifetime = 1.5f;
			bullet.movementSpeed = 30;
			bullet.attackDamage = 1;
			Player1.countWalk = 0;
			printf("attackDM : %d\n", bullet.attackDamage);
			bulletcount = true;
			check = 2;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) && gameplay.play == true && gameplay.pause == false) //ธนู
		{
			checkitem2 = true;
			checkitem = false;
			checkitem1 = false;
			bullet.Lifetime = 40.f;
			bullet.movementSpeed = 15;
			bullet.attackDamage = 4;
			Player1.countWalk = 0;
			printf("attackDM : %d\n", bullet.attackDamage);
			bulletcount = false;
			check = 1;
		}
		if (checkitem == true) Player1.updateMovementDragger(5, bullet.rad, deltatime); //มีด
		if (checkitem1 == true) Player1.updateMovementSpear(7, bullet.rad, deltatime); //หอก
		if (checkitem2 == true) Player1.updateMovementBow(13, bullet.rad, deltatime); //ธนู

																					  //Draw Player
																					  //window.draw(Player1.rect);

																					  //updateText
		arrow.update(viewPlayer.getCenter().x - 260, viewPlayer.getCenter().y - 190);
		scoree.update(viewPlayer.getCenter().x - 45, viewPlayer.getCenter().y + 180);
		pause.update(viewPlayer.getCenter().x + 125, viewPlayer.getCenter().y - 195);
		resume.update(viewPlayer.getCenter().x - 125, viewPlayer.getCenter().y);
		black.update(viewPlayer.getCenter().x + 130, viewPlayer.getCenter().y - 195);
		//Text menu
		arrow.Text.setString("Aroow : " + to_string(Player1.arrow));
		scoree.Text.setString("Score : " + to_string(score));
		scoree1.Text.setString(sortS[0].name);
		scoree2.Text.setString(sortS[1].name);
		scoree3.Text.setString(sortS[2].name);
		scoree4.Text.setString(sortS[3].name);
		scoree5.Text.setString(sortS[4].name);
		scores1.Text.setString(to_string(sortS[0].score));
		scores2.Text.setString(to_string(sortS[1].score));
		scores3.Text.setString(to_string(sortS[2].score));
		scores4.Text.setString(to_string(sortS[3].score));
		scores5.Text.setString(to_string(sortS[4].score));
		gameplay.readScore(name, score);
		if (gameplay.play == false) {
			//nonny
			window.draw(nonny.Text);

			window.draw(playtext.Text);
			window.draw(exit.Text);
			window.draw(howtoplay.Text);
			window.draw(htItem.Text);
			window.draw(move.Text);
			window.draw(highscore.Text);
			window.draw(inputname1.Text);
			window.draw(inputname.Text);
			window.setView(default);
			//name
			window.draw(scoree1.Text);
			window.draw(scoree2.Text);
			window.draw(scoree3.Text);
			window.draw(scoree4.Text);
			window.draw(scoree5.Text);
			//score
			window.draw(scores1.Text);
			window.draw(scores2.Text);
			window.draw(scores3.Text);
			window.draw(scores4.Text);
			window.draw(scores5.Text);
		}
		else if (gameplay.pause == true) {
			window.draw(resume.Text);
			window.draw(black.Text);


		}
		else if (gameplay.play == true) {
			window.draw(Player1.sprite);
			window.draw(pause.Text);
			window.draw(arrow.Text);
			window.draw(scoree.Text);
			window.setView(viewPlayer);
		}
		//if(check == 0)window.draw(arrow.Text);

		// Update the window
		window.display();

	}
}