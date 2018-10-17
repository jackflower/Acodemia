//acodemia.pl

#include "AnimatedFrame.h"

namespace acodemia
{
	namespace animated
	{
		//Konstruktor
		AnimationFrame::AnimationFrame()
		:
			p_texture(nullptr),
			m_rectangle()
		{
		}

		//Konstruktor kopiujący
		AnimationFrame::AnimationFrame(const AnimationFrame & copy)
		:
			p_texture(copy.p_texture),
			m_rectangle(copy.m_rectangle)
		{
		}

		//Konstruktor przenoszący
		AnimationFrame::AnimationFrame(AnimationFrame && other)
		:
			p_texture(nullptr)
		{
			//kopiujemy pod wskaźnik dane obiektu źródłowego
			p_texture = other.p_texture;
			//zwalniamy wskaźnik na dane obiektu źródłowego tak,
			//aby destruktor nie zwalniał pamięci wielokrotnie
			other.p_texture = nullptr;
		}

		//Konstruktor parametryczny
		AnimationFrame::AnimationFrame(const acodemia::rendering::Texture & texture, const sf::IntRect & rectangle)
		:
			p_texture(& texture),
			m_rectangle(rectangle)
		{
		}

		//Konstruktor parametryczny
		AnimationFrame::AnimationFrame(const acodemia::rendering::Texture & texture)
		:
			p_texture(& texture)
		{
			if (p_texture != nullptr)
				m_rectangle = sf::IntRect(0, 0, p_texture->getSize().x, p_texture->getSize().y);
		}

		//Destruktor
		AnimationFrame::~AnimationFrame()
		{
			p_texture = nullptr;
		}

		//Przeciążony operator przypisania kopiowania
		AnimationFrame & AnimationFrame::operator=(const AnimationFrame & copy)
		{
			// to do...
			//look at class Displayable...
			return *this;
		}

		//Przeciążony operator przypisania przenoszenia
		AnimationFrame & AnimationFrame::operator=(AnimationFrame && other)
		{
			//to do...
			//look at class Displayable...
			return *this;
		}

		//Metoda zwraca stały wskaźnik na teksturę klatki animacji z wektora
		const sf::Texture *AnimationFrame::GetFrameImage() const
		{
			return p_texture;
		}

		//Metoda zwraca koordynaty klatki animacji z wektora
		const sf::IntRect AnimationFrame::GetFrameRectangle() const
		{
			return m_rectangle;
		}
	}//namespace animated
}//namespace acodemia