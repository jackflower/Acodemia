//acodemia.pl

#include "PhysicalManager.h"
#include "../physicals/physical/Physical.h"
using namespace acodemia::physical;


PhysicalManager::PhysicalManager()
{
}

PhysicalManager::~PhysicalManager()
{
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
	std::vector<Physical*>::iterator it;//iterator tego kontenera
	std::vector<Physical*> dirty;		//kontener na obiekty do zniszczenia
	//implementację dopisać potem (w main muszą być wskaźniki
	//najlepiej jakby fabryka tworzyła Physical'e

	for (it = m_physicals.begin(); it != m_physicals.end(); it++)
	{
		if ((*it)->getDestruction())			//jeśli obiekt jest gotowy do zniszczaenia
			dirty.push_back(*it);					//wstawiamy go do kontenera "śmierci"
	}
}


//Wirtualna metoda rysująca obiekt
void PhysicalManager::draw(sf::RenderWindow & render) const
{
	std::vector<Physical*>::const_iterator it;//iterator tego kontenera
	for (it = m_physicals.begin(); it != m_physicals.end(); it++)
		if ((*it)->getUseDisplayable())
			(*it)->draw(render);
}
