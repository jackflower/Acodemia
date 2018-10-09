//
//acodemia.pl
//

#ifndef H_SPRITE_ACODEMIA
#define H_SPRITE_ACODEMIA

#include "SFML/Graphics/Sprite.hpp"

namespace acodemia
{
	namespace rendering
	{
		///
		///Klasa reprezentuje opakowanie bibliotecznej klasy sf::Sprite
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
			///@param & copy - stała referencja na obiekt klasy Sprite
			///
			Sprite(const Sprite & copy);

			///
			///Konstruktor przenoszący
			///
			///@param && other = referencja do r-wartości
			///
			Sprite(Sprite && other);

			///
			///Destrukror
			///
			~Sprite();

			//To do...
			///przenoszący operator przypisania...
			//klasa& klasa::operator=(klasa &&);
		};
	}//namespace rendering
}//namespace acodemia

#endif//H_SPRITE_ACODEMIA

