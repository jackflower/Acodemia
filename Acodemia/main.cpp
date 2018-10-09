#include <iostream>
#include <SFML/Graphics.hpp>
#include "source/rendering/Sprite.h"

int main()
{
	acodemia::rendering::Sprite duszek;


	//Testowanie poprawności kodowania znaków UTF-8
	//
	//Łabędź żródło znalazł mądrzej patrzeć może teraz łąką się kończąc...

	sf::RenderWindow window(sf::VideoMode(800, 600), "Acodemia++ SCI 2018", sf::Style::Close);

	sf::Texture graphics;
	graphics.loadFromFile("../data/ship.png");

	sf::Sprite Ship;
	Ship.setTexture(graphics);
	Ship.setPosition(300, 300);

	duszek.setTexture(graphics);
	duszek.setPosition(500, 300);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}


		window.clear(sf::Color::White);
		window.draw(Ship);
		window.draw(duszek);
		window.display();
	}

	return 0;
}
