//acodemia.pl

#ifndef H_SPRITE_ACODEMIA
#define H_SPRITE_ACODEMIA

#include "SFML/Graphics/Sprite.hpp"

namespace acodemia
{
	///
	///Klasa reprezentuje opakowanie
	///
	class Sprite : public sf::Sprite
	{
	public:

		///
		///Konstruktor
		///
		Sprite();

		///
		///Konstruktor kopiujący
		///
		Sprite(const Sprite & copy);

		///
		///Konstruktor przenoszący
		///
		//To do...

		///
		///Destrukror
		///
		~Sprite();
	};
}//namespace acodemia

#endif//H_SPRITE_ACODEMIA

