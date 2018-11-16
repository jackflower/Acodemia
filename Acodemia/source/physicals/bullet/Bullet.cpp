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
			m_caliber(0.f),
			m_lifetime(0.f),
			m_elapsedtime(0.f)
		{
		}

		//Konstruktor kopiujący
		Bullet::Bullet(const Bullet & copy)
		:
			Physical(copy),//konstruktor kopiujący klasy bazowej
			m_caliber(copy.m_caliber),
			m_lifetime(copy.m_lifetime),
			m_elapsedtime(copy.m_elapsedtime)
		{
		}

		//Konstruktor przenoszący
		Bullet::Bullet(Bullet && other)
		:
			Physical(other),//konstruktor przenoszący klasy bazowej
			m_caliber(other.m_caliber),
			m_lifetime(other.m_lifetime),
			m_elapsedtime(other.m_elapsedtime)
		{
		}

		//Destruktor wirtualny
		Bullet::~Bullet()
		{
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
				m_caliber = other.m_caliber;
				m_lifetime = other.m_lifetime;
				m_elapsedtime = other.m_elapsedtime;
			}
			return *this;
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

			//aktualizacja pozycji
			Physical::update(dt);

			//zliczamy czas życia pocisku
			m_elapsedtime += dt;
			//po upływie określonego czasu
			if (m_elapsedtime > m_lifetime)
				destroy();//niszczymy pocisk
		}

	}//namespace physical
}//namespace acodemia
