﻿//
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

#include "Enemy.h"
#include <iostream>
#include "../../manager/PhysicalManager.h"
#include "../bullet/Bullet.h"

namespace acodemia
{
	namespace physical
	{
		//Konstruktor domyślny
		Enemy::Enemy()
		:
			Actor()//konstruktor klasy bazowej
		{
		}

		//Konstruktor kopiujący
		Enemy::Enemy(const Enemy & copy)
		:
			Actor(copy)//konstruktor kopiujący klasy bazowej
		{
		}

		//Konstruktor przenoszący
		Enemy::Enemy(Enemy && other)
		:
			Actor(other)//konstruktor przenoszący klasy bazowej
		{
		}

		//Destruktor
		Enemy::~Enemy()
		{
		}

		//Przeciążony operator przypisania kopiowania
		Enemy & Enemy::operator=(const Enemy & copy)
		{
			if (this != &copy)
			{
				Actor::operator=(copy);
				//members...
			}
			return *this;
		}

		//Przeciążony operator przypisania przenoszenia
		Enemy & Enemy::operator=(Enemy && other)
		{
			if (this != &other)
			{
				Actor::operator=(other);
				//members...
			}
			return *this;
		}

		//Wirtualna metoda aktualizująca obiekt
		void Enemy::update(float dt)
		{
			setMotion(0, 1);
			Physical::update(dt);
			Actor::update(dt);
			controlEnemy(dt);
		}

		void Enemy::controlEnemy(float time)
		{
			Actor::shoot();
		}

	}//namespace physical
}//namespace acodemia