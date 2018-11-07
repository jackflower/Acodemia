//acodemia.pl

#include "Physical.h"

namespace acodemia
{
	namespace physical
	{
		//Konstruktor domyœlny
		Physical::Physical()
		:
			m_displayable(),
			m_use_displayable(false),
			m_destruction(false),
			m_position(),
			m_rotation(),
			m_scale(1, 1),
			m_origin(),
			m_color(),
			m_stored_color()
		{
		}

		//Konstruktor kopiuj¹cy
		Physical::Physical(const Physical & copy)
		:
			m_displayable(copy.m_displayable),
			m_use_displayable(copy.m_use_displayable),
			m_destruction(copy.m_destruction),
			m_position(copy.m_position),
			m_rotation(copy.m_rotation),
			m_scale(copy.m_scale),
			m_origin(copy.m_origin),
			m_color(copy.m_color),
			m_stored_color(copy.m_stored_color)
		{
		}

		//Konstruktor przenosz¹cy
		Physical::Physical(Physical && other)
		:
			//przenosimy dane obiektu Ÿród³owego
			//m_displayable(std::move(other.m_displayable)),
			m_displayable(other.m_displayable),
			m_use_displayable(other.m_use_displayable),
			m_destruction(other.m_destruction),
			m_position(other.m_position),
			m_rotation(other.m_rotation),
			m_scale(other.m_scale),
			m_origin(other.m_origin),
			m_color(other.m_color),
			m_stored_color(other.m_stored_color)
		{
		}

		//Destruktor wirtualny
		Physical::~Physical()
		{
			//nothing to do...
		}

		//Przeci¹¿ony operator przypisania kopiowania
		Physical & Physical::operator=(const Physical & copy)
		{
			if (this != &copy)
			{
				m_displayable = copy.m_displayable;
				m_use_displayable = copy.m_use_displayable;
				m_destruction = copy.m_destruction;
				m_position = copy.m_position;
				m_rotation = copy.m_rotation;
				m_scale = copy.m_scale;
				m_origin = copy.m_origin;
				m_color = copy.m_color;
				m_stored_color = copy.m_stored_color;
			}
			return *this;
		}

		//Przeci¹¿ony operator przypisania przenoszenia
		Physical & Physical::operator=(Physical && other)
		{
			if (this != &other)
			{
				m_displayable = other.m_displayable;
				m_use_displayable = other.m_use_displayable;
				m_destruction = other.m_destruction;
				m_position = other.m_position;
				m_rotation = other.m_rotation;
				m_scale = other.m_scale;
				m_origin = other.m_origin;
				m_color = other.m_color;
				m_stored_color = other.m_stored_color;
			}
			return *this;
		}

		//Metoda zwraca sta³¹ referencjê obiektu - reprezentacja graficzna
		const Displayable & Physical::getDisplayable() const
		{
			return m_displayable;
		}

		//Metoda ustawia referencjê na reprezentacjê graficzn¹
		void Physical::setDisplayable(const Displayable & displayable)
		{
			m_displayable = displayable;
		}

		//Metoda zwraca flagê, czy obiekt posiada reprezentacjê graficzn¹
		const bool Physical::getUseDisplayable() const
		{
			return m_use_displayable;
		}

		void Physical::setUseDisplayable(bool use_displayable)
		{
			m_use_displayable = use_displayable;
		}

		//Meotoda zwraca informacjê, czy obiekt na byæ zniszczony
		const bool Physical::getDestruction() const
		{
			return m_destruction;
		}

		//Meotoda ustawia informacjê, czy obiekt na byæ zniszczony
		void Physical::setDestruction(bool destruction)
		{
			m_destruction = destruction;
		}


		//Metoda zwraca sta³¹ referencjê pozycji obiektu
		const sf::Vector2f & Physical::getPosition() const
		{
			return m_position;
		}

		//Metoda ustawia pozycjê obiektu
		void Physical::setPosition(float x, float y)
		{
			m_position.x = x;
			m_position.y = y;
			m_displayable.setPosition(m_position.x, m_position.y);
		}

		//Metoda ustawia pozycjê obiektu
		void Physical::setPosition(const sf::Vector2f & vector)
		{
			m_position = vector;
			m_displayable.setPosition(m_position);
		}

		//Metoda zwraca wartoœæ obrotu
		float Physical::getRotation() const
		{
			return m_rotation;
		}

		//Metoda ustawia wartoœæ obrotu
		void Physical::setRotation(float rotation_value)
		{
			m_displayable.setRotation(rotation_value);
		}

		//Metoda obraca wartoœæ obrotu
		void Physical::rotate(float angle)
		{
			m_displayable.rotate(angle);
		}

		//Metoda zwraca skalê
		const sf::Vector2f & Physical::getScale() const
		{
			return m_scale;
		}

		//Metoda ustawia skalê
		void Physical::setScale(float x, float y)
		{
			m_scale.x = x;
			m_scale.y = y;
			m_displayable.setScale(m_scale.x, m_scale.y);
		}

		//Metoda ustawia skalê
		void Physical::setScale(const sf::Vector2f & new_scale_value)
		{
			m_scale = new_scale_value;
			m_displayable.setScale(m_scale);
		}

		//Metoda ustawia skalê
		void Physical::setScale(float factors)
		{
			m_scale.x = m_scale.y = factors;
			m_displayable.setScale(m_scale.x, m_scale.y);
		}

		//Metoda ustawia skalê w stosunku do obecnej skali
		void Physical::scale(float factorX, float factorY)
		{
			m_scale.x = factorX;
			m_scale.y = factorY;
			m_displayable.scale(m_scale.x, m_scale.y);
		}

		//Metoda ustawia skalê w stosunku do obecnej skali
		void Physical::scale(const sf::Vector2f & factor)
		{
			m_scale = factor;
			m_displayable.scale(m_scale);
		}

		//Metoda zwraca wspó³rzêdne punktu uchwytu obiektu
		const sf::Vector2f & Physical::getOrigin() const
		{
			return m_origin;
		}

		//Metoda ustawia wspó³rzêdne punktu uchwytu obiektu
		void Physical::setOrigin(float x, float y)
		{
			m_origin.x = x;
			m_origin.y = y;
			m_displayable.setOrigin(m_origin.x, m_origin.y);
		}

		//Metoda ustawia wspó³rzêdne punktu uchwytu obiektu
		void Physical::setOrigin(const sf::Vector2f & origin)
		{
			m_origin = origin;
			m_displayable.setOrigin(m_origin);
		}

		//Metoda zwraca kolor obiektu
		const sf::Color&  Physical::getColor() const
		{
			return m_color;
		}

		//Metoda ustawia kolor obiektu
		void Physical::setColor(const sf::Color & color)
		{
			m_color = color;
			m_displayable.setColor(m_color);
		}

		//Metoda ustawia oryginalny kolor obiektu
		void Physical::restoreColor()
		{
			setColor(m_stored_color);
		}

		//Metoda zwraca granice obiektu w lokalnym w uk³adzie wspó³rzêdnych
		sf::FloatRect Physical::getLocalBounds() const
		{
			return m_displayable.getLocalBounds();
		}

		//Metoda zwraca granice obiektu w globalnym w uk³adzie wspó³rzêdnych
		sf::FloatRect Physical::getGlobalBounds() const
		{
			return m_displayable.getGlobalBounds();
		}

		//Metoda przemieszcza obiekt o wartoœæ podan¹ w parametrach wzglêdem aktualnej pozycji
		void Physical::move(float offsetX, float offsetY)
		{
			m_displayable.move(offsetX, offsetY);
		}

		//Metoda przemieszcza obiekt o wartoœæ wektora przesuniêcia
		void Physical::move(const sf::Vector2f & offset)
		{
			m_displayable.move(offset);
		}

		//Metoda ustawia teksturê dla kontekstu graficznego
		void Physical::setTexture(const Texture & texture)
		{
			m_displayable.setTexture(texture);
			m_stored_color = m_displayable.getColor();
		}

		//Wirtualna metoda aktualizuj¹ca obiekt
		void Physical::update(float dt)
		{
			//implementacje w klasach potomnych
		}

		//Wirtualna metoda rysuj¹ca obiekt
		void Physical::draw(sf::RenderWindow & render) const
		{
			if (m_use_displayable)
				m_displayable.draw(render);
		}

	}//namespace physical
}//namespace acodemia
