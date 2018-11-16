////////////////////////////////////////////////////////////
//
// Acodemia Copyright (C) Jacek Kwiatek
// e-mail: jackflower (at) poczta.onet.pl
// acodemia.pl
//
// To oprogramowanie dostarczane jest w postaci takiej,
// w jakiej jest, bez wyraŸnych ani domniemanych gwarancji.
//
// W ¿adnym wypadku Autor nie ponosi odpowiedzialnoœci
// za jakiekolwiek szkody powsta³e w wyniku korzystania
// z tego oprogramowania.Zastrzega
//
// Zezwala siê na korzystanie z tego oprogramowania
// w dowolnym celu, tak¿e komercyjnym. Mo¿na je zmieniæ
// i swobodnie rozpowszechniaæ.
//
// Zastrzega siê nastêpuj¹ce ograniczenia:
//
// 1. Jeœli u¿ywasz tego oprogramowania w swoich
//    produktach, potwierdzenie pochodzenia tego
//    oprogramowania w dokumentacji produktu,
//    by³oby docenione, ale nie jest wymagane.
//
////////////////////////////////////////////////////////////

#include "Actor.h"

namespace acodemia
{
	namespace physical
	{
		//Konstruktor domyœlny
		Actor::Actor()
		:
			Physical()//konstrutor klasy bazowej
		{
		}

		//Konstruktor kopiuj¹cy
		Actor::Actor(const Actor & copy)
		:
			Physical(copy)//konstrutor kopiuj¹cy klasy bazowej
		{
		}

		//Konstruktor przenosz¹cy
		Actor::Actor(Actor && other)
		:
			Physical(other)//konstruktor przenosz¹cy klasy bazowej
		{
		}

		//Destruktor
		Actor::~Actor()
		{
		}

		//Przeci¹¿ony operator przypisania kopiowania
		Actor & Actor::operator=(const Actor & copy)
		{
			if (this != &copy)
			{
				Physical::operator=(copy);
				//members...
			}
			return *this;
		}

		//Przeci¹¿ony operator przypisania przenoszenia
		Actor & Actor::operator=(Actor && other)
		{
			if (this != &other)
			{
				Physical::operator=(other);
				//members...
			}
			return *this;
		}

		//Wirtualna metoda aktualizuj¹ca obiekt
		void Actor::update(float dt)
		{
			//sterowanie, strzelanie, etc...
		}

	}//namespace physical
}//namespace acodemia
