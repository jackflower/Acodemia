#include "Sprite.h"


namespace acodemia
{
	//Konstruktor
	Sprite::Sprite()
	:
		sf::Sprite()//konstruktor klasy bazowej
	{
	}

	//Konstruktor kopiujący
	Sprite::Sprite(const Sprite & copy)
	:
		sf::Sprite(copy)//konstruktor kopiujący klasy bazowej
	{
	}

	///
	///Konstruktor przenoszący
	///
	//To do...

	//Destrukror
	Sprite::~Sprite()
	{
	}
}//namespace acodemia
