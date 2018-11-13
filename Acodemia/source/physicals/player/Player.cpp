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

#include "Player.h"

namespace acodemia
{
	namespace physical
	{
		//Konstruktor domy�lny
		Player::Player()
		{
			//doliczy� klas� bazow�
		}

		//Konstruktor kopiuj�cy
		Player::Player(const Player & copy)
		{
			//doliczy� klas� bazow�
		}

		//Konstruktor przenosz�cy
		Player::Player(Player && other)
		{
			//doliczy� klas� bazow�
		}

		//Destruktor
		Player::~Player()
		{
			//doliczy� klas� bazow�
		}

		//Przeci��ony operator przypisania kopiowania
		Player & Player::operator=(const Player & copy)
		{
			if (this != &copy)
			{
				Physical::operator=(copy);
				//members...
			}
			return *this;
		}

		//Przeci��ony operator przypisania przenoszenia
		Player & Player::operator=(Player && other)
		{
			if (this != &other)
			{
				Physical::operator=(other);
				//members...
			}
			return *this;
		}

		//Wirtualna metoda aktualizuj�ca obiekt
		void Player::update(float dt)
		{
			//sterowanie, strzelanie, etc...
		}
		
	}//namespace physical
}//namespace acodemia
