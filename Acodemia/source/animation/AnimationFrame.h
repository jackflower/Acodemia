//
//acodemia.pl
//

#ifndef H_ANIMATION_FRAME_JACK
#define H_ANIMATION_FRAME_JACK

#include "../rendering/Texture.h"

namespace acodemia
{
	namespace animation
	{
		///
		///Klasa reprezentuje klatkę animacji
		//
		class AnimationFrame
		{
		public:

			///
			//Konstruktor domyślny
			///
			AnimationFrame();

			///
			///Konstruktor kopiujący
			///
			///@param & copy - stała referencja na obiekt klasy AnimationFrame
			///
			AnimationFrame(const AnimationFrame & copy);

			///
			///Konstruktor przenoszący
			///
			///@param && other = referencja do r-wartości
			///
			AnimationFrame(AnimationFrame && other);

			///
			///Konstruktor parametryczny
			///
			///@param & texture - stała referencja na teksturę
			///
			///@param & rectangle - stała referencja na obszar prostokątny tekstury
			///
			AnimationFrame(const acodemia::rendering::Texture & texture, const sf::IntRect & rectangle);

			///
			///Konstruktor parametryczny
			///
			///@param & texture - stała referencja na teksturę
			///
			AnimationFrame(const acodemia::rendering::Texture & texture);
			
			///
			///Destruktor
			///
			~AnimationFrame();

			///
			///Przeciążony operator przypisania kopiowania
			///
			///@param & copy - stała referencja na obiekt klasy AnimationFrame
			///
			AnimationFrame & operator=(const AnimationFrame & copy);

			///
			///Przeciążony operator przypisania przenoszenia
			///
			///@param && other -  referencja do r-wartości
			///
			AnimationFrame & operator=(AnimationFrame && other);

			///
			///Metoda zwraca stały wskaźnik na teksturę klatki animacji z wektora
			///
			const sf::Texture *GetFrameImage() const;

			///
			///Metoda zwraca koordynaty klatki animacji z wektora
			///
			const sf::IntRect GetFrameRectangle() const;

		private:

			const acodemia::rendering::Texture *p_texture;//stały wskaźnik na teksturę
			sf::IntRect m_rectangle;//obszar prostokątny klatki animacji
		};
	}//namespace animation
}//namespace acodemia
#endif // H_ANIMATION_FRAME_JACK
