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
	}//namespace rendering
}//namespace acodemia
