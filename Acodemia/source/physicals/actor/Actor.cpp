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
// z tego oprogramowania.Zastrzega
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

#include "Actor.h"

namespace acodemia
{
	namespace physical
	{
		//Konstruktor domyślny
		Actor::Actor()
		:
			Physical(),//konstrutor klasy bazowej
			gun()
		{
		}

		//Konstruktor kopiujący
		Actor::Actor(const Actor & copy)
		:
			Physical(copy),//konstrutor kopiujący klasy bazowej
			gun(copy.gun)
		{
		}

		//Konstruktor przenoszący
		Actor::Actor(Actor && other)
		:
			Physical(other),//konstruktor przenoszący klasy bazowej
			gun(other.gun)
		{
		}

		//Destruktor
		Actor::~Actor()
		{
		}

		//Przeciążony operator przypisania kopiowania
		Actor & Actor::operator=(const Actor & copy)
		{
			if (this != &copy)
			{
				Actor::operator=(copy);
				gun = copy.gun;
			}
			return *this;
		}

		//Przeciążony operator przypisania przenoszenia
		Actor & Actor::operator=(Actor && other)
		{
			if (this != &other)
			{
				Actor::operator=(other);
				gun = other.gun;
			}
			return *this;
		}

		//Metoda ustawia teksturę dla kontekstu graficznego pocisku
		void Actor::setBulletTexture(const Texture & texture)
		{
			gun.setBulletTexture(texture);
		}

		//Wirtualna metoda aktualizująca obiekt
		void Actor::update(float dt)
		{
			gun.update(dt);
		}

		//Chroniona wirtualna metoda - strzał
		void Actor::shoot()
		{
			gun.shoot(*this);
		}

	}//namespace physical
}//namespace acodemia
