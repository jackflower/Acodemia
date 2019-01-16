#include <iostream>
#include <SFML/Graphics.hpp>
#include "source/rendering/Displayable.h"
#include "source/animation/Animated.h"
#include "source/physicals/physical/Physical.h"
#include "source/physicals/bullet/Bullet.h"
#include "source/physicals/player/Player.h"
#include "source/physicals/enemy/Enemy.h"
#include "source/manager/PhysicalManager.h"
#include <random>

#define _USE_MATH_DEFINES // for C++  
#include <cmath>
#include <math.h>
using namespace acodemia::physical;



int main()
{

	std::default_random_engine
		URBG{ std::random_device{}() };

	// to emulate rand() or random()
	std::uniform_int_distribution<long>
		dist(0, RAND_MAX);

	//for (int i = 0; i < 10; i++)
	//{
	//	long next_random = dist(URBG);
	//	std::cout << next_random << std::endl;
	//}
	
	std::srand((unsigned)time(nullptr));

	for (int i = 0; i < 10; i++)
	{
		int liczba = std::rand();
		std::cout << liczba << std::endl;
	}
	

	sf::RenderWindow window(sf::VideoMode(800, 600), "Acodemia++ SCI 2018", sf::Style::Close);
	window.setKeyRepeatEnabled(false);


	//2018-12-08 sobota - begin
	// B u l l e t
	acodemia::rendering::Texture bullet_texture;
	bullet_texture.loadFromFile("../data/bullet.png");
	bullet_texture.setSmooth(true);

	// P l a y e r s
	acodemia::rendering::Texture player_texture;
	player_texture.loadFromFile("../data/ship.png");
	player_texture.setSmooth(true);

	Actor *physical;

	//pierwszy - normal
	physical = gPhysicalManager.CreatePlayer();
	physical->setTexture(player_texture);
	physical->setUseDisplayable(true);
	physical->setBulletTexture(&bullet_texture);
	physical->setBulletSpeed(50.f);
	physical->setBulletMotion(sf::Vector2f(0,-1));
	physical->setBulletCaliber(3.0f);
	physical->setBulletLifeTime(4.125f);
	physical->setGunRate(1.125f);
	physical->setScale(2);
	physical->setOrigin(physical->getLocalBounds().width * 0.5f, physical->getLocalBounds().height * 0.5f);
	physical->setPosition(200, 200);
	physical->setSpeed(100);
	physical->setUpsideDown(false);

	//drugi - red
	physical = gPhysicalManager.CreatePlayer();
	physical->setTexture(player_texture);
	physical->setUseDisplayable(true);
	physical->setPosition(300, 200);
	physical->setColor(sf::Color::Red);
	physical->setOrigin(physical->getLocalBounds().width * 0.5f, physical->getLocalBounds().height * 0.5f);
	
	//trzeci - green
	physical = gPhysicalManager.CreatePlayer();
	physical->setTexture(player_texture);
	physical->setUseDisplayable(true);
	physical->setPosition(400, 200);
	physical->setColor(sf::Color::Green);
	physical->setOrigin(physical->getLocalBounds().width * 0.5f, physical->getLocalBounds().height * 0.5f);

	// A c t o r s
	//aktor - blue
	physical = gPhysicalManager.CreateActor();
	physical->setTexture(player_texture);
	physical->setUseDisplayable(true);
	physical->setPosition(500, 200);
	physical->setColor(sf::Color::Blue);

	// E n e m i e s
	physical = gPhysicalManager.CreateEnemy();
	physical->setTexture(player_texture);
	physical->setUseDisplayable(true);
	physical->setBulletTexture(&bullet_texture);
	physical->setBulletSpeed(400.f);
	physical->setBulletMotion(sf::Vector2f(0, 1));
	physical->setBulletCaliber(2.0f);
	physical->setBulletLifeTime(0.5f);
	physical->setGunRate(0.25f);
	physical->setOrigin(physical->getLocalBounds().width * 0.5f, physical->getLocalBounds().height * 0.5f);
	physical->setPosition(500, 70);
	physical->setSpeed(10);
	physical->setScale(1, -1);
	physical->setUpsideDown(true);
	

	//	physical = gPhysicalManager.CreatePlayer();
	//	physical->setTexture(player_texture);
	//	physical->setUseDisplayable(true);
	//	physical->setBulletTexture(&bullet_texture);
	//		physical->setScale(2);
	//	physical->setOrigin(physical->getLocalBounds().width * 0.5f, physical->getLocalBounds().height * 0.5f);
	//physical->setPosition(200, 200);
	//physical->setSpeed(100);



	sf::Clock clock;
	float time = 0.0f;

	//usage
	acodemia::rendering::Texture animation_texture;
	animation_texture.loadFromFile("../data/logo_sci_atlas.png");
	acodemia::animation::Animation animacja;
	animacja.setAnimationFramesFromAtlasTexture(animation_texture, 50, 50);
	acodemia::animation::Animated animek;
	animek.setAnimation(&animacja);
	animek.setPosition(700.f, 100.f);
	animek.setAnimationSpeed(2.f);
	//usage

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		time = clock.restart().asSeconds();

		animek.update(time);
		gPhysicalManager.updatePhysical(time);
		window.clear(sf::Color::White);
		animek.draw(&window);
		gPhysicalManager.draw(window);
		window.display();
	}
	return 0;
}
