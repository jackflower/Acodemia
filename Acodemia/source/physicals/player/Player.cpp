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
#include "../../manager/PhysicalManager.h"
#include "../bullet/Bullet.h"

namespace acodemia
{
	namespace physical
	{
		//Konstruktor domyślny
		Player::Player()
		:
			Actor(),
			m_bullet_texture(),
			m_elapsed_time(0.0f),
			m_shoot_timer(0.25f),//strzał co 1/4 sekundy (4 pociski na sekundę)
			shoot_enabled(false)
		{
			//doliczyć klasę bazową

			// B u l l e t
			m_bullet_texture.loadFromFile("../data/bullet.png");
			m_bullet_texture.setSmooth(true);
		}

		//Konstruktor kopiujący
		Player::Player(const Player & copy)
		//doliczyć klasę bazową
		{
		}

		//Konstruktor przenoszący
		Player::Player(Player && other)
			//doliczyć klasę bazową
		{
		}

		//Destruktor
		Player::~Player()
		{
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

			//metoda ograniczająca sterowanie do wielkości sceny...
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

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				shoot();


			//co robi ten kod?
			m_elapsed_time = m_elapsed_time + dt;

			if (m_elapsed_time >= m_shoot_timer)
			{
				m_elapsed_time = 0.0f;
				shoot_enabled = true;
			}

		}
		
		void Player::shoot()
		{
			if (shoot_enabled)
			{
				//strzelamy
				Bullet *bullet = gPhysicalManager.CreateBullet();
				bullet->setTexture(m_bullet_texture);
				bullet->setUseDisplayable(true);
				bullet->setPosition(m_position.x, m_position.y);
				bullet->setMotion(0.f, -1.f);
				bullet->setSpeed(100.f);
				bullet->setLifeTime(4.52f);
				shoot_enabled = false;
			}

		}
	}//namespace physical
}//namespace acodemia
