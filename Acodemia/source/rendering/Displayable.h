//
//acodemia.pl
//

#ifndef H_DISPLAYABLE_ACODEMIA
#define H_DISPLAYABLE_ACODEMIA

#include <SFML/Graphics.hpp>

namespace acodemia
{
	namespace rendering
	{
		///
		///Klasa reprezentuje obiekt, który mo¿e byæ renderowany
		///
		class Displayable
		{

		public:

			///
			///Konstruktor domyœlny
			///
			Displayable();

			///
			///Konstruktor kopiuj¹cy
			///
			///@param & copy - sta³a referencja na obiekt klasy Displayable
			///
			Displayable(const Displayable & copy);

			///
			///Konstruktor przenosz¹cy
			///
			///@param && other = referencja do r-wartoœci
			///
			Displayable(Displayable && other);

			///
			///Destruktor wirtualny
			///
			~Displayable();

			///
			///Przeci¹¿ony operator przypisania kopiowania
			///
			///@param & other - sta³a referencja na obiekt klasy Displayable
			///
			Displayable & operator=(const Displayable & other);

			///
			///Przeci¹¿ony operator przypisania przenoszenia
			///
			///@param && other -  referencja do r-wartoœci
			///
			Displayable & operator=(Displayable && other);

			///Metoda zwraca referencjê na obiekt sf::Sprite
			///
			//sf::Sprite & getSprite();

			///
			///Metoda ustawia referencjê na obiekt sf::Sprite
			///
			///@param & sprite - referencja na obiekt klasy sf::Sprite
			///
			//void setSprite(sf::Sprite & sprite);

			///
			///Metoda zwraca pozycjê obiektu
			///
			const sf::Vector2f& getPosition() const;

			///
			///Metoda ustawia pozycjê obiektu
			///
			///@param x - wspó³rzêdna x obiektu
			///
			///@param y - wspó³rzêdna y obiektu
			///
			void setPosition(float x, float y);

			///
			//Metoda ustawia pozycjê obiektu
			///
			///@param &vector - referenacja - obiekt klasy sf::Vector2f
			///
			void setPosition(const sf::Vector2f& vector);

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
			const sf::Vector2f& getScale() const;
		
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
			///@param &new_scale_value - referencja na obiekt klasy sf::Vector2f
			///
			void setScale(const sf::Vector2f& new_scale_value);

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
			///@param &factor - sta³a referencja na obiekt klasy sf::Vector2f
			///
			void scale(const sf::Vector2f& factor);

			///
			///Metoda zwraca wspó³rzêdne punktu uchwytu obiektu
			///
			const sf::Vector2f& getOrigin() const;

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
			///@param &origin - sta³a referencja na obiekt klasy sf::Vector2f
			///
			void setOrigin(const sf::Vector2f& origin);

			///
			///Metoda zwraca obszar prostok¹tny zajmowany przez teksturê
			///
			const sf::IntRect& getTextureRect() const;

			///
			///Metoda ustawia obszar prostok¹tny zajmowany przez teksturê
			///
			///@param rectLeft - lewy róg prostok¹tnego obszaru
			///
			///@param rectTop - górny róg prostok¹tnego obszaru
			///
			///@param rectWidth - szerokoœæ prostok¹tnego obszaru
			///
			///@param rectHeight - wysokoœæ prostok¹tnego obszaru
			///
			void setTextureRect(int rectLeft, int rectTop, int rectWidth, int rectHeight);

			///
			///Metoda ustawia obszar prostok¹tny zajmowany przez teksturê
			///
			///@param rectangle - sta³a referencja na obiekt klasy sf::IntRect
			///
			void setTextureRect (const sf::IntRect& rectangle);

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
			///@param &offset - sta³a referencja na obiekt klasy sf::Vector2f - wektora przesuniêcia
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
			///Metoda ustawia teksturê obiektu
			///
			///@param &texture_name - sta³a referencja na obiekt std::string - nazwa tekstury
			///
			//void setTexture(const std::string& texture_name, bool smoothing = true);

			///
			///Metoda ustawia teksturê obiektu
			///
			///@param *p_texture - wskaŸnik na obiekt klasy CTexture
			///
			//void setTexture(CTexture *p_texture, bool smoothing = true);

			///
			///Metoda generuje obraz tekstury
			///
			///@param width - szerokoœæ tekstury (obiektu) w pikselach
			///
			///@param height - wysokoœæ tekstury (obiektu) w pikselach
			///
			///@param color - & color - sta³a referencja na obiekt klasy sf::Color
			///
			void SetTexture(unsigned width, unsigned height, const sf::Color & color = sf::Color(0, 0, 0));

			///
			///Metoda generuje obraz tekstury
			///
			///@param width - szerokoœæ tekstury (obiektu) w pikselach
			///
			///@param height - wysokoœæ tekstury (obiektu) w pikselach
			///
			///@param r - sk³adowa red koloru
			///
			///@param g - sk³adowa green koloru
			///
			///@param b - sk³adowa blue koloru
			///
			///@param a - sk³adowa alpha koloru
			///
			void SetTexture(unsigned width, unsigned height, unsigned r, unsigned g, unsigned b, unsigned a = 255);

			///
			///Metoda ustawia animacjê
			///
			///@param &animation_name - sta³a referencja na obiekt std::string - nazwa animacji
			///
			//void SetAnimation( const std::string& animation_name );

			///
			///Metoda ustawia animacjê
			///
			///@param *p_animation - wskaŸnik na obiekt klasy CAnimation
			///
			//void SetAnimation(CAnimation *p_animation);

			///
			///Metoda zwraca wskaŸnik na obiekt klasy CAnimationState
			///
			//CAnimationState* GetAnimationState();


			///
			///Metoda ustawia teksturê dla sprite
			///
			///@param & texture - sta³a referencja na obiekt klasy sf::Texture
			///
			void setTexture(const sf::Texture & texture);


			//dodaæ smooth...y
			//void setTexture(const Texture& texture, bool resetRect = false);

			///
			///Wirtualna metoda renderuj¹ca obiekt
			///
			///@render & render - referencja na kontekst graficzny
			///
			virtual void draw(sf::RenderWindow & render);
		
		private:
		
			sf::Sprite *p_sprite;//wskaŸnik na kontekst graficzny
		};
	} //namespace rendering
}//namespace acodemia
#endif //H_DISPLAYABLE_ACODEMIA
