//acodemia.pl

#include "Texture.h"

namespace acodemia
{
	namespace rendering
	{

		//Konstruktor
		Texture::Texture()
		:
			sf::Texture()//konstruktor klasy bazowej
		{
		}

		//Konstruktor kopiujący
		Texture::Texture(const Texture & copy)
		:
			sf::Texture(copy)//konstruktor kopiujący klasy bazowej
		{
		}


		//Konstruktor przenoszący
		Texture::Texture(Texture && other)
		:
			sf::Texture(other)
		{
		}

		//Destruktor
		Texture::~Texture()
		{
		}

		//Wirtualna metoda ładująca zasób - implementacja
		bool Texture::Load(const std::string &file_name)
		{
			if (loadFromFile(file_name))//jeśli dane zostały załadowane
				return true;			//zwracamy flagę true (ok)
			return false;				//false, jeśli program nie załadował pliku
		}

		////Wirtualna metoda zwalniająca zasób
		//void CTexture::Drop()
		//{
		//	delete this;
		//}
	}//namespace rendering
}//namespace acodemia
