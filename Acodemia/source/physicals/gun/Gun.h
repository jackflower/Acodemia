////////////////////////////////////////////////////////////
//
// Acodemia Copyright (C) Jacek Kwiatek
// e-mail: jackflower (at) poczta.onet.pl
// acodemia.pl
//
// To oprogramowanie dostarczane jest w postaci takiej,
// w jakiej jest, bez wyraŸnych ani domniemanych gwarancji.
//
// W ¿adnym wypadku Autor nie ponosi odpowiedzialnoœci
// za jakiekolwiek szkody powsta³e w wyniku korzystania
// z tego oprogramowania.Zastrzega
//
// Zezwala siê na korzystanie z tego oprogramowania
// w dowolnym celu, tak¿e komercyjnym. Mo¿na je zmieniæ
// i swobodnie rozpowszechniaæ.
//
// Zastrzega siê nastêpuj¹ce ograniczenia:
//
// 1. Jeœli u¿ywasz tego oprogramowania w swoich
//    produktach, potwierdzenie pochodzenia tego
//    oprogramowania w dokumentacji produktu,
//    by³oby docenione, ale nie jest wymagane.
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
		///Klasa reprezentuje obiekt strzelaj¹cy
		///
		class Gun : public Physical
		{
		public:

			///
			///Konstruktor domyœlny
			///
			Gun();

			///
			///Konstruktor kopiuj¹cy
			///
			///@param &copy - sta³a referencja na obiekt klasy Gun
			///
			Gun(const Gun & copy);

			///
			///Konstruktor przenosz¹cy
			///
			///@param &&other = referencja do r-wartoœci
			///
			Gun(Gun && other);

			///
			///Destruktor
			///
			~Gun();

			///
			///Przeci¹¿ony operator przypisania kopiowania
			///
			///@param &copy - sta³a referencja na obiekt klasy Gun
			///
			Gun & operator=(const Gun & copy);

			///
			///Przeci¹¿ony operator przypisania przenoszenia
			///
			///@param &&other -  referencja do r-wartoœci
			///
			Gun & operator=(Gun && other);

			///
			///Metoda ustawia wskaŸnik na teksturê dla kontekstu graficznego pocisku
			///
			///@param *texture - wskaŸnik na obiekt klasy Texture
			///
			void setBulletTexture(Texture * texture);

			///
			///Metoda generuje strza³
			///
			///@param &owner - sta³a referencja na obiekt bêd¹cy w³aœcicielem dzia³a
			///
			void shoot(const Physical & owner);

			///
			///Metoda aktualizuj¹ca obiekt
			///
			///@param dt - czas
			///
			void update(float dt);

		private:

			Texture * p_bullet_texture;//wskaŸnik na teksturê pociski
			float m_shoot_timer;//timer strzelanie - dzia³o generuje pocisk co jakiœ czas
			float m_elapsed_time;//up³ywaj¹cy czas
			bool m_shoot_enabled;//flaga, czy mo¿na oddaæ strza³
			float m_bullet_speed;//prêdkoœæ pocisku
			sf::Vector2f m_bullet_start_position;//wyliczana pozycja startowa pocisku

		};
	}//namespace physical
}// namespace acodemia

#endif//H_GUN_ACODEMIA
