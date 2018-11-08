//
//acodemia.pl
//

#ifndef H_PHYSICAL_MANAGER_ACODEMIA
#define H_PHYSICAL_MANAGER_ACODEMIA

#include "SFML/Graphics.hpp"
#include "../utilities/Singleton.h"
#include <vector>

namespace acodemia
{
	namespace physical
	{
		class Physical;
	}
}

//class acodemia::physical::Physical;
using namespace acodemia::physical;

#define gPhysicalManager PhysicalManager::getSingleton()

///
///Klasa reprezentuje fabrykę produkującą obiekty gry,
///zarządzanie obiektami, dziedziczy po szablonie,
///który jest wzorcem singletona - jest Singletonem
///
class PhysicalManager : public Singleton<PhysicalManager>
{
public:

	///
	///Konstruktor domyślny
	///
	PhysicalManager();

	///
	///Destruktor
	///
	~PhysicalManager();

	///
	///Metoda zwraca stała referencję do kontenera z wszystkimi wskaźnikami zarejestorwanych obiektów CPhysical
	///
	const std::vector<Physical*> & getPhysicals();

	///
	///Metoda rejestruje w kontenerze wskaźniki na obiekty Physical
	///
	///@param * physical - wskaźnik na obiekt Physical
	///
	void registerPhysical(Physical * physical);

	///
	///Metoda aktualizuje  wskaźniki na obiekty Physical
	///
	///@param dt - czas
	///
	void updatePhysical(float dt);

	///
	///Wirtualna metoda rysująca obiekt
	///
	///@param & render - kontekst graficzny
	///
	virtual void draw(sf::RenderWindow & render) const;

private:

	std::vector<Physical*> m_physicals;		//kontener <vector> na wskaźniki na obiekty klasy CPhysical
};

#endif//H_PHYSICAL_MANAGER_ACODEMIA