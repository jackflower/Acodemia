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
using namespace acodemia::physical;

//Konstruktor domyślny
PhysicalManager::PhysicalManager()
:
	m_physicals()
{
}

//Destruktor
PhysicalManager::~PhysicalManager()
{
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
		//jeśli obiekt jest oznaczony do zniszczaenia
		if(m_physicals.at(i)->getDestruction())
		{
			if (m_physicals.at(i))
			{
				delete m_physicals.at(i);
				m_physicals.at(i) = nullptr;
				m_physicals.erase(m_physicals.begin() + i);
			}
		}
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
