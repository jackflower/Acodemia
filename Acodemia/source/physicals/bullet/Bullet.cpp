////////////////////////////////////////////////////////////
//
// Acodemia Copyright (C) Jacek Kwiatek
// e-mail: jackflower (at) poczta.onet.pl
// acodemia.pl
//
// To oprogramowanie dostarczane jest w postaci takiej,
// w jakiej jest, bez wyraźnych ani domniemanych gwarancji.
//
// W żadnym wypadku Autor nie ponosi odpowiedzialności
// za jakiekolwiek szkody powstałe w wyniku korzystania
// z tego oprogramowania.
//
// Zezwala się na korzystanie z tego oprogramowania
// w dowolnym celu, także komercyjnym. Można je zmienić
// i swobodnie rozpowszechniać.
//
// Zastrzega się następujące ograniczenia:
//
// 1. Jeśli używasz tego oprogramowania w swoich
//    produktach, potwierdzenie pochodzenia tego
//    oprogramowania w dokumentacji produktu,
//    byłoby docenione, ale nie jest wymagane.
//
////////////////////////////////////////////////////////////

#include "Bullet.h"
#include <iostream>

//uporządkować bajzel...

namespace acodemia
{
	namespace physical
	{
		//Konstruktor domyślny
		Bullet::Bullet()
		:
			Physical()
		{
			//bajzel - uporządkować...
			m_move.x = 0.f;
			m_move.y = -1;
			//
			m_speed = 100;
			m_lifetime = 4.54f;
		}

		//Konstruktor kopiujący
		Bullet::Bullet(const Bullet & copy)
		:
			Physical(copy)//konstruktor kopiujący klasy bazowej
			//m_displayable(copy.m_displayable),
			//m_use_displayable(copy.m_use_displayable),
			//m_destruction(copy.m_destruction),
			//m_position(copy.m_position),
			//m_rotation(copy.m_rotation),
			//m_scale(copy.m_scale),
			//m_origin(copy.m_origin),
			//m_color(copy.m_color),
			//m_stored_color(copy.m_stored_color)
		{
		}

		//Konstruktor przenoszący
		Bullet::Bullet(Bullet && other)
		:
			Physical(other)//konstruktor przenoszący klasy bazowej
			////przenosimy dane obiektu źródłowego
			//m_displayable(other.m_displayable),
			//m_use_displayable(other.m_use_displayable),
			//m_destruction(other.m_destruction),
			//m_position(other.m_position),
			//m_rotation(other.m_rotation),
			//m_scale(other.m_scale),
			//m_origin(other.m_origin),
			//m_color(other.m_color),
			//m_stored_color(other.m_stored_color)
		{
		}

		//Destruktor wirtualny
		Bullet::~Bullet()
		{
		}

		//Przeciążony operator przypisania kopiowania
		Bullet & Bullet::operator=(const Bullet & copy)
		{
			//if (this != &copy)
			//{
			//	m_displayable = copy.m_displayable;
			//	m_use_displayable = copy.m_use_displayable;
			//	m_destruction = copy.m_destruction;
			//	m_position = copy.m_position;
			//	m_rotation = copy.m_rotation;
			//	m_scale = copy.m_scale;
			//	m_origin = copy.m_origin;
			//	m_color = copy.m_color;
			//	m_stored_color = copy.m_stored_color;
			//}
			return *this;
		}

		//Przeciążony operator przypisania przenoszenia
		Bullet & Bullet::operator =(Bullet && other)
		{
			//if (this != &other)
			//{
			//	m_displayable = other.m_displayable;
			//	m_use_displayable = other.m_use_displayable;
			//	m_destruction = other.m_destruction;
			//	m_position = other.m_position;
			//	m_rotation = other.m_rotation;
			//	m_scale = other.m_scale;
			//	m_origin = other.m_origin;
			//	m_color = other.m_color;
			//	m_stored_color = other.m_stored_color;
			//}
			return *this;
		}

		//Wirtualna metoda aktualizująca obiekt
		void Bullet::update(float dt)
		{
			m_elapsedtime = m_elapsedtime + dt;
			if (m_elapsedtime > m_lifetime)
				destroy();

			sf::Vector2f new_position;
			new_position.x = m_position.x + m_move.x * m_speed * dt;
			new_position.y = m_position.y + m_move.y * m_speed * dt;
			m_position = new_position;

			//std::cout << "Pocisk" << std::endl;
			//std::cout << m_position.x << std::endl;
			setPosition(m_position);
		}

	}//namespace physical
}//namespace acodemia
