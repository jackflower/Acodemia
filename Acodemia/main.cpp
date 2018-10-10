#include <iostream>
#include <SFML/Graphics.hpp>
#include "source/rendering/Displayable.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Acodemia++ SCI 2018", sf::Style::Close);

	//Testy
	//acodemia::rendering::Sprite
	//acodemia::rendering::Texture
	//



	sf::Texture graphics;
	graphics.loadFromFile("../data/ship.png");

	//testy - potem usunąć...
	acodemia::rendering::Displayable Ship;
	Ship.setTexture(graphics);
	Ship.setPosition(100, 100);
	acodemia::rendering::Displayable Twice;
	Twice.setTexture(graphics);
	Twice.setPosition(300, 100);
	acodemia::rendering::Displayable Zorro(Ship);//kopiujący
	acodemia::rendering::Displayable Garcia(std::move(Twice));//przenoszący
	acodemia::rendering::Displayable Jeden;
	Jeden = Ship;//operator przypisania kopiujący...
	Jeden.setPosition(200, 400);
	acodemia::rendering::Displayable Dwa;
	Dwa = std::move(Twice);//operator przypisania przenoszący...
	Dwa.setPosition(400, 400);


	int warta = 0;


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::White);
		Ship.draw(window);
		Twice.draw(window);
		Zorro.draw(window);
		Garcia.draw(window);
		Jeden.draw(window);
		Dwa.draw(window);
		window.display();
	}

	return 0;
}
