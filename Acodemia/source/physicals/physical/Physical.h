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
			///Konstruktor domyœlny
			///
			Physical();

			///
			///Konstruktor kopiuj¹cy
			///
			///@param & copy - sta³a referencja na obiekt klasy Physical
			///
			Physical(const Physical & copy);

			///
			///Konstruktor przenosz¹cy
			///
			///@param && other = referencja do r-wartoœci
			///
			Physical(Physical && other);

			///
			///Destruktor wirtualny
			///
			virtual ~Physical();

			///
			///Przeci¹¿ony operator przypisania kopiowania
			///
			///@param & copy - sta³a referencja na obiekt klasy Physical
			///
			Physical & operator=(const Physical & copy);

			///
			///Przeci¹¿ony operator przypisania przenoszenia
			///
			///@param && other -  referencja do r-wartoœci
			///
			Physical & operator=(Physical && other);

			///
			///Metoda zwraca sta³¹ referencjê obiektu - reprezentacja graficzna
			///
			const Displayable & getDisplayable() const;

			///
			///Metoda ustawia referencjê na reprezentacjê graficzn¹
			///
			///@param & displayable - sta³a referencja na obiekt klasy Displayable
			///
			void setDisplayable(const Displayable & displayable);
			
			///
			///Metoda ustawia teksturê dla kontekstu graficznego
			///
			///@param & texture - sta³a referencja na obiekt klasy Texture
			///
			void setTexture(const Texture & texture);

			///
			///Metoda zwraca flagê, czy obiekt posiada reprezentacjê graficzn¹
			///
			const bool getUseDisplayable() const;

			///
			///Metoda ustawia flagê na reprezentacjê graficzn¹
			///
			///@param use_displayable - flaga, czy obiekt posiada reprezentacjê graficzn¹
			///
			void setUseDisplayable(bool use_displayable);

			///
			///Meotoda zwraca informacjê, czy obiekt na byæ zniszczony
			///
			const bool getDestruction() const;

			///
			///Meotoda ustawia informacjê, czy obiekt na byæ zniszczony
			///
			///@param destruction - flaga destrukcji
			///
			void setDestruction(bool destruction);

			///
			///Metoda zwraca sta³¹ referencjê pozycji obiektu
			///
			const sf::Vector2f & getPosition() const;

			///
			///Metoda ustawia pozycjê obiektu
			///
			///@param x - wspó³rzêdna x obiektu
			///
			///@param y - wspó³rzêdna y obiektu
			///
			void setPosition(float x, float y);

			///
			///Metoda ustawia pozycjê obiektu
			///
			///@param & vector - sta³a referenacja na obiekt klasy sf::Vector2f
			///
			void setPosition(const sf::Vector2f & vector);
			
			///
			///Metoda zwraca wartoœæ obrotu
			///
			float getRotation() const;

			///
			///Metoda ustawia wartoœæ obrotu
			///
			///@param rotation_value - wartoœæ obrotu
			///
			void setRotation(float rotation_value);

			///
			///Metoda obraca wartoœæ obrotu
			///
			///@param angle - wartoœæ obrotu
			///
			void rotate(float angle);

			///
			///Metoda zwraca skalê
			///
			const sf::Vector2f & getScale() const;

			///
			///Metoda ustawia skalê
			///
			///@param x - wspó³rzêdna x wektora
			///
			///@param y - wspó³rzêdna y wektora
			///
			void setScale(float x, float y);

			///
			///Metoda ustawia skalê
			///
			///@param & new_scale_value - sta³a referencja na obiekt klasy sf::Vector2f
			///
			void setScale(const sf::Vector2f & new_scale_value);

			///
			///Metoda ustawia skalê
			///
			///@param factors - jednolita wartoœæ skaluj¹ca w osi x i y
			///
			void setScale(float factors);

			///
			///Metoda ustawia skalê w stosunku do obecnej skali
			///
			///@param factorX - wspó³czynnik w osi x
			///
			///@param factorY - spó³czynnik w osi y
			///
			void scale(float factorX, float factorY);

			///
			///Metoda ustawia skalê w stosunku do obecnej skali
			///
			///@param & factor - sta³a referencja na obiekt klasy sf::Vector2f
			///
			void scale(const sf::Vector2f & factor);

			///
			///Metoda zwraca wspó³rzêdne punktu uchwytu obiektu
			///
			const sf::Vector2f & getOrigin() const;

			///
			///Metoda ustawia wspó³rzêdne punktu uchwytu obiektu
			///
			///@param x - wspó³rzêdna x
			///
			///@param y - wspó³rzêdna y
			///
			void setOrigin(float x, float y);

			///
			///Metoda ustawia wspó³rzêdne punktu uchwytu obiektu
			///
			///@param & origin - sta³a referencja na obiekt klasy sf::Vector2f
			///
			void setOrigin(const sf::Vector2f & origin);

			///
			///Metoda zwraca kolor obiektu
			///
			const sf::Color & getColor() const;

			///
			///Metoda ustawia kolor obiektu
			///
			///@param & color - sta³a referencja na obiekt klasy sf::Color
			///
			void setColor(const sf::Color & color);

			///
			///Metoda ustawia oryginalny kolor obiektu
			///
			void restoreColor();

			///
			///Metoda zwraca granice obiektu w lokalnym w uk³adzie wspó³rzêdnych
			///
			sf::FloatRect getLocalBounds() const;

			///
			///Metoda zwraca granice obiektu w globalnym w uk³adzie wspó³rzêdnych
			///
			sf::FloatRect getGlobalBounds() const;

			///
			///Metoda przemieszcza obiekt o wartoœæ podan¹ w parametrach wzglêdem aktualnej pozycji
			///
			///@param offsetX - wartoœæ przesuniêcia w osi x
			///
			///@param offsetX - wartoœæ przesuniêcia w osi x
			///
			void move(float offsetX, float offsetY);

			///
			///Metoda przemieszcza obiekt o wartoœæ wektora przesuniêcia
			///
			///@param & offset - sta³a referencja na obiekt klasy sf::Vector2f - wektora przesuniêcia
			///
			void move(const sf::Vector2f & offset);

			///
			///Wirtualna metoda aktualizuj¹ca obiekt
			///
			///@param dt - czas
			///
			virtual void update(float dt);

			///
			///Wirtualna metoda rysuj¹ca obiekt
			///
			///@param & render - kontekst graficzny
			///
			virtual void draw(sf::RenderWindow & render) const;

		protected:

			Displayable m_displayable; //reprezentacja graficzna
			bool m_use_displayable; //czy jest reprezentacja graficzna
			bool m_destruction; //flaga destrukcji
			sf::Vector2f m_position; //wektor pozycji
			float m_rotation; //wartoœæ obrotu
			sf::Vector2f m_scale; //skala
			sf::Vector2f m_origin; //wektor uchwytu obiektu
			sf::Color m_color; //kolor obiektu
			sf::Color m_stored_color; //kolor oryginalny
			
		private:

		};
	}//namespace physical
}//namespace acodemia

#endif//H_PHYSICAL_ACODEMIA

