////////////////////////////////////////////////////////////
//
// Acodemia Copyright (C) Jacek Kwiatek
// e-mail: jackflower (at) poczta.onet.pl
// acodemia.pl
//
// To oprogramowanie dostarczane jest w postaci takiej,
// w jakiej jest, bez wyra�nych ani domniemanych gwarancji.
//
// W �adnym wypadku Autor nie ponosi odpowiedzialno�ci
// za jakiekolwiek szkody powsta�e w wyniku korzystania
// z tego oprogramowania.Zastrzega
//
// Zezwala si� na korzystanie z tego oprogramowania
// w dowolnym celu, tak�e komercyjnym. Mo�na je zmieni�
// i swobodnie rozpowszechnia�.
//
// Zastrzega si� nast�puj�ce ograniczenia:
//
// 1. Je�li u�ywasz tego oprogramowania w swoich
//    produktach, potwierdzenie pochodzenia tego
//    oprogramowania w dokumentacji produktu,
//    by�oby docenione, ale nie jest wymagane.
//
////////////////////////////////////////////////////////////

#include "Actor.h"

namespace acodemia
{
	namespace physical
	{
		//Konstruktor domy�lny
		Actor::Actor()
		:
			Physical()//konstrutor klasy bazowej
		{
		}

		//Konstruktor kopiuj�cy
		Actor::Actor(const Actor & copy)
		:
			Physical(copy)//konstrutor kopiuj�cy klasy bazowej
		{
		}

		//Konstruktor przenosz�cy
		Actor::Actor(Actor && other)
		:
			Physical(other)//konstruktor przenosz�cy klasy bazowej
		{
		}

		//Destruktor
		Actor::~Actor()
		{
		}

		//Przeci��ony operator przypisania kopiowania
		Actor & Actor::operator=(const Actor & copy)
		{
			if (this != &copy)
			{
				Physical::operator=(copy);
				//members...
			}
			return *this;
		}

		//Przeci��ony operator przypisania przenoszenia
		Actor & Actor::operator=(Actor && other)
		{
			if (this != &other)
			{
				Physical::operator=(other);
				//members...
			}
			return *this;
		}

		//Wirtualna metoda aktualizuj�ca obiekt
		void Actor::update(float dt)
		{
			//sterowanie, strzelanie, etc...
		}

	}//namespace physical
}//namespace acodemia
