/*
 _______________________________________
| CAnimFrame.cpp - implementacja klasy. |
| SCI - by Jack Flower February 2009.   |
|_______________________________________|

*/

#include "CAnimFrame.h"

namespace animation
{

	//Konstruktor
	CAnimFrame::CAnimFrame(const sf::Color& color)
	: 
		m_image(0),
		m_color(color)
	{
	}

	//Konstruktor kopiuj¹cy
	CAnimFrame::CAnimFrame(const CAnimFrame& copy)
	: 
		m_image(copy.m_image),
		m_rect(copy.m_rect),
		m_color(copy.m_color)
	{
	}

	//Konstruktor parametryczny
	CAnimFrame::CAnimFrame(const sf::Image& image, const sf::IntRect& rect, const sf::Color& color)
	: 
		m_image(&image),
		m_rect(rect),
		m_color(color)
	{
	}

	//Konstruktor parametryczny
	CAnimFrame::CAnimFrame(const sf::Image& image, const sf::Color& color)
	: 
		m_image(&image),
		m_color(color)
	{
		if (m_image != 0)
			m_rect = sf::IntRect(0, 0, m_image->GetWidth(), m_image->GetHeight());
	}

	//Destruktor
	CAnimFrame::~CAnimFrame()
	{
		m_image = NULL;
	}

}//namespace animation