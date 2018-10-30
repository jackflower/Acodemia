#pragma once
#include "../utilities/Singleton.h"
class PhysicalManager : public Singleton<PhysicalManager>
{
public:
	PhysicalManager();
	~PhysicalManager();
	void Alabama();
	void Nebraska();

};

