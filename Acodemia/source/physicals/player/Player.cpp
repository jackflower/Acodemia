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

#include "Player.h"

namespace acodemia
{
	namespace physical
	{
		//Konstruktor domyœlny
		Player::Player()
		{
			//doliczyæ klasê bazow¹
		}

		//Konstruktor kopiuj¹cy
		Player::Player(const Player & copy)
		{
			//doliczyæ klasê bazow¹
		}

		//Konstruktor przenosz¹cy
		Player::Player(Player && other)
		{
			//doliczyæ klasê bazow¹
		}

		//Destruktor
		Player::~Player()
		{
			//doliczyæ klasê bazow¹
		}

		//Przeci¹¿ony operator przypisania kopiowania
		Player & Player::operator=(const Player & copy)
		{
			if (this != &copy)
			{
				Physical::operator=(copy);
				//members...
			}
			return *this;
		}

		//Przeci¹¿ony operator przypisania przenoszenia
		Player & Player::operator=(Player && other)
		{
			if (this != &other)
			{
				Physical::operator=(other);
				//members...
			}
			return *this;
		}

		//Wirtualna metoda aktualizuj¹ca obiekt
		void Player::update(float dt)
		{
			//sterowanie, strzelanie, etc...
		}
		
	}//namespace physical
}//namespace acodemia
