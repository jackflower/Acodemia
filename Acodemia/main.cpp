#include <iostream>
#include <SFML/Graphics.hpp>
#include "source/rendering/Displayable.h"
#include "source/animation/Animated.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Acodemia++ SCI 2018", sf::Style::Close);

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


	acodemia::rendering::Texture graphics;
	graphics.loadFromFile("../data/ship.png");

	acodemia::rendering::Displayable Destroyer;
	Destroyer.setTexture(graphics);
	Destroyer.setPosition(100, 100);

	acodemia::rendering::Displayable Warrior;
	Warrior.setTexture(graphics);
	Warrior.setPosition(300, 100);

	acodemia::rendering::Displayable Defender;
	Defender.setTexture(graphics);
	Defender.setPosition(200, 300);


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

		window.clear(sf::Color::White);
		Destroyer.draw(window);
		Warrior.draw(window);
		Defender.draw(window);
		animek.draw(&window);
		window.display();
	}

	return 0;
}
