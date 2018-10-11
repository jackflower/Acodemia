//
//acodemia.pl
//

#ifndef H_DISPLAYABLE_ACODEMIA
#define H_DISPLAYABLE_ACODEMIA

#include <SFML/Graphics.hpp>
#include "Sprite.h"

// r e f a k t o r y z a j c a   k o d u

namespace acodemia
{
	namespace rendering
	{
		///
		///Klasa reprezentuje obiekt, który może być renderowany
		///
		class Displayable
		{

		
		public:

			///
			///Konstruktor domyślny
			///
			Displayable();

			///
			///Konstruktor kopiujący
			///
			///@param & copy - stała referencja na obiekt klasy Displayable
			///
			Displayable(const Displayable & copy);

			///
			///Konstruktor przenoszący
			///
			///@param && other = referencja do r-wartości
			///
			Displayable(Displayable && other);

			///
			///Destruktor wirtualny
			///
			~Displayable();

			///
			///Przeciążony operator przypisania kopiowania
			///
			///@param & other - stała referencja na obiekt klasy Displayable
			///
			Displayable & operator=(const Displayable & other);

			///
			///Przeciążony operator przypisania przenoszenia
			///
			///@param && other -  referencja do r-wartości
			///
			Displayable & operator=(Displayable && other);

			///Metoda zwraca referencję na obiekt sf::Sprite
			///
			//sf::Sprite & getSprite();

			///
			///Metoda ustawia referencję na obiekt sf::Sprite
			///
			///@param & sprite - referencja na obiekt klasy sf::Sprite
			///
			//void setSprite(sf::Sprite & sprite);

			///
			///Metoda zwraca stałą referencję pozycji obiektu
			///
			const sf::Vector2f& getPosition() const;

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
			const sf::Vector2f& getScale() const;
		
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
			///@param &new_scale_value - referencja na obiekt klasy sf::Vector2f
			///
			void setScale(const sf::Vector2f& new_scale_value);

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
			///@param &factor - stała referencja na obiekt klasy sf::Vector2f
			///
			void scale(const sf::Vector2f& factor);

			///
			///Metoda zwraca współrzędne punktu uchwytu obiektu
			///
			const sf::Vector2f& getOrigin() const;

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
			///@param &origin - stała referencja na obiekt klasy sf::Vector2f
			///
			void setOrigin(const sf::Vector2f& origin);

			///
			///Metoda zwraca obszar prostokątny zajmowany przez teksturę
			///
			const sf::IntRect& getTextureRect() const;

			///
			///Metoda ustawia obszar prostokątny zajmowany przez teksturę
			///
			///@param rectLeft - lewy róg prostokątnego obszaru
			///
			///@param rectTop - górny róg prostokątnego obszaru
			///
			///@param rectWidth - szerokość prostokątnego obszaru
			///
			///@param rectHeight - wysokość prostokątnego obszaru
			///
			void setTextureRect(int rectLeft, int rectTop, int rectWidth, int rectHeight);

			///
			///Metoda ustawia obszar prostokątny zajmowany przez teksturę
			///
			///@param rectangle - stała referencja na obiekt klasy sf::IntRect
			///
			void setTextureRect (const sf::IntRect& rectangle);

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
			///@param &offset - stała referencja na obiekt klasy sf::Vector2f - wektora przesunięcia
			///
			void move(const sf::Vector2f& offset);

			///
			///Metoda zwraca kolor obiektu
			///
			const sf::Color& getColor() const;

			///
			///Metoda ustawia kolor obiektu
			///
			///@param color - kolor obiektu
			///
			void setColor(const sf::Color& color);

			///
			///Metoda ustawia teksturę obiektu
			///
			///@param &texture_name - stała referencja na obiekt std::string - nazwa tekstury
			///
			//void setTexture(const std::string& texture_name, bool smoothing = true);

			///
			///Metoda ustawia teksturę obiektu
			///
			///@param *p_texture - wskaźnik na obiekt klasy CTexture
			///
			//void setTexture(CTexture *p_texture, bool smoothing = true);

			///
			///Metoda generuje obraz tekstury
			///
			///@param width - szerokość tekstury (obiektu) w pikselach
			///
			///@param height - wysokość tekstury (obiektu) w pikselach
			///
			///@param color - & color - stała referencja na obiekt klasy sf::Color
			///
			void SetTexture(unsigned width, unsigned height, const sf::Color & color = sf::Color(0, 0, 0));

			///
			///Metoda generuje obraz tekstury
			///
			///@param width - szerokość tekstury (obiektu) w pikselach
			///
			///@param height - wysokość tekstury (obiektu) w pikselach
			///
			///@param r - składowa red koloru
			///
			///@param g - składowa green koloru
			///
			///@param b - składowa blue koloru
			///
			///@param a - składowa alpha koloru
			///
			void SetTexture(unsigned width, unsigned height, unsigned r, unsigned g, unsigned b, unsigned a = 255);

			///
			///Metoda ustawia animację
			///
			///@param &animation_name - stała referencja na obiekt std::string - nazwa animacji
			///
			//void SetAnimation( const std::string& animation_name );

			///
			///Metoda ustawia animację
			///
			///@param *p_animation - wskaźnik na obiekt klasy CAnimation
			///
			//void SetAnimation(CAnimation *p_animation);

			///
			///Metoda zwraca wskaźnik na obiekt klasy CAnimationState
			///
			//CAnimationState* GetAnimationState();


			///
			///Metoda ustawia teksturę dla sprite
			///
			///@param & texture - stała referencja na obiekt klasy sf::Texture
			///
			void setTexture(const sf::Texture & texture);


			//dodać smooth...y
			//void setTexture(const Texture& texture, bool resetRect = false);

			///
			///Wirtualna metoda renderująca obiekt
			///
			///@render & render - referencja na kontekst graficzny
			///
			virtual void draw(sf::RenderWindow & render);
		
		private:
		
			//sf::Sprite *p_sprite;//wskaźnik na kontekst graficzny
			Sprite *p_sprite;
			
		};
	} //namespace rendering
}//namespace acodemia
#endif //H_DISPLAYABLE_ACODEMIA
