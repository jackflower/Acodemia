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
			///@param && other - referencja do r-wartości
			///
			Sprite(Sprite && other);

			///
			///Destrukror
			///
			~Sprite();

			///
			///Przeciążony operator przypisania kopiowania
			///
			///@param & copy - stała referencja na obiekt klasy Sprite
			///
			Sprite & operator=(const Sprite & copy);

			///
			///Przeciążony operator przypisania przenoszenia
			///
			///@param && other -  referencja do r-wartości
			///
			Sprite & operator=(Sprite && other);

		};
	}//namespace rendering
}//namespace acodemia

#endif//H_SPRITE_ACODEMIA

