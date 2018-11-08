﻿//
//acodemia.pl
//

#ifndef H_PHYSICAL_ACODEMIA
#define H_PHYSICAL_ACODEMIA

#include "../../rendering/Displayable.h"

using namespace acodemia::rendering;

namespace acodemia
{
	namespace physical
	{
		///
		///Klasa reprezentuje behawioralne cechy fizyczne i logiczne
		///
		class Physical
		{

		public:

			///
			///Konstruktor domyślny
			///
			Physical();

			///
			///Konstruktor kopiujący
			///
			///@param & copy - stała referencja na obiekt klasy Physical
			///
			Physical(const Physical & copy);

			///
			///Konstruktor przenoszący
			///
			///@param && other = referencja do r-wartości
			///
			Physical(Physical && other);

			///
			///Destruktor wirtualny
			///
			virtual ~Physical();

			///
			///Przeciążony operator przypisania kopiowania
			///
			///@param & copy - stała referencja na obiekt klasy Physical
			///
			Physical & operator=(const Physical & copy);

			///
			///Przeciążony operator przypisania przenoszenia
			///
			///@param && other -  referencja do r-wartości
			///
			Physical & operator=(Physical && other);

			///
			///Metoda zwraca stałą referencję obiektu - reprezentacja graficzna
			///
			const Displayable & getDisplayable() const;

			///
			///Metoda ustawia referencję na reprezentację graficzną
			///
			///@param & displayable - stała referencja na obiekt klasy Displayable
			///
			void setDisplayable(const Displayable & displayable);
			
			///
			///Metoda ustawia teksturę dla kontekstu graficznego
			///
			///@param & texture - stała referencja na obiekt klasy Texture
			///
			void setTexture(const Texture & texture);

			///
			///Metoda zwraca flagę, czy obiekt posiada reprezentację graficzną
			///
			const bool getUseDisplayable() const;

			///
			///Metoda ustawia flagę na reprezentację graficzną
			///
			///@param use_displayable - flaga, czy obiekt posiada reprezentację graficzną
			///
			void setUseDisplayable(bool use_displayable);

			///
			///Meotoda zwraca informację, czy obiekt na być zniszczony
			///
			const bool getDestruction() const;

			///
			///Meotoda ustawia informację, czy obiekt na być zniszczony
			///
			///@param destruction - flaga destrukcji
			///
			void setDestruction(bool destruction);

			///
			///Metoda zwraca stałą referencję pozycji obiektu
			///
			const sf::Vector2f & getPosition() const;

			///
			///Metoda ustawia pozycję obiektu
			///
			///@param x - współrzędna x obiektu
			///
			///@param y - współrzędna y obiektu
			///
			void setPosition(float x, float y);

			///
			///Metoda ustawia pozycję obiektu
			///
			///@param & vector - stała referenacja na obiekt klasy sf::Vector2f
			///
			void setPosition(const sf::Vector2f & vector);
			
			///
			///Metoda zwraca wartość obrotu
			///
			float getRotation() const;

			///
			///Metoda ustawia wartość obrotu
			///
			///@param rotation_value - wartość obrotu
			///
			void setRotation(float rotation_value);

			///
			///Metoda obraca wartość obrotu
			///
			///@param angle - wartość obrotu
			///
			void rotate(float angle);

			///
			///Metoda zwraca skalę
			///
			const sf::Vector2f & getScale() const;

			///
			///Metoda ustawia skalę
			///
			///@param x - współrzędna x wektora
			///
			///@param y - współrzędna y wektora
			///
			void setScale(float x, float y);

			///
			///Metoda ustawia skalę
			///
			///@param & new_scale_value - stała referencja na obiekt klasy sf::Vector2f
			///
			void setScale(const sf::Vector2f & new_scale_value);

			///
			///Metoda ustawia skalę
			///
			///@param factors - jednolita wartość skalująca w osi x i y
			///
			void setScale(float factors);

			///
			///Metoda ustawia skalę w stosunku do obecnej skali
			///
			///@param factorX - współczynnik w osi x
			///
			///@param factorY - spółczynnik w osi y
			///
			void scale(float factorX, float factorY);

			///
			///Metoda ustawia skalę w stosunku do obecnej skali
			///
			///@param & factor - stała referencja na obiekt klasy sf::Vector2f
			///
			void scale(const sf::Vector2f & factor);

			///
			///Metoda zwraca współrzędne punktu uchwytu obiektu
			///
			const sf::Vector2f & getOrigin() const;

			///
			///Metoda ustawia współrzędne punktu uchwytu obiektu
			///
			///@param x - współrzędna x
			///
			///@param y - współrzędna y
			///
			void setOrigin(float x, float y);

			///
			///Metoda ustawia współrzędne punktu uchwytu obiektu
			///
			///@param & origin - stała referencja na obiekt klasy sf::Vector2f
			///
			void setOrigin(const sf::Vector2f & origin);

			///
			///Metoda zwraca kolor obiektu
			///
			const sf::Color & getColor() const;

			///
			///Metoda ustawia kolor obiektu
			///
			///@param & color - stała referencja na obiekt klasy sf::Color
			///
			void setColor(const sf::Color & color);

			///
			///Metoda ustawia oryginalny kolor obiektu
			///
			void restoreColor();

			///
			///Metoda zwraca granice obiektu w lokalnym w układzie współrzędnych
			///
			sf::FloatRect getLocalBounds() const;

			///
			///Metoda zwraca granice obiektu w globalnym w układzie współrzędnych
			///
			sf::FloatRect getGlobalBounds() const;

			///
			///Metoda przemieszcza obiekt o wartość podaną w parametrach względem aktualnej pozycji
			///
			///@param offsetX - wartość przesunięcia w osi x
			///
			///@param offsetX - wartość przesunięcia w osi x
			///
			void move(float offsetX, float offsetY);

			///
			///Metoda przemieszcza obiekt o wartość wektora przesunięcia
			///
			///@param & offset - stała referencja na obiekt klasy sf::Vector2f - wektora przesunięcia
			///
			void move(const sf::Vector2f & offset);

			///
			///Wirtualna metoda aktualizująca obiekt
			///
			///@param dt - czas
			///
			virtual void update(float dt);

			///
			///Wirtualna metoda rysująca obiekt
			///
			///@param & render - kontekst graficzny
			///
			virtual void draw(sf::RenderWindow & render) const;

		protected:

			Displayable m_displayable; //reprezentacja graficzna
			bool m_use_displayable; //czy jest reprezentacja graficzna
			bool m_destruction; //flaga destrukcji
			sf::Vector2f m_position; //wektor pozycji
			float m_rotation; //wartość obrotu
			sf::Vector2f m_scale; //skala
			sf::Vector2f m_origin; //wektor uchwytu obiektu
			sf::Color m_color; //kolor obiektu
			sf::Color m_stored_color; //kolor oryginalny
			
		private:

		};
	}//namespace physical
}//namespace acodemia

#endif//H_PHYSICAL_ACODEMIA

