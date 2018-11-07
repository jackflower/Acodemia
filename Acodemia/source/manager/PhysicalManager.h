//
//acodemia.pl
//

#ifndef H_PHYSICAL_MANAGER_ACODEMIA
#define H_PHYSICAL_MANAGER_ACODEMIA

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

	//testy
	void Alabama();
	void Nebraska();

	///
	///Metoda zwraca stała referencję do kontenera z wszystkimi wskaźnikami zarejestorwanych obiektów CPhysical
	///
	const std::vector<Physical*> & getPhysicals();

private:

	std::vector<Physical*> m_physicals;		//kontener <vector> na wskaźniki na obiekty klasy CPhysical
	//testy

	Physical * physical_1;
	Physical * physical_2;
	Physical * physical_3;
};

#endif//H_PHYSICAL_MANAGER_ACODEMIA