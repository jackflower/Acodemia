/*
 _______________________________________
| CAnimFrame.h - definicja klasy.       |
| SCI - by Jack Flower February 2009.   |
|_______________________________________|

*/

#ifndef ANIM_FRAME_JACK
#define ANIM_FRAME_JACK

#include <SFML/Graphics.hpp>

namespace animation
{

	///
	///Klasa reprezentuje klatk� animacji
	class CAnimFrame
	{
	public :
	
		///
		////Konstruktor domy�lny
		///
		CAnimFrame(const sf::Color& color = sf::Color::White);
	
		///
		///Konstruktor kopiuj�cy
		///
		///@param &copy - obiekt klasy CAnimFrame
		///
		CAnimFrame(const CAnimFrame& copy);

		///
		///Konstruktor parametryczny
		///
		///@param &image - tekstura
		///
		///@param &rect	- obszar tekstury
		///
		///@param &color - kolor
		///
		CAnimFrame(const sf::Image& image, const sf::IntRect& rect, const sf::Color& color = sf::Color::White);

		///
		///Konstruktor parametryczny
		///
		///@param &image - tekstura
		///
		///@param &color - kolor
		///
		CAnimFrame(const sf::Image& image, const sf::Color& color = sf::Color::White);
	
		///
		///Destruktor
		///
		~CAnimFrame();

		///
		///Metoda zwraca tekstur� klatki animacji z wektora
		///
		sf::ResourcePtr<sf::Image> GetFrameImage() {return m_image;}

		///
		///Metoda zwraca koordynaty klatki animacji z wektora
		///
		sf::IntRect GetFrameRectangle() {return m_rect;}

		///
		///Metoda zwraca kolor klatki animacji z wektora
		///
		sf::Color GetFrameColor() {return m_color;}

	private:
		sf::ResourcePtr<sf::Image>	m_image;	//wska�nik na tekstur�
		sf::IntRect					m_rect;		//obszar prostok�tny
		sf::Color					m_color;	//kolor
	};

}//namespace animation

#endif // ANIM_FRAME_JACK
