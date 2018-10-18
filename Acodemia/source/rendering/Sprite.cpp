//acodemia.pl

#include "Sprite.h"

namespace acodemia
{
	namespace rendering
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

		//Konstruktor przenoszący
		Sprite::Sprite(Sprite && other)
		:
			sf::Sprite(other)
		{
		}

		//Destrukror
		Sprite::~Sprite()
		{
		}

		//Przeciążony operator przypisania kopiowania
		Sprite & Sprite::operator=(const Sprite & copy)
		{
			if (this != &copy)
				sf::Sprite::operator=(copy);
			return *this;
		}

		//Przeciążony operator przypisania przenoszenia
		Sprite & Sprite::operator=(Sprite && other)
		{
			if (this != &other)
				sf::Sprite::operator=(other);
			return *this;
		}

	}//namespace rendering
}//namespace acodemia
