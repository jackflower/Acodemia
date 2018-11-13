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

namespace acodemia
{
	namespace physical
	{
		//Konstruktor domyślny
		Bullet::Bullet()
		:
			Physical(),
			m_motion(),
			m_speed(0.f),
			m_caliber(0.f),
			m_lifetime(0.f),
			m_elapsedtime(0.f)
		{
		}

		//Konstruktor kopiujący
		Bullet::Bullet(const Bullet & copy)
		:
			Physical(copy),//konstruktor kopiujący klasy bazowej
			m_motion(copy.m_motion),
			m_speed(copy.m_speed),
			m_caliber(copy.m_caliber),
			m_lifetime(copy.m_lifetime),
			m_elapsedtime(copy.m_elapsedtime)
		{
		}

		//Konstruktor przenoszący
		Bullet::Bullet(Bullet && other)
		:
			Physical(other),//konstruktor przenoszący klasy bazowej
			m_motion(other.m_motion),
			m_speed(other.m_speed),
			m_caliber(other.m_caliber),
			m_lifetime(other.m_lifetime),
			m_elapsedtime(other.m_elapsedtime)
		{
		}

		//Destruktor wirtualny
		Bullet::~Bullet()
		{
			m_motion.x = 0.f;
			m_motion.y = 0.f;
			m_speed = 0.f;
			m_caliber = 0.f;
			m_lifetime = 0.f;
			m_elapsedtime = 0.f;
		}

		//Przeciążony operator przypisania kopiowania
		Bullet & Bullet::operator=(const Bullet & copy)
		{
			if (this != &copy)
			{
				Physical::operator=(copy);
				m_motion = copy.m_motion;
				m_speed = copy.m_speed;
				m_caliber = copy.m_caliber;
				m_lifetime = copy.m_lifetime;
				m_elapsedtime = copy.m_elapsedtime;
			}
			return *this;
		}

		//Przeciążony operator przypisania przenoszenia
		Bullet & Bullet::operator =(Bullet && other)
		{
			if (this != &other)
			{
				Physical::operator=(other);
				m_motion = other.m_motion;
				m_speed = other.m_speed;
				m_caliber = other.m_caliber;
				m_lifetime = other.m_lifetime;
				m_elapsedtime = other.m_elapsedtime;
			}
			return *this;
		}

		//Metoda zwraca stałą referencję na wektor kierunku
		const sf::Vector2f & Bullet::getMotion() const
		{
			return m_motion;
		}

		//Metoda ustawia wektor kierunku
		void Bullet::setMotion(const sf::Vector2f & motion)
		{
			m_motion = motion;
		}

		//Metoda ustawia wektor kierunku
		void Bullet::setMotion(float x, float y)
		{
			m_motion.x = x;
			m_motion.y = y;
		}

		//Metoda zwraca prędkość pocisku
		const float Bullet::getSpeed() const
		{
			return m_speed;
		}

		void Bullet::setSpeed(float speed)
		{
			m_speed = speed;
		}

		//Metoda zwraca kaliber pocisku
		const float Bullet::getCaliber() const
		{
			return m_caliber;
		}

		//Metoda ustawia kaliber pocisku
		void Bullet::setCaliber(float caliber)
		{
			m_caliber = caliber;
		}

		//Metoda zwraca czas życia pocisku
		const float Bullet::getLifeTime() const
		{
			return m_lifetime;
		}

		//Metoda ustawia czas życia pocisku
		void Bullet::setLifeTime(float lifetime)
		{
			m_lifetime = lifetime;
		}

		//Wirtualna metoda aktualizująca obiekt
		void Bullet::update(float dt)
		{
			//zliczamy czas życia pocisku
			m_elapsedtime += dt;
			//po upływie określonego czasu
			if (m_elapsedtime > m_lifetime)
				destroy();//niszczymy pocisk

			//aktualizacja pozycji pocisku
			sf::Vector2f new_position;
			new_position.x = m_position.x + m_motion.x * m_speed * dt;
			new_position.y = m_position.y + m_motion.y * m_speed * dt;
			m_position = new_position;
			setPosition(m_position);
		}

	}//namespace physical
}//namespace acodemia
