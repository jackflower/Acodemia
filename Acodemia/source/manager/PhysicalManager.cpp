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

#include "PhysicalManager.h"
#include "../physicals/physical/Physical.h"
#include "../physicals/bullet/Bullet.h"
#include "../physicals/actor/Actor.h"
#include "../physicals/player/Player.h"
#include "../physicals/enemy/Enemy.h"
#include<iostream>

using namespace acodemia::physical;

//Konstruktor domyślny
PhysicalManager::PhysicalManager()
:
	m_physicals()
{
}

//Destruktor wirtualny
PhysicalManager::~PhysicalManager()
{
	std::vector<Physical*>::iterator it;
	for (it = m_physicals.begin(); it != m_physicals.end(); it++)
	{
		if((*it))
			delete (*it);
	}
	m_physicals.clear();
}

//Metoda zwraca stałą referencję kontenera
const std::vector<Physical *> & PhysicalManager::getPhysicals()
{
	return m_physicals;
}

//Metoda rejestruje w kontenerze wskaźniki na obiekty Physical
void PhysicalManager::registerPhysical(Physical * physical)
{
	m_physicals.push_back(physical);
}

//Metoda aktualizuje  wskaźniki na obiekty Physical
void PhysicalManager::updatePhysical(float dt)
{
	for (unsigned int i = 0; i < m_physicals.size(); i++)
	{
		checkCollision(m_physicals.at(i));
		//checkEnemyCollision(m_physicals.at(i));
		//checkPlayerCollision(m_physicals.at(i));
		//checkBulletCollision(m_physicals.at(i));

		m_physicals.at(i)->update(dt);

		//jeśli obiekt jest oznaczony do zniszczaenia
		if(m_physicals.at(i)->getDestruction())
		{
				delete m_physicals.at(i);
				m_physicals.at(i) = nullptr;
				m_physicals.erase(m_physicals.begin() + i);
		}
		//m_physicals.at(i)->getbu
	}
}

//Wirtualna metoda rysująca obiekt
void PhysicalManager::draw(sf::RenderWindow & render) const
{
	std::vector<Physical*>::const_iterator it;//iterator tego kontenera
	for (it = m_physicals.begin(); it != m_physicals.end(); it++)
	{
		if ((*it) != nullptr)
			if ((*it)->getUseDisplayable() and !(*it)->getDestruction())
				(*it)->draw(render);
	}
}

// f a c t o r y  - implementacja

//Metoda tworzy obiekt klasy Physical i zwraca wskaźnik na ten obiekt
Physical *PhysicalManager::CreatePhysical()
{
	return Create<Physical>();
}

//Metoda tworzy obiekt klasy Bullet i zwraca wskaźnik na ten obiekt
Bullet *PhysicalManager::CreateBullet()
{
	return Create<Bullet>();
}

//Metoda tworzy obiekt klasy Actor i zwraca wskaźnik na ten obiekt
Actor *PhysicalManager::CreateActor()
{
	return Create<Actor>();
}

//Metoda tworzy obiekt klasy Player i zwraca wskaźnik na ten obiekt
Player *PhysicalManager::CreatePlayer()
{
	return Create<Player>();
}

//Metoda tworzy obiekt klasy Enemy i zwraca wskaźnik na ten obiekt
Enemy *PhysicalManager::CreateEnemy()
{
	return Create<Enemy>();
}

//Metoda sprawdza, czy nastąpiła jakaś kolizja
bool PhysicalManager::checkCollision(Physical *collider)
{
	std::string typ = typeid(*collider).name();

	//sprawdzam, które elementy z listy kolidują z lecącym pociskiem
	for (unsigned int i = 0; i < m_physicals.size(); i++)
	{
		if (m_physicals.at(i) != collider)//blokujemy kolizję "sam ze sobą"
		{
			if (m_physicals.at(i)->getGlobalBounds().intersects(collider->getGlobalBounds()))
			{
				if (m_physicals.at(i)->getGlobalBounds().intersects(collider->getGlobalBounds()))
				{
					if (typ == "class acodemia::physical::Enemy")
					{
						updatePosition(m_physicals.at(i), collider);
						return true;
					}

					if (typ == "class acodemia::physical::Player")
					{
						updatePosition(m_physicals.at(i), collider);
						return true;
					}

					if (typ == "class acodemia::physical::Bullet")
					{
						m_physicals.at(i)->setHealt
						(
							m_physicals.at(i)->getHealt() - static_cast<Bullet*>(collider)->getCaliber()
						);
						collider->setDestruction(true);
						return true;
					}
				}

				//ostatecznie w ipdatePhysical wolać te funkcję, a poniżze do lamusza?
			}
		}
	}
	return false;
}

//Metoda sprawdza, czy nastąpiła kolizja z Enemy
bool PhysicalManager::checkEnemyCollision(Physical *collider)
{
	std::string typ = typeid(*collider).name();

	for (unsigned int i = 0; i < m_physicals.size(); i++)
	{
		//sf::Vector2f new_position;
		//sf::Vector2f old_position;

		if (m_physicals.at(i) != collider) //blokujemy kolizję "sam ze sobą"
		{
			//updatePosition(m_physicals.at(i), collider);
			//old_position = m_physicals.at(i)->getPosition();
			//
			////x
			//if (m_physicals.at(i)->getPosition().x <= collider->getPosition().x)
			//	new_position.x = old_position.x - 0.1f;
			//else
			//	new_position.x = old_position.x + 0.1f;

			////y
			//if (m_physicals.at(i)->getPosition().y <= collider->getPosition().y)
			//	new_position.y = old_position.y - 0.1f;
			//else
			//	new_position.y = old_position.y + 0.1f;


			if (m_physicals.at(i)->getGlobalBounds().intersects(collider->getGlobalBounds()))
			{
				if (typ == "class acodemia::physical::Enemy")
				{
					updatePosition(m_physicals.at(i), collider);
					std::cout << "Kolizja z Enemy..." << std::endl;
					//m_physicals.at(i)->setPosition(new_position);
					//m_physicals.at(i)->setDestruction(true);
					return true;
				}
				
			}
		}
	}
	//std::cout << " " << std::endl;
	return false;
}

/////////////
///
///Metoda sprawdza, czy nastąpiła kolizja z PLayer
///
///@param *collider - wskaźnik na obiekt klasy Physical
///
bool PhysicalManager::checkPlayerCollision(Physical *collider)
{
	std::string typ = typeid(*collider).name();

	for (unsigned int i = 0; i < m_physicals.size(); i++)
	{
		//sf::Vector2f new_position;
		//sf::Vector2f old_position;

		if (m_physicals.at(i) != collider) //blokujemy kolizję "sam ze sobą"
		{
			//old_position = m_physicals.at(i)->getPosition();

			////x
			//if (m_physicals.at(i)->getPosition().x <= collider->getPosition().x)
			//	new_position.x = old_position.x - 0.1f;
			//else
			//	new_position.x = old_position.x + 0.1f;

			////y
			//if (m_physicals.at(i)->getPosition().y <= collider->getPosition().y)
			//	new_position.y = old_position.y - 0.1f;
			//else
			//	new_position.y = old_position.y + 0.1f;


			if (m_physicals.at(i)->getGlobalBounds().intersects(collider->getGlobalBounds()))
			{
				if (typ == "class acodemia::physical::Player")
				{
					updatePosition(m_physicals.at(i), collider);
					std::cout << "Kolizja z Player..." << std::endl;
					//m_physicals.at(i)->setPosition(new_position);
					//m_physicals.at(i)->setDestruction(true);
					return true;
				}

			}
		}
	}
	//std::cout << " " << std::endl;
	return false;

}


////////////



//Metoda sprawdza, czy nastąpiła kolizja z Bullet
bool PhysicalManager::checkBulletCollision(Physical *collider)
{
	std::string typ = typeid(*collider).name();

	//sprawdzam, które elementy z listy kolidują z lecącym pociskiem
	for (unsigned int i = 0; i < m_physicals.size(); i++)
	{
		if (m_physicals.at(i) != collider)//blokujemy kolizję "sam ze sobą"
		{
			if (m_physicals.at(i)->getGlobalBounds().intersects(collider->getGlobalBounds()))
			{
				//kolizja z Bullet zabija...
				if (typ == "class acodemia::physical::Bullet")
				{
					
					float healt = m_physicals.at(i)->getHealt();
					float damage = static_cast<Bullet*>(collider)->getCaliber();
					
					std::cout << healt << std::endl;
					std::cout << damage << std::endl;
					//std::cout << x << std::endl;
					//healt = healt - damage;

					m_physicals.at(i)->setHealt(healt - damage);
					//pocisk ginie - bo inaczej jak leci przez ofiarę to jej zabiera życie...!!
					collider->setDestruction(true);
					
					//std::cout << damage << std::endl;
					//m_physicals.at(i)->setHealt(m_physicals.at(i)->getHealt() - static_cast<Bullet*>(collider)->getCaliber());
					//std::cout << m_physicals.at(i)->getHealt() << std::endl;

					//std::cout << dynamic_cast<Actor*>(collider)->getBulletCaliber() << std::endl;
					std::cout << "Kolizja z Bullet..." << std::endl;
					//m_physicals.at(i)->setDestruction(true);
					return true;
				}
			}
		}
	}
	//std::cout << " " << std::endl;
	return false;
}


//Szablon metody tworzenia obiektów
template<class T>
T* PhysicalManager::Create()
{
	T* obj = new T();
	m_physicals.push_back(obj);
	return obj;
}

//Metoda aktualizuje pozycję obiektu w wyniku kolizji
void PhysicalManager::updatePosition(Physical *object, Physical *collider) const
{
	//uporządkować...
	sf::Vector2f new_position;
	sf::Vector2f old_position;
	old_position = object->getPosition();

	sf::Vector2f new_collider_position;
	sf::Vector2f old_collider_position;
	old_collider_position = collider->getPosition();

	//x
	if (object->getPosition().x <= collider->getPosition().x)
	{
		new_position.x = old_position.x - 0.1f;
		new_collider_position.x = old_collider_position.x + 0.1f;
	}
	else
	{
		new_position.x = old_position.x + 0.1f;
		new_collider_position.x = old_collider_position.x - 0.1f;
	}

	//y
	if (object->getPosition().y <= collider->getPosition().y)
	{
		new_position.y = old_position.y - 0.1f;
		new_collider_position.y = old_collider_position.y + 0.1f;
	}
	else
	{
		new_position.y = old_position.y + 0.1f;
		new_collider_position.y = old_collider_position.y - 0.1f;
	}

	object->setPosition(new_position);
	collider->setPosition(new_collider_position);
}