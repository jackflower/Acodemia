//
//acodemia.pl
//

#define gPhysicalManager PhysicalManager::getSingleton()

///
///Szablon reprezentuje wzorzec Singleton
///
template <typename T> class Singleton
{
protected:

	///
	///Konstruktor
	///
	Singleton()
	{
	}

	///
	///Destruktor wirtualny
	///
	virtual ~Singleton()
	{
	}

public:
	static T & getSingleton()
	{
		static T m_singleton;
		return m_singleton;
	}
};
