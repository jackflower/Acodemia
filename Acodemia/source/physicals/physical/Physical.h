//
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
			///Konstruktor domy�lny
			///
			Physical();

			///
			///Konstruktor kopiuj�cy
			///
			///@param & copy - sta�a referencja na obiekt klasy Physical
			///
			Physical(const Physical & copy);

			///
			///Konstruktor przenosz�cy
			///
			///@param && other = referencja do r-warto�ci
			///
			Physical(Physical && other);

			///
			///Destruktor wirtualny
			///
			virtual ~Physical();

			///
			///Przeci��ony operator przypisania kopiowania
			///
			///@param & copy - sta�a referencja na obiekt klasy Physical
			///
			Physical & operator=(const Physical & copy);

			///
			///Przeci��ony operator przypisania przenoszenia
			///
			///@param && other -  referencja do r-warto�ci
			///
			Physical & operator=(Physical && other);

			///
			///Metoda zwraca sta�� referencj� obiektu - reprezentacja graficzna
			///
			const Displayable & getDisplayable() const;

			///
			///Metoda ustawia referencj� na reprezentacj� graficzn�
			///
			///@param & displayable - sta�a referencja na obiekt klasy Displayable
			///
			void setDisplayable(const Displayable & displayable);
			
			///
			///Metoda ustawia tekstur� dla kontekstu graficznego
			///
			///@param & texture - sta�a referencja na obiekt klasy Texture
			///
			void setTexture(const Texture & texture);

			///
			///Metoda zwraca flag�, czy obiekt posiada reprezentacj� graficzn�
			///
			const bool getUseDisplayable() const;

			///
			///Metoda ustawia flag� na reprezentacj� graficzn�
			///
			///@param use_displayable - flaga, czy obiekt posiada reprezentacj� graficzn�
			///
			void setUseDisplayable(bool use_displayable);

			///
			///Meotoda zwraca informacj�, czy obiekt na by� zniszczony
			///
			const bool getDestruction() const;

			///
			///Meotoda ustawia informacj�, czy obiekt na by� zniszczony
			///
			///@param destruction - flaga destrukcji
			///
			void setDestruction(bool destruction);

			///
			///Metoda zwraca sta�� referencj� pozycji obiektu
			///
			const sf::Vector2f & getPosition() const;

			///
			///Metoda ustawia pozycj� obiektu
			///
			///@param x - wsp�rz�dna x obiektu
			///
			///@param y - wsp�rz�dna y obiektu
			///
			void setPosition(float x, float y);

			///
			///Metoda ustawia pozycj� obiektu
			///
			///@param & vector - sta�a referenacja na obiekt klasy sf::Vector2f
			///
			void setPosition(const sf::Vector2f & vector);
			
			///
			///Metoda zwraca warto�� obrotu
			///
			float getRotation() const;

			///
			///Metoda ustawia warto�� obrotu
			///
			///@param rotation_value - warto�� obrotu
			///
			void setRotation(float rotation_value);

			///
			///Metoda obraca warto�� obrotu
			///
			///@param angle - warto�� obrotu
			///
			void rotate(float angle);

			///
			///Metoda zwraca skal�
			///
			const sf::Vector2f & getScale() const;

			///
			///Metoda ustawia skal�
			///
			///@param x - wsp�rz�dna x wektora
			///
			///@param y - wsp�rz�dna y wektora
			///
			void setScale(float x, float y);

			///
			///Metoda ustawia skal�
			///
			///@param & new_scale_value - sta�a referencja na obiekt klasy sf::Vector2f
			///
			void setScale(const sf::Vector2f & new_scale_value);

			///
			///Metoda ustawia skal�
			///
			///@param factors - jednolita warto�� skaluj�ca w osi x i y
			///
			void setScale(float factors);

			///
			///Metoda ustawia skal� w stosunku do obecnej skali
			///
			///@param factorX - wsp�czynnik w osi x
			///
			///@param factorY - sp�czynnik w osi y
			///
			void scale(float factorX, float factorY);

			///
			///Metoda ustawia skal� w stosunku do obecnej skali
			///
			///@param & factor - sta�a referencja na obiekt klasy sf::Vector2f
			///
			void scale(const sf::Vector2f & factor);

			///
			///Metoda zwraca wsp�rz�dne punktu uchwytu obiektu
			///
			const sf::Vector2f & getOrigin() const;

			///
			///Metoda ustawia wsp�rz�dne punktu uchwytu obiektu
			///
			///@param x - wsp�rz�dna x
			///
			///@param y - wsp�rz�dna y
			///
			void setOrigin(float x, float y);

			///
			///Metoda ustawia wsp�rz�dne punktu uchwytu obiektu
			///
			///@param & origin - sta�a referencja na obiekt klasy sf::Vector2f
			///
			void setOrigin(const sf::Vector2f & origin);

			///
			///Metoda zwraca kolor obiektu
			///
			const sf::Color & getColor() const;

			///
			///Metoda ustawia kolor obiektu
			///
			///@param & color - sta�a referencja na obiekt klasy sf::Color
			///
			void setColor(const sf::Color & color);

			///
			///Metoda ustawia oryginalny kolor obiektu
			///
			void restoreColor();

			///
			///Metoda zwraca granice obiektu w lokalnym w uk�adzie wsp�rz�dnych
			///
			sf::FloatRect getLocalBounds() const;

			///
			///Metoda zwraca granice obiektu w globalnym w uk�adzie wsp�rz�dnych
			///
			sf::FloatRect getGlobalBounds() const;

			///
			///Metoda przemieszcza obiekt o warto�� podan� w parametrach wzgl�dem aktualnej pozycji
			///
			///@param offsetX - warto�� przesuni�cia w osi x
			///
			///@param offsetX - warto�� przesuni�cia w osi x
			///
			void move(float offsetX, float offsetY);

			///
			///Metoda przemieszcza obiekt o warto�� wektora przesuni�cia
			///
			///@param & offset - sta�a referencja na obiekt klasy sf::Vector2f - wektora przesuni�cia
			///
			void move(const sf::Vector2f & offset);

			///
			///Wirtualna metoda aktualizuj�ca obiekt
			///
			///@param dt - czas
			///
			virtual void update(float dt);

			///
			///Wirtualna metoda rysuj�ca obiekt
			///
			///@param & render - kontekst graficzny
			///
			virtual void draw(sf::RenderWindow & render) const;

		protected:

			Displayable m_displayable; //reprezentacja graficzna
			bool m_use_displayable; //czy jest reprezentacja graficzna
			bool m_destruction; //flaga destrukcji
			sf::Vector2f m_position; //wektor pozycji
			float m_rotation; //warto�� obrotu
			sf::Vector2f m_scale; //skala
			sf::Vector2f m_origin; //wektor uchwytu obiektu
			sf::Color m_color; //kolor obiektu
			sf::Color m_stored_color; //kolor oryginalny
			
		private:

		};
	}//namespace physical
}//namespace acodemia

#endif//H_PHYSICAL_ACODEMIA

