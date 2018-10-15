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
		///Klasa reprezentuje klatk� animacji
		//
		class AnimationFrame
		{
		public:

			///
			//Konstruktor domy�lny
			///
			AnimationFrame();

			///
			///Konstruktor kopiuj�cy
			///
			///@param & copy - sta�a referencja na obiekt klasy AnimationFrame
			///
			AnimationFrame(const AnimationFrame & copy);

			///
			///Konstruktor przenosz�cy
			///
			///@param && other = referencja do r-warto�ci
			///
			AnimationFrame(AnimationFrame && other);

			///
			///Konstruktor parametryczny
			///
			///@param & texture - tekstura
			///
			///@param & rectangle - obszar prostok�tny tekstury
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
			///Przeci��ony operator przypisania kopiowania
			///
			///@param & copy - sta�a referencja na obiekt klasy AnimationFrame
			///
			AnimationFrame & operator=(const AnimationFrame & copy);

			///
			///Przeci��ony operator przypisania przenoszenia
			///
			///@param && other -  referencja do r-warto�ci
			///
			AnimationFrame & operator=(AnimationFrame && other);
			

			///
			///Metoda zwraca sta�y wska�nik na tekstur� klatki animacji z wektora
			///
			const sf::Texture *GetFrameImage() const;

			///
			///Metoda zwraca koordynaty klatki animacji z wektora
			///
			const sf::IntRect GetFrameRectangle() const;

		private:

			const sf::Texture*	p_texture;		//wska�nik na tekstur�
			sf::IntRect			m_rectangle;	//obszar prostok�tny klatki animacji
			//analiza - sk�adowe
		};
	}//namespace animated
}//namespace acodemia
#endif // H_ANIMATION_FRAME_JACK
