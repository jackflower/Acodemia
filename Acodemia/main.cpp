#include <iostream>
#include <SFML/Graphics.hpp>
#include "source/rendering/Displayable.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Acodemia++ SCI 2018", sf::Style::Close);

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

		window.clear(sf::Color::White);
		Destroyer.draw(window);
		Warrior.draw(window);
		Defender.draw(window);
		window.display();
	}

	return 0;
}
