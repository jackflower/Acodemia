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

#include "Gun.h"
#include "../bullet/Bullet.h"
#include "../../manager/PhysicalManager.h"

using namespace acodemia::physical;

namespace acodemia
{
	namespace physical
	{
		//Konstruktor domyślny
		Gun::Gun()
		:
			Physical(),//konstruktor klasy bazowej
			p_bullet_texture(nullptr),
			m_elapsed_time(0.0f),
			m_shoot_timer(0.0f),
			m_shoot_enabled(false),
			m_bullet_speed(0.0f),
			m_bullet_start_position()
		{
		}

		//Konstruktor kopiujący
		Gun::Gun(const Gun & copy)
		:
			Physical(copy),//konstruktor kopiujący klasy bazowej
			//kopiujemy dane obiektu źródłowego
			p_bullet_texture(copy.p_bullet_texture),
			m_elapsed_time(copy.m_elapsed_time),
			m_shoot_timer(copy.m_shoot_timer),
			m_shoot_enabled(copy.m_shoot_enabled),
			m_bullet_speed(copy.m_bullet_speed),
			m_bullet_start_position(copy.m_bullet_start_position)
		{
		}

		//Konstruktor przenoszący
		Gun::Gun(Gun && other)
		:
			Physical(other),//konstruktor przenoszący klasy bazowej
			//przenosimy dane obiektu źródłowego
			p_bullet_texture(other.p_bullet_texture),
			m_elapsed_time(other.m_elapsed_time),
			m_shoot_timer(other.m_shoot_timer),
			m_shoot_enabled(other.m_shoot_enabled),
			m_bullet_speed(other.m_bullet_speed),
			m_bullet_start_position(other.m_bullet_start_position)
		{
		}

		//Destruktor
		Gun::~Gun()
		{
			p_bullet_texture = nullptr;
			m_shoot_timer = 0.0f;
			m_elapsed_time = 0.0f;
			m_shoot_enabled = false;
			m_bullet_speed = 0.0f;
			m_bullet_start_position.x = 0.0f;
			m_bullet_start_position.y = 0.0f;
		}

		//Przeciążony operator przypisania kopiowania
		Gun & Gun::operator=(const Gun & copy)
		{
			if (this != &copy)
			{
				Physical::operator=(copy);
				p_bullet_texture = copy.p_bullet_texture;
				m_shoot_timer = copy.m_shoot_timer;
				m_elapsed_time = copy.m_elapsed_time;
				m_shoot_enabled = copy.m_shoot_enabled;
				m_bullet_speed = copy.m_bullet_speed;
				m_bullet_start_position = copy.m_bullet_start_position;
			}
			return *this;
		}

		//Przeciążony operator przypisania przenoszenia
		Gun & Gun::operator=(Gun && other)
		{
			if (this != &other)
			{
				Physical::operator=(other);
				p_bullet_texture = other.p_bullet_texture;
				m_shoot_timer = other.m_shoot_timer;
				m_elapsed_time = other.m_elapsed_time;
				m_shoot_enabled = other.m_shoot_enabled;
				m_bullet_speed = other.m_bullet_speed;
				m_bullet_start_position = other.m_bullet_start_position;
			}
			return *this;
		}

		//Metoda ustawia wskaźnik na teksturę dla kontekstu graficznego pocisku
		void Gun::setBulletTexture(Texture * texture)
		{
			p_bullet_texture = texture;
		}

		//Metoda generuje strzał
		void Gun::shoot(const Physical & owner)
		{
			if (m_shoot_enabled)
			{
				if (p_bullet_texture)
				{
					//tworzymy pocisk, konfigurujemy go, strzelamy
					Bullet *bullet = gPhysicalManager.CreateBullet();
					bullet->setTexture(*p_bullet_texture);
					bullet->setUseDisplayable(true);
					//skala
					bullet->setScale(owner.getScale());
					bullet->setOrigin(bullet->getLocalBounds().width * 0.5f, bullet->getLocalBounds().height * 0.5f);
					//korekta...pozycja startowa pocisku jest za lufą - pocisk nie może kolidować...
					m_bullet_start_position.x = owner.getPosition().x + 0.0f;
					m_bullet_start_position.y = owner.getPosition().y - owner.getGlobalBounds().height * 0.5f;
					//porawka na wielkość pocisku
					m_bullet_start_position.x = owner.getPosition().x + 0.0f;
					m_bullet_start_position.y = m_bullet_start_position.y - bullet->getGlobalBounds().height * 0.5f;
					bullet->setPosition(m_bullet_start_position);

					bullet->setMotion(0.f, -1.f);
					bullet->setSpeed(100.f);
					bullet->setLifeTime(4.52f);
					m_shoot_timer = 0.25f;//strzał co 1/4 sekundy (4 pociski na sekundę)
					m_shoot_enabled = false;
				}
			}
		}

		//Metoda aktualizująca obiekt
		void Gun::update(float dt)
		{
			m_elapsed_time = m_elapsed_time + dt;

			if (m_elapsed_time >= m_shoot_timer)
			{
				m_elapsed_time = 0.0f;
				m_shoot_enabled = true;
			}
		}

	}//namespace physical
}// namespace acodemia
