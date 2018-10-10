//
//acodemia.pl
//

#include "Displayable.h"
#include <iostream>

namespace acodemia
{
	namespace rendering
	{
		//Konstruktor domyœlny
		Displayable::Displayable()
		:
			p_sprite(new sf::Sprite())
		{
			std::cout << "konstruktor domyslny" << std::endl;
		}

		//Konstruktor kopiuj¹cy
		Displayable::Displayable(const Displayable & copy)
		:
			p_sprite(new sf::Sprite(*copy.p_sprite))
		{
			std::cout << "konstruktor kopiujacy" << std::endl;
		}

		//Konstruktor przenosz¹cy
		Displayable::Displayable(Displayable && other)
		:
			p_sprite(nullptr)
		{
			//kopiujemy pod wskaŸnik dane obiektu Ÿród³owego
			p_sprite = other.p_sprite;
			//zwalniamy wskaŸnik na dane obiektu Ÿród³owego tak, aby
			//destruktor nie zwalnia³ pamiêci wielokrotnie
			other.p_sprite = nullptr;
			std::cout << "konstruktor przenoszacy" << std::endl;
		}

		//Destruktor wirtualny
		Displayable::~Displayable() 
		{
			if(p_sprite != nullptr)
				delete p_sprite;
			p_sprite = nullptr;
		}

		//Przeci¹¿ony operator przypisania kopiowania
		Displayable & Displayable::operator=(const Displayable & other)
		{
			std::cout << "operator przypisania kopiujacy" << std::endl;
			if (this != & other)
			{
				//zwalaniamy dane pod wskaŸnikiem
				delete p_sprite;
				//tworzymy nowy obiekt na podstawie obiektu Ÿród³owego
				p_sprite = new sf::Sprite(*other.p_sprite);
			}
			return *this;
		}

		//Przeci¹¿ony operator przypisania przenoszenia
		Displayable & Displayable::operator=(Displayable && other)
		{
			std::cout << "operator przypisania przenoszenia" << std::endl;
			if (this != & other)
			{
				//zwalaniamy dane pod wskaŸnikiem
				delete p_sprite;
				//przenosimy pod wskaŸnik dane z obiektu Ÿród³owego
				p_sprite = other.p_sprite;
				//zwalniamy wskaŸnik na dane obiektu Ÿród³owego tak, aby
				//destruktor nie zwalnia³ pamiêci wielokrotnie
				other.p_sprite = nullptr;
			}
				return *this;
		}



		////Metoda zwraca wskaŸnik na obiekt sf::Sprite
		//sf::Sprite & Displayable::getSprite()
		//{
		//	return m_sprite;
		//}

		////Metoda ustawia referencjê na obiekt sf::Sprite
		//void Displayable::setSprite(sf::Sprite & sprite)
		//{
		//	m_sprite = sprite;
		//}

		//Metoda zwraca sta³¹ referencjê pozycji obiektu
		const sf::Vector2f & Displayable::getPosition() const
		{
			return p_sprite->getPosition();
		}

		//Metoda ustawia pozycjê obiektu
		void Displayable::setPosition(float x, float y)
		{
			if(p_sprite)
				p_sprite->setPosition(x, y);
		}

		//Metoda ustawia pozycjê obiektu
		void Displayable::setPosition(const sf::Vector2f & vector)
		{
			setPosition(vector.x, vector.y);
		}

		////Metoda zwraca wartoœæ obrotu
		//float CDisplayable::getRotation() const
		//{ 
		//	return m_sprite->getRotation();
		//}

		////Metoda ustawia wartoœæ obrotu
		//void CDisplayable::setRotation(float rotation_value)
		//{
		//	m_sprite->setRotation(rotation_value);
		//}

		////Metoda obraca wartoœæ obrotu
		//void CDisplayable::rotate(float angle)
		//{
		//	m_sprite->rotate(angle);
		//}

		////Metoda zwraca skalê
		//const sf::Vector2f& CDisplayable::getScale() const
		//{
		//	return m_sprite->getScale();
		//}

		////Metoda ustawia skalê
		//void CDisplayable::setScale(float x, float y)
		//{
		//	m_sprite->setScale(x, y);
		//}

		////Metoda ustawia skalê
		//void CDisplayable::setScale(const sf::Vector2f& new_scale_value)
		//{
		//	m_sprite->setScale(new_scale_value);
		//}

		////Metoda ustawia skalê
		//void CDisplayable::setScale(float factors)
		//{
		//	setScale(factors, factors);
		//}

		////Metoda ustawia skalê w stosunku do obecnej skali
		//void CDisplayable::scale(float factorX, float factorY)
		//{
		//	m_sprite->scale(factorX, factorY);
		//}

		////Metoda ustawia skalê w stosunku do obecnej skali
		//void CDisplayable::scale(const sf::Vector2f& factor)
		//{
		//	m_sprite->scale(factor);
		//}

		////Metoda zwraca wspó³rzêdne punktu uchwytu obiektu
		//const sf::Vector2f& CDisplayable::getOrigin() const
		//{
		//	return m_sprite->getOrigin();
		//}

		////Metoda ustawia wspó³rzêdne punktu uchwytu obiektu
		//void CDisplayable::setOrigin(float x, float y)
		//{
		//	m_sprite->setOrigin(x, y);
		//}

		////Metoda ustawia wspó³rzêdne punktu uchwytu obiektu
		//void CDisplayable::setOrigin(const sf::Vector2f& origin)
		//{
		//	m_sprite->setOrigin(origin);
		//}

		////Metoda zwraca obszar prostok¹tny zajmowany przez teksturê
		//const sf::IntRect& CDisplayable::getTextureRect() const
		//{
		//	return m_sprite->getTextureRect();
		//}

		////Metoda ustawia obszar prostok¹tny zajmowany przez teksturê
		//void CDisplayable::setTextureRect(int rectLeft, int rectTop, int rectWidth, int rectHeight)
		//{
		//	setTextureRect(sf::IntRect(rectLeft, rectTop, rectWidth, rectHeight));
		//}

		////Metoda ustawia obszar prostok¹tny zajmowany przez teksturê
		//void CDisplayable::setTextureRect (const sf::IntRect& rectangle)
		//{
		//	m_sprite->setTextureRect(rectangle);
		//}

		////Metoda zwraca granice obiektu w lokalnym w uk³adzie wspó³rzêdnych
		//sf::FloatRect CDisplayable::getLocalBounds() const
		//{
		//	return m_sprite->getLocalBounds();
		//}

		////Metoda zwraca granice obiektu w globalnym w uk³adzie wspó³rzêdnych
		//sf::FloatRect CDisplayable::getGlobalBounds() const
		//{
		//	return m_sprite->getGlobalBounds();
		//}

		////Metoda przemieszcza obiekt o wartoœæ podan¹ w parametrach wzglêdem aktualnej pozycji
		//void CDisplayable::move(float offsetX, float offsetY)
		//{
		//	m_sprite->move(offsetX, offsetY);
		//}

		////Metoda przemieszcza obiekt o wartoœæ wektora przesuniêcia
		//void CDisplayable::move(const sf::Vector2f& offset)
		//{
		//	m_sprite->move(offset);
		//}

		////Metoda zwraca kolor obiektu
		//const sf::Color& CDisplayable::getColor() const
		//{
		//	return m_sprite->getColor();
		//}

		////Metoda ustawia kolor obiektu
		//void CDisplayable::setColor(const sf::Color& color)
		//{
		//	m_sprite->setColor(color);
		//}

		////Metoda ustawia teksturê obiektu
		//void CDisplayable::setTexture(const std::string& texture_name, bool smoothing)
		//{
		//	m_smooth = smoothing;
		//	CTexture* p_texture = gResourceManager.GetTexture(texture_name);
		//	if (!p_texture)
		//	{
		//		fprintf(stderr, "warning: CDisplayable::setTexture: unable to obtain image `%s'\n", texture_name.c_str());
		//		setTexture(NULL);
		//		return;
		//	}
		//	setTexture(p_texture, m_smooth);
		//}

		////Metoda ustawia teksturê obiektu
		//void CDisplayable::setTexture(CTexture *p_texture, bool smoothing)
		//{
		//	if (m_animation_state)					//jeœli wskaŸnik na CAnimationState jest zainicjowany
		//	{
		//		gAnimationManager.DestroyAnimationState(m_animation_state);//usuwamy animacjê
		//		m_animation_state = NULL;			//ustawiamy wskaŸnik na NULL
		//	}

		//	if (p_texture != NULL)					//jeœli mamy wskaŸnik poprawnie wskazuj¹cy na teksturê
		//	{
		//		p_texture->setSmooth(m_smooth);
		//		m_sprite->setTexture(*p_texture);	//ustawiamy teskturê
		//		//po za³adowaniu tekstury wyznaczamy punkt uchwytu sprite'a na jego œrodek geometryczny
		//		m_sprite->setOrigin(m_sprite->getLocalBounds().width * 0.5f, m_sprite->getLocalBounds().height * 0.5f);
		//	}
		//}

		////Metoda generuje obraz tekstury
		//void CDisplayable::SetTexture(unsigned width, unsigned height, const sf::Color & color)
		//{
		//	if (m_animation_state)					//jeœli wskaŸnik na CAnimationState jest zainicjowany
		//	{
		//		gAnimationManager.DestroyAnimationState(m_animation_state);//usuwamy animacjê
		//		m_animation_state = NULL;			//ustawiamy wskaŸnik na NULL
		//	}

		//	p_synthetic_texture->create(width, height);
		//	p_synthetic_image->create(width, height, color);
		//	p_synthetic_texture->update(*p_synthetic_image);
		//	m_sprite->setTexture(*p_synthetic_texture);
		//}

		////Metoda generuje obraz tekstury
		//void CDisplayable::SetTexture(unsigned width, unsigned height, unsigned r, unsigned g, unsigned b, unsigned a)
		//{
		//	if (m_animation_state)					//jeœli wskaŸnik na CAnimationState jest zainicjowany
		//	{
		//		gAnimationManager.DestroyAnimationState(m_animation_state);//usuwamy animacjê
		//		m_animation_state = NULL;			//ustawiamy wskaŸnik na NULL
		//	}
		//	
		//	p_synthetic_texture->create(width, height);
		//	p_synthetic_image->create(width, height, sf::Color(r, g, b, a));
		//	p_synthetic_texture->update(*p_synthetic_image);
		//	m_sprite->setTexture(*p_synthetic_texture);
		//}

		////Metoda ustawia animacjê
		//void CDisplayable::SetAnimation(const std::string& animation_name)
		//{
		//	//warunki, gdy zamiana animacji siê nie powiedzie:
		//	//nie jest ³adowana animacja, jeœli próbujemy
		//	//zamieniæ j¹ na tak¹ sam¹ (istniej¹c¹ pod tak¹ sam¹ nazw¹)
		//	if (m_animation_name == animation_name) return;

		//	m_animation_name = animation_name;

		//	//usuwamy animacjê, jeœli wczeœniej jakaœ by³a
		//	if (m_animation_state)
		//		gAnimationManager.DestroyAnimationState(m_animation_state);

		//	//tworzymy now¹ animacjê
		//	m_animation_state = gAnimationManager.CreateAnimationState(animation_name);

		//	if (!m_animation_state)
		//	{
		//		fprintf(stderr, "warning: CDisplayable::SetAnimation: unable to obtain animation `%s'\n", animation_name.c_str());
		//	} 
		//}

		////Metoda ustawia animacjê
		//void CDisplayable::SetAnimation(CAnimation *p_animation)
		//{
		//	//warunki, gdy zamiana animacji siê nie powiedzie:
		//	//jeœli wskaŸnik jest NULL - return
		//	//jeœli wskaŸnik jest zainicjowany, a próbujemy go zainicjowaæ takim samym wskaŸnikiem - return

		//	if (p_animation == NULL)
		//		return;
		//	if ((m_animation_state != NULL) && (m_animation_state->GetAnimation() == p_animation))
		//		return;

		//	m_animation_name = p_animation->GetAnimationName();

		//	if (m_animation_state)
		//		gAnimationManager.DestroyAnimationState(m_animation_state);
		//	m_animation_state = gAnimationManager.CreateAnimationState(p_animation);

		//	if (!m_animation_state)
		//	{
		//		fprintf(stderr, "warning: CDrawable::SetAnimation: unable to obtain animation '%s'\n", m_animation_name.c_str());
		//	} 
		//}

		////Metoda zwraca wskaŸnik na obiekt klasy CAnimationState
		//CAnimationState* CDisplayable::GetAnimationState()
		//{
		//	return m_animation_state;
		//}
		//
		/////Metoda zwraca tryb wyg³adzania tekstury
		//const bool CDisplayable::getSmoothing() const
		//{
		//	return m_smooth;
		//}

		////Metoda ustawia tryb wyg³adzania tekstury
		//void CDisplayable::setSmoothing(bool smooth)
		//{
		//	m_smooth = smooth;
		//}

		//Metoda ustawia teksturê dla sprite
		void Displayable::setTexture(const sf::Texture & texture)
		{
			if(p_sprite)
				p_sprite->setTexture(texture);
		}

		//Wirtualna metoda renderuj¹ca obiekt
		void Displayable::draw(sf::RenderWindow & render)
		{
			//jeœli flaga nie pozwala - nie rysujemy obiektu - return
			//if(m_can_draw == false)	return;

			//jeœli wskaŸnik na obiekt CAnimationState pokazuje na animacjê
			//if (m_animation_state)
			//{
			//	//tworzymy klatkê animacji i pobieramy bie¿¹c¹ klatkê z CAnimationState
			//	CAnimationFrame frame = m_animation_state->GetCurrentFrame();

			//	//tworzymy wskaŸnik na obiekt klasy CTexture (tekstura)
			//	//inicjujemy ten wskaŸnik obrazem pobranym na podstawie nazwy
			//	//tekstury, na której znajduje sie klatka animacji.
			//	//CResourceManager zwraca na podstawie tej nazwy wskaŸnik na teksturê.
			//	CTexture* p_texture = gResourceManager.GetTexture(frame.GetTextureName());
			//	//ustawiamy flagê wyg³adzania tekstury
			//	p_texture->setSmooth(m_smooth);

			//	//jeœli wskaŸnik nie jest zainicjowany - komunikat o b³êdzie
			//	if (!p_texture)
			//	{
			//		fprintf(stderr, "warning: CDisplayable::Draw: animation: unable to obtain image `%s'\n", frame.GetTextureName().c_str());
			//	}
			//	else
			//	{
			//		//w przeciwnym wypadku pobieramy obszar klatki animacji
			//		sf::IntRect rect = frame.GetImageRectangle();

			//		//sprawdzamy, wielkoœæ tekstury (czy ten kod jest potrzebny?)
			//		//niech na razie sobie tutaj pole¿y, najwy¿ej mo¿na to zakomentowaæ...
			//		//if (rect.left == 0 && rect.top == 0 && rect.width == 0 && rect.height == 0)
			//		//{
			//		//	rect.width = p_texture->getSize().x;	//wyznaczamy szerokoœæ
			//		//	rect.height = p_texture->getSize().y;	//wyznaczamy wysokoœæ
			//		//}
			//		p_texture->setSmooth(m_smooth);				//filtr
			//		m_sprite->setTexture(*p_texture);			//pod³¹czamy wskaŸnik na teksturê pod sprite'a
			//		m_sprite->setTextureRect(rect);				//pod³¹czamy wyliczony obszar tekstury pod sprite'a

			//		//wyznaczamy punkt uchwytu sprite'a na jego œrodek geometryczny
			//		m_sprite->setOrigin(m_sprite->getLocalBounds().width * 0.5f, m_sprite->getLocalBounds().height * 0.5f);
			//	}
			//}
			
			//if(m_can_draw == false) return;	//na wszelki wypadek, gdyby w ramce czasu flaga ustawi³a siê na false
			if (p_sprite)					//na wszelki wypadek, gdyby wskaŸnik straci³ adres...
			{
				render.draw(*p_sprite);	//rysujemy obiekt
			}
		}
	}//namespace rendering
}//namespace acodemia
