////////////////////////////////////////////////////////////
//
// Acodemia Copyright (C) Jacek Kwiatek
// e-mail: jackflower (at) poczta.onet.pl
// acodemia.pl
//
// To oprogramowanie dostarczane jest w postaci takiej,
// w jakiej jest, bez wyra�nych ani domniemanych gwarancji.
//
// W �adnym wypadku Autor nie ponosi odpowiedzialno�ci
// za jakiekolwiek szkody powsta�e w wyniku korzystania
// z tego oprogramowania.Zastrzega
//
// Zezwala si� na korzystanie z tego oprogramowania
// w dowolnym celu, tak�e komercyjnym. Mo�na je zmieni�
// i swobodnie rozpowszechnia�.
//
// Zastrzega si� nast�puj�ce ograniczenia:
//
// 1. Je�li u�ywasz tego oprogramowania w swoich
//    produktach, potwierdzenie pochodzenia tego
//    oprogramowania w dokumentacji produktu,
//    by�oby docenione, ale nie jest wymagane.
//
////////////////////////////////////////////////////////////

#ifndef H_GUN_ACODEMIA
#define H_GUN_ACODEMIA

#include "../physical/Physical.h"
#include "../../rendering/Texture.h"

using namespace acodemia::rendering;

namespace acodemia
{
	namespace physical
	{
		///
		///Klasa reprezentuje obiekt strzelaj�cy
		///
		class Gun : public Physical
		{
		public:

			///
			///Konstruktor domy�lny
			///
			Gun();

			///
			///Konstruktor kopiuj�cy
			///
			///@param &copy - sta�a referencja na obiekt klasy Gun
			///
			Gun(const Gun & copy);

			///
			///Konstruktor przenosz�cy
			///
			///@param &&other = referencja do r-warto�ci
			///
			Gun(Gun && other);

			///
			///Destruktor
			///
			~Gun();

			///
			///Przeci��ony operator przypisania kopiowania
			///
			///@param &copy - sta�a referencja na obiekt klasy Gun
			///
			Gun & operator=(const Gun & copy);

			///
			///Przeci��ony operator przypisania przenoszenia
			///
			///@param &&other -  referencja do r-warto�ci
			///
			Gun & operator=(Gun && other);

			///
			///Metoda ustawia wska�nik na tekstur� dla kontekstu graficznego pocisku
			///
			///@param *texture - wska�nik na obiekt klasy Texture
			///
			void setBulletTexture(Texture * texture);

			///
			///Metoda generuje strza�
			///
			///@param &owner - sta�a referencja na obiekt b�d�cy w�a�cicielem dzia�a
			///
			void shoot(const Physical & owner);

			///
			///Metoda aktualizuj�ca obiekt
			///
			///@param dt - czas
			///
			void update(float dt);

		private:

			Texture * p_bullet_texture;//wska�nik na tekstur� pociski
			float m_shoot_timer;//timer strzelanie - dzia�o generuje pocisk co jaki� czas
			float m_elapsed_time;//up�ywaj�cy czas
			bool m_shoot_enabled;//flaga, czy mo�na odda� strza�
			float m_bullet_speed;//pr�dko�� pocisku
			sf::Vector2f m_bullet_start_position;//wyliczana pozycja startowa pocisku

		};
	}//namespace physical
}// namespace acodemia

#endif//H_GUN_ACODEMIA
