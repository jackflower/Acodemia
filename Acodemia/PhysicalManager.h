#pragma once
#include "Singleton.h"
class PhysicalManager : public Singleton<PhysicalManager>
{
public:
	PhysicalManager();
	~PhysicalManager();
	void Alabama();
	void Nebraska();

};

