//acodemia.pl


//uporz¹dkowaæ bajzel...


#include "Physical.h"
namespace acodemia
{
	namespace physical
	{
		//Konstruktor domyœlny
		Physical::Physical()
		:
			m_displayable(),
			m_destruction(false),
			m_use_displayable(false),
			m_position(),
			m_rotation(),
			m_origin(),
			m_scale(1, 1)
		{
		}

		//Konstruktor kopiuj¹cy
		// to do...

		//Konstruktor przenosz¹cy
		//to do...

		//Destruktor wirtualny
		Physical::~Physical()
		{
		}

		void Physical::setUseDisplayable(bool use_displayable)
		{
			m_use_displayable = use_displayable;
		}

		Displayable & Physical::getDisplayable()
		{
			return m_displayable;
		}

		//Metoda ustawia teksturê dla kontekstu graficznego
		void Physical::setTexture(const Texture & texture)
		{
			m_displayable.setTexture(texture);
		}

		void Physical::update(float dt)
		{
			//to do...
		}

		void Physical::draw(sf::RenderWindow & render)
		{
			if (m_use_displayable)
				m_displayable.draw(render);
		}

	}//namespace physical
}//namespace acodemia
