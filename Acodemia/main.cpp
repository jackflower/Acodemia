#include <iostream>
#include <SFML/Graphics.hpp>
#include "source/rendering/Displayable.h"
#include "source/animation/Animated.h"
#include "../Acodemia/source/physicals/bullet/Bullet.h"
#include "../Acodemia/source/physicals/player/Player.h"
#include "source/manager/PhysicalManager.h"
#include "source/physicals/physical/Physical.h"

using namespace acodemia::physical;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Acodemia++ SCI 2018", sf::Style::Close);
	
	//gPhysicalManager - testy
	std::vector<Physical*> physicals = gPhysicalManager.getPhysicals();
	bool t_01 = physicals.at(0)->getDestruction();
	bool t_02 = physicals.at(1)->getDestruction();
	bool t_03 = physicals.at(2)->getDestruction();

	int demko = 0;

	//gPhysicalManager.Alabama();
	//gPhysicalManager.Nebraska();
	//PhysicalManager::getSingleton().Alabama();
	//PhysicalManager::getSingleton().Nebraska();


	// a c o d e m i a   library
	acodemia::rendering::Texture tekstura;
	tekstura.loadFromFile("../data/ship.png");
	tekstura.setSmooth(true);



	// G r a c z
	Player player;
	player.setTexture(tekstura);
	player.setUseDisplayable(true);
	player.setPosition(200, 200);
	player.setColor(sf::Color::Red);
	player.restoreColor();
	//player.setScale(2);
	//float szerokosc_global = player.getDisplayable().getGlobalBounds().width;
	//float szerokosc_local = player.getDisplayable().getLocalBounds().width;
	//Player player_demo;
	//player_demo = player;
	//player_demo.setPosition(400, 200);
	//player_demo.restoreColor();
	int warta = 0;


	// P o c i s k
	//Bullet pocisk;
	//pocisk.setTexture(tekstura);
	//pocisk.setUseDisplayable(true);


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
		//player.rotate(0.01f);
		//player.move(0.0125f, 0);

		window.clear(sf::Color::White);
		animek.draw(&window);
		player.draw(window);
		window.display();
	}

	return 0;
}
