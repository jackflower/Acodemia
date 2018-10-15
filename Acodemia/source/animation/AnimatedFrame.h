//
//acodemia.pl
//

#ifndef H_ANIMATION_FRAME_JACK
#define H_ANIMATION_FRAME_JACK

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

namespace acodemia
{
	namespace animated
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
			///@param & texture - tekstura
			///
			///@param & rectangle - obszar prostokątny tekstury
			///
			AnimationFrame(const sf::Texture & texture, const sf::IntRect & rectangle);

			///
			///Konstruktor parametryczny
			///
			///@param & texture - tekstura
			///
			AnimationFrame(const sf::Texture & texture);
			
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

			const sf::Texture*	p_texture;		//wskaźnik na teksturę
			sf::IntRect			m_rectangle;	//obszar prostokątny klatki animacji
			//analiza - składowe
		};
	}//namespace animated
}//namespace acodemia
#endif // H_ANIMATION_FRAME_JACK
