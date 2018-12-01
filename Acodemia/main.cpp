#include <iostream>
#include <SFML/Graphics.hpp>
#include "source/rendering/Displayable.h"
#include "source/animation/Animated.h"
#include "source/physicals/physical/Physical.h"
#include "source/physicals/bullet/Bullet.h"
#include "source/physicals/player/Player.h"
#include "source/manager/PhysicalManager.h"




#define _USE_MATH_DEFINES // for C++  
#include <cmath>
#include <math.h>

using namespace acodemia::physical;

int main()
{
	//sf::

	//double halfC = M_PI / 180;
	const double pi = std::acos(-1);
	double xx = M_PI;
	
	int testowanie = 0;

	//sin()
	//

	//std::degr

	
	

	sf::RenderWindow window(sf::VideoMode(800, 600), "Acodemia++ SCI 2018", sf::Style::Close);
	
	
	window.setKeyRepeatEnabled(false);
	
	
	//// B u l l e t
	//acodemia::rendering::Texture tex_bullet;
	//tex_bullet.loadFromFile("../data/bullet.png");
	//tex_bullet.setSmooth(true);

	//Bullet *bullet = gPhysicalManager.CreateBullet();
	//bullet->setTexture(tex_bullet);
	//bullet->setUseDisplayable(true);
	//bullet->setPosition(230, 500);
	//bullet->setMotion(0.f, -1.f);
	//bullet->setSpeed(100.f);
	//bullet->setLifeTime(4.52f);


	// P l a y e r s
	acodemia::rendering::Texture tekstura;
	tekstura.loadFromFile("../data/ship.png");
	tekstura.setSmooth(true);

	Physical *physical;

	//pierwszy - normal
	physical = gPhysicalManager.CreatePlayer();
	physical->setTexture(tekstura);
	physical->setUseDisplayable(true);
	//physical->setPosition(200, 200);
	physical->setScale(2);
	//testy do strzelania...docelowo opakować do metody...
	physical->setOrigin(physical->getLocalBounds().width * 0.5f, physical->getLocalBounds().height * 0.5f);
	//float origin_x = physical->getOrigin().x;
	//float origin_y = physical->getOrigin().y;
	physical->setPosition(200, 200);
	physical->setSpeed(100);

	int warta = 0;
		
	//drugi - red
	physical = gPhysicalManager.CreatePlayer();
	physical->setTexture(tekstura);
	physical->setUseDisplayable(true);
	physical->setPosition(300, 200);
	physical->setColor(sf::Color::Red);
	//player->setScale(1, -1);
	physical->setOrigin(physical->getLocalBounds().width * 0.5f, physical->getLocalBounds().height * 0.5f);
	
	//trzeci - green
	physical = gPhysicalManager.CreatePlayer();
	physical->setTexture(tekstura);
	physical->setUseDisplayable(true);
	physical->setPosition(400, 200);
	physical->setColor(sf::Color::Green);
	physical->setOrigin(physical->getLocalBounds().width * 0.5f, physical->getLocalBounds().height * 0.5f);

	// A c t o r s
	//aktor - blue
	physical = gPhysicalManager.CreateActor();
	physical->setTexture(tekstura);
	physical->setUseDisplayable(true);
	physical->setPosition(500, 200);
	physical->setColor(sf::Color::Blue);

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
