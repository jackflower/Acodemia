//acodemia.pl

#include "PhysicalManager.h"
#include "../physicals/physical/Physical.h"
using namespace acodemia::physical;

PhysicalManager::PhysicalManager()
{
	//2018-11-09
	// to do...
}

PhysicalManager::~PhysicalManager()
{
	//2018-11-09
	// to do...
}

//Metoda zwraca stałą referencję do kontenera z wszystkimi wskaźnikami zarejestorwanych obiektów CPhysical
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
