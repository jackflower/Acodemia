//acodemia.pl

#include "Sprite.h"

namespace acodemia
{
	namespace rendering
	{
		//Konstruktor
		Sprite::Sprite()
		:
			sf::Sprite()//konstruktor klasy bazowej
		{
		}

		//Konstruktor kopiujący
		Sprite::Sprite(const Sprite & copy)
		:
			sf::Sprite(copy)//konstruktor kopiujący klasy bazowej
		{
		}

		//Konstruktor przenoszący
		Sprite::Sprite(Sprite && other)
		:
			sf::Sprite(other)
		{
		}

		//Destrukror
		Sprite::~Sprite()
		{
		}

		//
		//notatka:
		// prawdopodobnie ten kod do kosza (poprawny w klasie Displayable)
		//
		////Przenoszący operator przypisania
		//Sprite & Sprite::operator=(Sprite && other)
		//{
		//	//std::cout << "In operator=(MemoryBlock&&). length = "
		//	//	<< other._length << "." << std::endl;

		//	if (this != &other)
		//	{
		//		//*this = *other;
		//		// Free the existing resource.  
		//		//delete[] _data;

		//		// Copy the data pointer and its length from the   
		//		// source object.  
		//		//_data = other._data;
		//		//_length = other._length;

		//		// Release the data pointer from the source object so that  
		//		// the destructor does not free the memory multiple times.  
		//		//other._data = nullptr;
		//		//other._length = 0;
		//	}
		//	return *this;
		//}
	}//namespace rendering
}//namespace acodemia
