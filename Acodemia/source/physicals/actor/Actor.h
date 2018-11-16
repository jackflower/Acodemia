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


#ifndef H_ACTOR_ACODEMIA
#define H_ACTOR_ACODEMIA

#include "../physical/Physical.h"

namespace acodemia
{
	namespace physical
	{
		///
		///Klasa reprezentuje aktora
		///
		class Actor : public Physical
		{
		public:

			///
			///Konstruktor domyœlny
			///
			Actor();

			///
			///Konstruktor kopiuj¹cy
			///
			///@param &copy - sta³a referencja na obiekt klasy Actor
			///
			Actor(const Actor & copy);

			///
			///Konstruktor przenosz¹cy
			///
			///@param &&other = referencja do r-wartoœci
			///
			Actor(Actor && other);

			///
			///Destruktor wirtualny
			///
			virtual ~Actor();

			///
			///Przeci¹¿ony operator przypisania kopiowania
			///
			///@param &copy - sta³a referencja na obiekt klasy Actor
			///
			Actor & operator=(const Actor & copy);

			///
			///Przeci¹¿ony operator przypisania przenoszenia
			///
			///@param &&other -  referencja do r-wartoœci
			///
			Actor & operator=(Actor && other);

			///
			///Wirtualna metoda aktualizuj¹ca obiekt
			///
			///@param dt - czas
			///
			virtual void update(float dt);

		protected:
		private:

		};
	}//namespace physical
}//namespace acodemia

#endif//H_ACTOR_ACODEMIA