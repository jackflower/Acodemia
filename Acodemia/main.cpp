﻿#include <iostream>
#include <SFML/Graphics.hpp>
#include "source/rendering/Displayable.h"
#include "source/animation/Animated.h"
#include "source/physicals/physical/Physical.h"
#include "source/physicals/bullet/Bullet.h"
#include "source/physicals/player/Player.h"
#include "source/physicals/enemy/Enemy.h"
#include "source/manager/PhysicalManager.h"
#include "source/explosion/Explosion.h"
#include "source/enemygenerator/EnemyGenerator.h"

#include <random>

using namespace acodemia::physical;

float width = 800;

int main()
{
	//class random generator...testy
	//waste


	//testy ok
	for (int i = 0; i < 100; i++)
		std::cout << gEnemyGenerator.getRandomFloat(10.f, 100.f) << std::endl;


	int warta = 0;

	////random generator...
	//// Seed with a real random value, if available
	//std::random_device r;
	//std::default_random_engine generator(r());
	//std::uniform_int_distribution<int> distribution(1, 6);
	//std::uniform_real_distribution<float> dfloat(0.25f, 1.125f);
	//int dice_roll = distribution(generator);  // generates number in the range 1..6 
	//float zenek = dfloat(generator);
	//std::cout << "Randomly-chosen mean: " << dice_roll << '\n';
	//std::cout << "Randomly-chosen mean float: " << zenek << '\n';

	//gEnemyGenerator.getSingleton();

	sf::RenderWindow window(sf::VideoMode(800, 600), "Acodemia++ SCI 2018", sf::Style::Close);
	window.setKeyRepeatEnabled(false);


	//2019-04-13 sobota - begin

	// E x p l o s i o n
	acodemia::rendering::Texture explosion_texture;
	explosion_texture.loadFromFile("../data/explosion.png");
	explosion_texture.setSmooth(true);

	// B u l l e t
	acodemia::rendering::Texture bullet_texture;
	bullet_texture.loadFromFile("../data/bullet.png");
	bullet_texture.setSmooth(true);

	// P l a y e r s
	acodemia::rendering::Texture player_texture;
	//player_texture.loadFromFile("../data/ship.png");
	player_texture.loadFromFile("../data/ship_x.png");
	player_texture.setSmooth(true);

	//Enemies
	acodemia::rendering::Texture enemy_texture;
	enemy_texture.loadFromFile("../data/enemy.png");
	enemy_texture.setSmooth(true);

	Actor *physical;
	// P l a y e r
	physical = gPhysicalManager.CreatePlayer();
	physical->setTexture(player_texture);
	physical->setUseDisplayable(true);
	physical->setBulletTexture(&bullet_texture);
	physical->setBulletSpeed(300.f);
	physical->setBulletMotion(sf::Vector2f(0,-1));
	physical->setBulletCaliber(3.0f);
	physical->setBulletLifeTime(4.125f);
	physical->setGunRate(0.5f);
	physical->setScale(2);
	physical->setOrigin(physical->getLocalBounds().width * 0.5f, physical->getLocalBounds().height * 0.5f);
	physical->setPosition(200, 200);
	physical->setSpeed(100);
	physical->setUpsideDown(false);
	//dane eksplozji...
	physical->setExplosionTexture(&explosion_texture);
	physical->setExplosionFrameSize(64, 64);
	physical->setExplosionSpeed(0.25f);

	//sprawdzić geometrycznie promień kolizji...
	float width = physical->getGlobalBounds().width;
	int alabama = 0;

	// EnemyGenerator - future...
	// E n e m i e s
	physical = gPhysicalManager.CreateEnemy();
	physical->setTexture(enemy_texture);
	physical->setUseDisplayable(true);
	physical->setBulletTexture(&bullet_texture);
	physical->setBulletSpeed(400.f);
	physical->setBulletMotion(sf::Vector2f(0, 1));
	physical->setBulletCaliber(2.0f);
	physical->setBulletLifeTime(3.25f);
	physical->setGunRate(2.25f);
	physical->setOrigin(physical->getLocalBounds().width * 0.5f, physical->getLocalBounds().height * 0.5f);
	physical->setPosition(500, -170);
	//physical->setPosition(0, 0);
	physical->setSpeed(50);
	physical->setScale(1, -1);
	physical->setUpsideDown(true);
	//dane eksplozji...
	physical->setExplosionTexture(&explosion_texture);
	physical->setExplosionFrameSize(64, 64);
	physical->setExplosionSpeed(1.f);
	
	//bool in_camera = physical->inCamera();
	//int kamera = 0;
	
	sf::Clock clock;
	float time = 0.0f;

	//Animation  u s a g e  -  logo SCI
	acodemia::rendering::Texture animation_texture;
	animation_texture.loadFromFile("../data/logo_sci_atlas.png");
	acodemia::animation::Animation animacja;
	animacja.setAnimationFramesFromAtlasTexture(animation_texture, 50, 50);
	acodemia::animation::Animated animek;
	animek.setAnimation(&animacja);
	animek.setPosition(700.f, 100.f);
	animek.setAnimationSpeed(1.5f);
	//Animation  u s a g e  -  logo SCI

	////e x p l o s i o n  usage
	//std::string name;
	//name = "../data/explosion.png";
	//acodemia::animation::Explosion *explosion = gPhysicalManager.CreateExplosion();
	//explosion->setExplosionTexture(explosion_texture, 64, 64);
	//explosion->setPosition(500.f, 300.f);
	//explosion->setAnimationSpeed(0.25f);
	//explosion->setScale(6, 6);
	////e x p l o s i o n  usage

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
