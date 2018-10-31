//
//acodemia.pl
//

#ifndef H_BULLET_ACODEMIA
#define H_BULLET_ACODEMIA

#include "SFML/Graphics.hpp"
#include "../physical/Physical.h"

//uporządkować bajzel...

namespace acodemia
{
	namespace physical
	{
		///
		///Klasa reprezentje pocisk
		///
		class Bullet : public Physical
		{
		public:

			///
			///Konstruktor domyślny
			///
			Bullet();

			///
			///Konstruktor kopiujący
			///

			///
			///Konstruktor przenoszący
			///

			///
			///Destruktor wirtualny
			///
			virtual ~Bullet();

			///
			///Przeciążony operator przypisania kopiowania
			///
			///@param & copy - stała referencja na obiekt klasy Bullet
			///
			//Bullet & operator=(const Bullet & copy);

			///
			///Przeciążony operator przypisania przenoszenia
			///
			///@param && other -  referencja do r-wartości
			///
			//Bullet & operator=(Bullet && other);

			///
			///Metoda ustawia teksturę dla kontekstu graficznego
			///
			///@param & texture - stała referencja na obiekt klasy Texture
			///
			//void setTexture(const Texture & texture);

			//void Load(const Texture & texture);

		private:

			//sf::Sprite m_sprite;
			float m_speed;
			//sf::Vector2f m_position;
			float			m_caliber;			//kaliber - siła rażenia
		};
	}//namespace physical
}//namespace acodemia
#endif//H_BULLET_ACODEMIA
