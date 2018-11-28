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

#include "Player.h"
#include <iostream>

namespace acodemia
{
	namespace physical
	{
		//Konstruktor domyślny
		Player::Player()
		{
			//doliczyć klasę bazową
		}

		//Konstruktor kopiujący
		Player::Player(const Player & copy)
		{
			//doliczyć klasę bazową
		}

		//Konstruktor przenoszący
		Player::Player(Player && other)
		{
			//doliczyć klasę bazową
		}

		//Destruktor
		Player::~Player()
		{
			//doliczyć klasę bazową
		}

		//Przeciążony operator przypisania kopiowania
		Player & Player::operator=(const Player & copy)
		{
			if (this != &copy)
			{
				Physical::operator=(copy);
				//members...
			}
			return *this;
		}

		//Przeciążony operator przypisania przenoszenia
		Player & Player::operator=(Player && other)
		{
			if (this != &other)
			{
				Physical::operator=(other);
				//members...
			}
			return *this;
		}

		//Wirtualna metoda aktualizująca obiekt
		void Player::update(float dt)
		{
			rotate(0.05f);
			//sterowanie...
			//opakować do prywatnej metody class Player
			//metoda ograniczająca sterowanie do wielkości sceny
			//bool inScene();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				setMotion(1, 0);
				Physical::update(dt);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				setMotion(-1, 0);
				Physical::update(dt);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				setMotion(0, -1);
				Physical::update(dt);
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				setMotion(0, 1);
				Physical::update(dt);
			}

		}
		
	}//namespace physical
}//namespace acodemia
