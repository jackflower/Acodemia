//
//acodemia.pl
//

#ifndef H_TEXTURE_ACODEMIA
#define H_TEXTURE_ACODEMIA

#include <SFML/Graphics/Texture.hpp>

namespace acodemia
{
	namespace rendering
	{
		///
		///Klasa reprezetuje opakowanie obiektu klasy sf::Texture
		///
		class Texture : public sf::Texture
		{
		public:

			///
			///Konstruktor
			///
			Texture();

			///
			///Konstruktor kopiujący
			///
			///@param & copy - stała referencja na obiekt klasy Texture
			///
			Texture(const Texture & copy);

			///
			///Konstruktor przenoszący
			///
			///@param && other = referencja do r-wartości
			///
			Texture(Texture && other);

			///
			///Destruktor
			///
			~Texture();
			
			//To do...
			//przenoszący operator przypisania...
			//klasa& klasa::operator=(klasa &&);

			bool Load(const std::string &file_name);

		};
	}//namespace rendering
}//namespace resource
#endif //H_TEXTURE_ACODEMIA
