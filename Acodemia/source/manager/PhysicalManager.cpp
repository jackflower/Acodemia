//acodemia.pl

#include "PhysicalManager.h"
#include "../physicals/physical/Physical.h"
using namespace acodemia::physical;


PhysicalManager::PhysicalManager()
{
	//testy...
	physical_1 = new Physical();
	physical_2 = new Physical();
	physical_3 = new Physical();

	physical_1->setDestruction(true);
	physical_2->setDestruction(false);
	physical_3->setDestruction(true);

	m_physicals.push_back(physical_1);
	m_physicals.push_back(physical_2);
	m_physicals.push_back(physical_3);
}

PhysicalManager::~PhysicalManager()
{
	//testy...
	delete physical_1;
	delete physical_2;
	delete physical_3;
	physical_1 = nullptr;
	physical_2 = nullptr;
	physical_3 = nullptr;
}

//Metoda zwraca stałą referencję do kontenera z wszystkimi wskaźnikami zarejestorwanych obiektów CPhysical
const std::vector<Physical *> & PhysicalManager::getPhysicals()
{
	return m_physicals;
}
void PhysicalManager::Alabama()
{
	//
}

void PhysicalManager::Nebraska()
{
	//
}