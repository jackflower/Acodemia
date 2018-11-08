﻿//acodemia.pl

#include "Physical.h"

namespace acodemia
{
	namespace physical
	{
		//Konstruktor domyślny
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

		//Konstruktor kopiujący
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

		//Konstruktor przenoszący
		Physical::Physical(Physical && other)
		:
			//przenosimy dane obiektu źródłowego
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

		//Przeciążony operator przypisania kopiowania
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

		//Przeciążony operator przypisania przenoszenia
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

		//Metoda zwraca stałą referencję obiektu - reprezentacja graficzna
		const Displayable & Physical::getDisplayable() const
		{
			return m_displayable;
		}

		//Metoda ustawia referencję na reprezentację graficzną
		void Physical::setDisplayable(const Displayable & displayable)
		{
			m_displayable = displayable;
		}

		//Metoda zwraca flagę, czy obiekt posiada reprezentację graficzną
		const bool Physical::getUseDisplayable() const
		{
			return m_use_displayable;
		}

		void Physical::setUseDisplayable(bool use_displayable)
		{
			m_use_displayable = use_displayable;
		}

		//Meotoda zwraca informację, czy obiekt na być zniszczony
		const bool Physical::getDestruction() const
		{
			return m_destruction;
		}

		//Meotoda ustawia informację, czy obiekt na być zniszczony
		void Physical::setDestruction(bool destruction)
		{
			m_destruction = destruction;
		}


		//Metoda zwraca stałą referencję pozycji obiektu
		const sf::Vector2f & Physical::getPosition() const
		{
			return m_position;
		}

		//Metoda ustawia pozycję obiektu
		void Physical::setPosition(float x, float y)
		{
			m_position.x = x;
			m_position.y = y;
			m_displayable.setPosition(m_position.x, m_position.y);
		}

		//Metoda ustawia pozycję obiektu
		void Physical::setPosition(const sf::Vector2f & vector)
		{
			m_position = vector;
			m_displayable.setPosition(m_position);
		}

		//Metoda zwraca wartość obrotu
		float Physical::getRotation() const
		{
			return m_rotation;
		}

		//Metoda ustawia wartość obrotu
		void Physical::setRotation(float rotation_value)
		{
			m_displayable.setRotation(rotation_value);
		}

		//Metoda obraca wartość obrotu
		void Physical::rotate(float angle)
		{
			m_displayable.rotate(angle);
		}

		//Metoda zwraca skalę
		const sf::Vector2f & Physical::getScale() const
		{
			return m_scale;
		}

		//Metoda ustawia skalę
		void Physical::setScale(float x, float y)
		{
			m_scale.x = x;
			m_scale.y = y;
			m_displayable.setScale(m_scale.x, m_scale.y);
		}

		//Metoda ustawia skalę
		void Physical::setScale(const sf::Vector2f & new_scale_value)
		{
			m_scale = new_scale_value;
			m_displayable.setScale(m_scale);
		}

		//Metoda ustawia skalę
		void Physical::setScale(float factors)
		{
			m_scale.x = m_scale.y = factors;
			m_displayable.setScale(m_scale.x, m_scale.y);
		}

		//Metoda ustawia skalę w stosunku do obecnej skali
		void Physical::scale(float factorX, float factorY)
		{
			m_scale.x = factorX;
			m_scale.y = factorY;
			m_displayable.scale(m_scale.x, m_scale.y);
		}

		//Metoda ustawia skalę w stosunku do obecnej skali
		void Physical::scale(const sf::Vector2f & factor)
		{
			m_scale = factor;
			m_displayable.scale(m_scale);
		}

		//Metoda zwraca współrzędne punktu uchwytu obiektu
		const sf::Vector2f & Physical::getOrigin() const
		{
			return m_origin;
		}

		//Metoda ustawia współrzędne punktu uchwytu obiektu
		void Physical::setOrigin(float x, float y)
		{
			m_origin.x = x;
			m_origin.y = y;
			m_displayable.setOrigin(m_origin.x, m_origin.y);
		}

		//Metoda ustawia współrzędne punktu uchwytu obiektu
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

		//Metoda zwraca granice obiektu w lokalnym w układzie współrzędnych
		sf::FloatRect Physical::getLocalBounds() const
		{
			return m_displayable.getLocalBounds();
		}

		//Metoda zwraca granice obiektu w globalnym w układzie współrzędnych
		sf::FloatRect Physical::getGlobalBounds() const
		{
			return m_displayable.getGlobalBounds();
		}

		//Metoda przemieszcza obiekt o wartość podaną w parametrach względem aktualnej pozycji
		void Physical::move(float offsetX, float offsetY)
		{
			m_displayable.move(offsetX, offsetY);
		}

		//Metoda przemieszcza obiekt o wartość wektora przesunięcia
		void Physical::move(const sf::Vector2f & offset)
		{
			m_displayable.move(offset);
		}

		//Metoda ustawia teksturę dla kontekstu graficznego
		void Physical::setTexture(const Texture & texture)
		{
			m_displayable.setTexture(texture);
			m_stored_color = m_displayable.getColor();
		}

		//Wirtualna metoda aktualizująca obiekt
		void Physical::update(float dt)
		{
			//implementacje w klasach potomnych
		}

		//Wirtualna metoda rysująca obiekt
		void Physical::draw(sf::RenderWindow & render) const
		{
			if (m_use_displayable)
				m_displayable.draw(render);
		}

	}//namespace physical
}//namespace acodemia
