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
		///Klasa reprezentuje klatkê animacji
		//
		class AnimationFrame
		{
		public:

			///
			//Konstruktor domyœlny
			///
			AnimationFrame();

			///
			///Konstruktor kopiuj¹cy
			///
			///@param & copy - sta³a referencja na obiekt klasy AnimationFrame
			///
			AnimationFrame(const AnimationFrame & copy);

			///
			///Konstruktor przenosz¹cy
			///
			///@param && other = referencja do r-wartoœci
			///
			AnimationFrame(AnimationFrame && other);

			///
			///Konstruktor parametryczny
			///
			///@param & texture - tekstura
			///
			///@param & rectangle - obszar prostok¹tny tekstury
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
			///Przeci¹¿ony operator przypisania kopiowania
			///
			///@param & copy - sta³a referencja na obiekt klasy AnimationFrame
			///
			AnimationFrame & operator=(const AnimationFrame & copy);

			///
			///Przeci¹¿ony operator przypisania przenoszenia
			///
			///@param && other -  referencja do r-wartoœci
			///
			AnimationFrame & operator=(AnimationFrame && other);
			

			///
			///Metoda zwraca sta³y wskaŸnik na teksturê klatki animacji z wektora
			///
			const sf::Texture *GetFrameImage() const;

			///
			///Metoda zwraca koordynaty klatki animacji z wektora
			///
			const sf::IntRect GetFrameRectangle() const;

		private:

			const sf::Texture*	p_texture;		//wskaŸnik na teksturê
			sf::IntRect			m_rectangle;	//obszar prostok¹tny klatki animacji
			//analiza - sk³adowe
		};
	}//namespace animated
}//namespace acodemia
#endif // H_ANIMATION_FRAME_JACK
