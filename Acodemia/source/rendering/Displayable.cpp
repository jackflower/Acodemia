//
//acodemia.pl
//

#include "Displayable.h"
#include <iostream>

namespace acodemia
{
	namespace rendering
	{
		//Konstruktor domyślny
		Displayable::Displayable()
		:
			//p_sprite(new sf::Sprite())
			p_sprite(new Sprite())
		{
			std::cout << "konstruktor domyslny" << std::endl;
		}

		//Konstruktor kopiujący
		Displayable::Displayable(const Displayable & copy)
		:
			//p_sprite(new sf::Sprite(*copy.p_sprite))
			p_sprite(new Sprite(*copy.p_sprite))
		{
			std::cout << "konstruktor kopiujacy" << std::endl;
		}

		//Konstruktor przenoszący
		Displayable::Displayable(Displayable && other)
		:
			p_sprite(nullptr)
		{
			//kopiujemy pod wskaźnik dane obiektu źródłowego
			p_sprite = other.p_sprite;
			//zwalniamy wskaźnik na dane obiektu źródłowego tak, aby
			//destruktor nie zwalniał pamięci wielokrotnie
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

		//Przeciążony operator przypisania kopiowania
		Displayable & Displayable::operator=(const Displayable & other)
		{
			std::cout << "operator przypisania kopiujacy" << std::endl;
			if (this != & other)
			{
				//zwalaniamy dane pod wskaźnikiem
				delete p_sprite;
				//tworzymy nowy obiekt na podstawie obiektu źródłowego
				//p_sprite = new sf::Sprite(*other.p_sprite);
				p_sprite = new Sprite(*other.p_sprite);
			}
			return *this;
		}

		//Przeciążony operator przypisania przenoszenia
		Displayable & Displayable::operator=(Displayable && other)
		{
			std::cout << "operator przypisania przenoszenia" << std::endl;
			if (this != & other)
			{
				//zwalaniamy dane pod wskaźnikiem
				delete p_sprite;
				//przenosimy pod wskaźnik dane z obiektu źródłowego
				p_sprite = other.p_sprite;
				//zwalniamy wskaźnik na dane obiektu źródłowego tak, aby
				//destruktor nie zwalniał pamięci wielokrotnie
				other.p_sprite = nullptr;
			}
				return *this;
		}



		////Metoda zwraca wskaźnik na obiekt sf::Sprite
		//sf::Sprite & Displayable::getSprite()
		//{
		//	return m_sprite;
		//}

		////Metoda ustawia referencję na obiekt sf::Sprite
		//void Displayable::setSprite(sf::Sprite & sprite)
		//{
		//	m_sprite = sprite;
		//}

		//Metoda zwraca stałą referencję pozycji obiektu
		const sf::Vector2f & Displayable::getPosition() const
		{
			return p_sprite->getPosition();
		}

		//Metoda ustawia pozycję obiektu
		void Displayable::setPosition(float x, float y)
		{
			if(p_sprite)
				p_sprite->setPosition(x, y);
		}

		//Metoda ustawia pozycję obiektu
		void Displayable::setPosition(const sf::Vector2f & vector)
		{
			setPosition(vector.x, vector.y);
		}

		////Metoda zwraca wartość obrotu
		//float CDisplayable::getRotation() const
		//{ 
		//	return m_sprite->getRotation();
		//}

		////Metoda ustawia wartość obrotu
		//void CDisplayable::setRotation(float rotation_value)
		//{
		//	m_sprite->setRotation(rotation_value);
		//}

		////Metoda obraca wartość obrotu
		//void CDisplayable::rotate(float angle)
		//{
		//	m_sprite->rotate(angle);
		//}

		////Metoda zwraca skalę
		//const sf::Vector2f& CDisplayable::getScale() const
		//{
		//	return m_sprite->getScale();
		//}

		////Metoda ustawia skalę
		//void CDisplayable::setScale(float x, float y)
		//{
		//	m_sprite->setScale(x, y);
		//}

		////Metoda ustawia skalę
		//void CDisplayable::setScale(const sf::Vector2f& new_scale_value)
		//{
		//	m_sprite->setScale(new_scale_value);
		//}

		////Metoda ustawia skalę
		//void CDisplayable::setScale(float factors)
		//{
		//	setScale(factors, factors);
		//}

		////Metoda ustawia skalę w stosunku do obecnej skali
		//void CDisplayable::scale(float factorX, float factorY)
		//{
		//	m_sprite->scale(factorX, factorY);
		//}

		////Metoda ustawia skalę w stosunku do obecnej skali
		//void CDisplayable::scale(const sf::Vector2f& factor)
		//{
		//	m_sprite->scale(factor);
		//}

		////Metoda zwraca współrzędne punktu uchwytu obiektu
		//const sf::Vector2f& CDisplayable::getOrigin() const
		//{
		//	return m_sprite->getOrigin();
		//}

		////Metoda ustawia współrzędne punktu uchwytu obiektu
		//void CDisplayable::setOrigin(float x, float y)
		//{
		//	m_sprite->setOrigin(x, y);
		//}

		////Metoda ustawia współrzędne punktu uchwytu obiektu
		//void CDisplayable::setOrigin(const sf::Vector2f& origin)
		//{
		//	m_sprite->setOrigin(origin);
		//}

		////Metoda zwraca obszar prostokątny zajmowany przez teksturę
		//const sf::IntRect& CDisplayable::getTextureRect() const
		//{
		//	return m_sprite->getTextureRect();
		//}

		////Metoda ustawia obszar prostokątny zajmowany przez teksturę
		//void CDisplayable::setTextureRect(int rectLeft, int rectTop, int rectWidth, int rectHeight)
		//{
		//	setTextureRect(sf::IntRect(rectLeft, rectTop, rectWidth, rectHeight));
		//}

		////Metoda ustawia obszar prostokątny zajmowany przez teksturę
		//void CDisplayable::setTextureRect (const sf::IntRect& rectangle)
		//{
		//	m_sprite->setTextureRect(rectangle);
		//}

		////Metoda zwraca granice obiektu w lokalnym w układzie współrzędnych
		//sf::FloatRect CDisplayable::getLocalBounds() const
		//{
		//	return m_sprite->getLocalBounds();
		//}

		////Metoda zwraca granice obiektu w globalnym w układzie współrzędnych
		//sf::FloatRect CDisplayable::getGlobalBounds() const
		//{
		//	return m_sprite->getGlobalBounds();
		//}

		////Metoda przemieszcza obiekt o wartość podaną w parametrach względem aktualnej pozycji
		//void CDisplayable::move(float offsetX, float offsetY)
		//{
		//	m_sprite->move(offsetX, offsetY);
		//}

		////Metoda przemieszcza obiekt o wartość wektora przesunięcia
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

		////Metoda ustawia teksturę obiektu
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

		////Metoda ustawia teksturę obiektu
		//void CDisplayable::setTexture(CTexture *p_texture, bool smoothing)
		//{
		//	if (m_animation_state)					//jeśli wskaźnik na CAnimationState jest zainicjowany
		//	{
		//		gAnimationManager.DestroyAnimationState(m_animation_state);//usuwamy animację
		//		m_animation_state = NULL;			//ustawiamy wskaźnik na NULL
		//	}

		//	if (p_texture != NULL)					//jeśli mamy wskaźnik poprawnie wskazujący na teksturę
		//	{
		//		p_texture->setSmooth(m_smooth);
		//		m_sprite->setTexture(*p_texture);	//ustawiamy teskturę
		//		//po załadowaniu tekstury wyznaczamy punkt uchwytu sprite'a na jego środek geometryczny
		//		m_sprite->setOrigin(m_sprite->getLocalBounds().width * 0.5f, m_sprite->getLocalBounds().height * 0.5f);
		//	}
		//}

		////Metoda generuje obraz tekstury
		//void CDisplayable::SetTexture(unsigned width, unsigned height, const sf::Color & color)
		//{
		//	if (m_animation_state)					//jeśli wskaźnik na CAnimationState jest zainicjowany
		//	{
		//		gAnimationManager.DestroyAnimationState(m_animation_state);//usuwamy animację
		//		m_animation_state = NULL;			//ustawiamy wskaźnik na NULL
		//	}

		//	p_synthetic_texture->create(width, height);
		//	p_synthetic_image->create(width, height, color);
		//	p_synthetic_texture->update(*p_synthetic_image);
		//	m_sprite->setTexture(*p_synthetic_texture);
		//}

		////Metoda generuje obraz tekstury
		//void CDisplayable::SetTexture(unsigned width, unsigned height, unsigned r, unsigned g, unsigned b, unsigned a)
		//{
		//	if (m_animation_state)					//jeśli wskaźnik na CAnimationState jest zainicjowany
		//	{
		//		gAnimationManager.DestroyAnimationState(m_animation_state);//usuwamy animację
		//		m_animation_state = NULL;			//ustawiamy wskaźnik na NULL
		//	}
		//	
		//	p_synthetic_texture->create(width, height);
		//	p_synthetic_image->create(width, height, sf::Color(r, g, b, a));
		//	p_synthetic_texture->update(*p_synthetic_image);
		//	m_sprite->setTexture(*p_synthetic_texture);
		//}

		////Metoda ustawia animację
		//void CDisplayable::SetAnimation(const std::string& animation_name)
		//{
		//	//warunki, gdy zamiana animacji się nie powiedzie:
		//	//nie jest ładowana animacja, jeśli próbujemy
		//	//zamienić ją na taką samą (istniejącą pod taką samą nazwą)
		//	if (m_animation_name == animation_name) return;

		//	m_animation_name = animation_name;

		//	//usuwamy animację, jeśli wcześniej jakaś była
		//	if (m_animation_state)
		//		gAnimationManager.DestroyAnimationState(m_animation_state);

		//	//tworzymy nową animację
		//	m_animation_state = gAnimationManager.CreateAnimationState(animation_name);

		//	if (!m_animation_state)
		//	{
		//		fprintf(stderr, "warning: CDisplayable::SetAnimation: unable to obtain animation `%s'\n", animation_name.c_str());
		//	} 
		//}

		////Metoda ustawia animację
		//void CDisplayable::SetAnimation(CAnimation *p_animation)
		//{
		//	//warunki, gdy zamiana animacji się nie powiedzie:
		//	//jeśli wskaźnik jest NULL - return
		//	//jeśli wskaźnik jest zainicjowany, a próbujemy go zainicjować takim samym wskaźnikiem - return

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

		////Metoda zwraca wskaźnik na obiekt klasy CAnimationState
		//CAnimationState* CDisplayable::GetAnimationState()
		//{
		//	return m_animation_state;
		//}
		//
		/////Metoda zwraca tryb wygładzania tekstury
		//const bool CDisplayable::getSmoothing() const
		//{
		//	return m_smooth;
		//}

		////Metoda ustawia tryb wygładzania tekstury
		//void CDisplayable::setSmoothing(bool smooth)
		//{
		//	m_smooth = smooth;
		//}

		//Metoda ustawia teksturę dla sprite
		void Displayable::setTexture(const sf::Texture & texture)
		{
			if(p_sprite)
				p_sprite->setTexture(texture);
		}

		//Wirtualna metoda renderująca obiekt
		void Displayable::draw(sf::RenderWindow & render)
		{
			//jeśli flaga nie pozwala - nie rysujemy obiektu - return
			//if(m_can_draw == false)	return;

			//jeśli wskaźnik na obiekt CAnimationState pokazuje na animację
			//if (m_animation_state)
			//{
			//	//tworzymy klatkę animacji i pobieramy bieżącą klatkę z CAnimationState
			//	CAnimationFrame frame = m_animation_state->GetCurrentFrame();

			//	//tworzymy wskaźnik na obiekt klasy CTexture (tekstura)
			//	//inicjujemy ten wskaźnik obrazem pobranym na podstawie nazwy
			//	//tekstury, na której znajduje sie klatka animacji.
			//	//CResourceManager zwraca na podstawie tej nazwy wskaźnik na teksturę.
			//	CTexture* p_texture = gResourceManager.GetTexture(frame.GetTextureName());
			//	//ustawiamy flagę wygładzania tekstury
			//	p_texture->setSmooth(m_smooth);

			//	//jeśli wskaźnik nie jest zainicjowany - komunikat o błędzie
			//	if (!p_texture)
			//	{
			//		fprintf(stderr, "warning: CDisplayable::Draw: animation: unable to obtain image `%s'\n", frame.GetTextureName().c_str());
			//	}
			//	else
			//	{
			//		//w przeciwnym wypadku pobieramy obszar klatki animacji
			//		sf::IntRect rect = frame.GetImageRectangle();

			//		//sprawdzamy, wielkość tekstury (czy ten kod jest potrzebny?)
			//		//niech na razie sobie tutaj poleży, najwyżej można to zakomentować...
			//		//if (rect.left == 0 && rect.top == 0 && rect.width == 0 && rect.height == 0)
			//		//{
			//		//	rect.width = p_texture->getSize().x;	//wyznaczamy szerokość
			//		//	rect.height = p_texture->getSize().y;	//wyznaczamy wysokość
			//		//}
			//		p_texture->setSmooth(m_smooth);				//filtr
			//		m_sprite->setTexture(*p_texture);			//podłączamy wskaźnik na teksturę pod sprite'a
			//		m_sprite->setTextureRect(rect);				//podłączamy wyliczony obszar tekstury pod sprite'a

			//		//wyznaczamy punkt uchwytu sprite'a na jego środek geometryczny
			//		m_sprite->setOrigin(m_sprite->getLocalBounds().width * 0.5f, m_sprite->getLocalBounds().height * 0.5f);
			//	}
			//}
			
			//if(m_can_draw == false) return;	//na wszelki wypadek, gdyby w ramce czasu flaga ustawiła się na false
			if (p_sprite)					//na wszelki wypadek, gdyby wskaźnik stracił adres...
			{
				render.draw(*p_sprite);	//rysujemy obiekt
			}
		}
	}//namespace rendering
}//namespace acodemia
