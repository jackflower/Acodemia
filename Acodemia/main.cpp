#include <iostream>
#include <SFML/Graphics.hpp>
#include "source/rendering/Displayable.h"
#include "source/animation/Animated.h"
#include "source/physicals/physical/Physical.h"
#include "source/physicals/bullet/Bullet.h"
#include "source/physicals/player/Player.h"
#include "source/manager/PhysicalManager.h"


using namespace acodemia::physical;

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Acodemia++ SCI 2018", sf::Style::Close);

	// B u l l e t
	acodemia::rendering::Texture tex_bullet;
	tex_bullet.loadFromFile("../data/bullet.png");
	tex_bullet.setSmooth(true);

	Bullet *bullet = new Bullet();
	bullet->setTexture(tex_bullet);
	bullet->setUseDisplayable(true);
	bullet->setPosition(100, 500);
	//bullet->destroy();
	

	//
	sf::Transformable desdemona;
	//desdemona.no


	// a c o d e m i a   library
	acodemia::rendering::Texture tekstura;
	tekstura.loadFromFile("../data/ship.png");
	tekstura.setSmooth(true);

	// G r a c z
	Player *player = new Player();
	player->setTexture(tekstura);
	player->setUseDisplayable(true);
	player->setPosition(200, 200);
	player->setColor(sf::Color::Red);
	//player->destroy();
	//player->setDestruction(true);
	
	
	Player *player_demo = new Player();
	player_demo->setTexture(tekstura);
	player_demo->setUseDisplayable(true);
	player_demo->setPosition(400, 200);
	//player_demo->destroy();
	//player_demo->setDestruction(true);

	//Testy fabryki...
	gPhysicalManager.registerPhysical(player);
	gPhysicalManager.registerPhysical(player_demo);
	gPhysicalManager.registerPhysical(bullet);
	
	int warta = 0;


	sf::Clock clock;
	float time = 0.0f;
	float zegarek = 0.f;


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

		zegarek = zegarek + time;
		if(zegarek > 3)
			player_demo->setDestruction(true);
		if (zegarek > 5)
			player->setDestruction(true);

		animek.update(time);
	
		gPhysicalManager.updatePhysical(time);

		window.clear(sf::Color::White);
		animek.draw(&window);
		gPhysicalManager.draw(window);
		window.display();
	}
	return 0;
}
