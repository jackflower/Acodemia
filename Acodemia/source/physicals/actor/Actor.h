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
			///Konstruktor domy�lny
			///
			Actor();

			///
			///Konstruktor kopiuj�cy
			///
			///@param &copy - sta�a referencja na obiekt klasy Actor
			///
			Actor(const Actor & copy);

			///
			///Konstruktor przenosz�cy
			///
			///@param &&other = referencja do r-warto�ci
			///
			Actor(Actor && other);

			///
			///Destruktor wirtualny
			///
			virtual ~Actor();

			///
			///Przeci��ony operator przypisania kopiowania
			///
			///@param &copy - sta�a referencja na obiekt klasy Actor
			///
			Actor & operator=(const Actor & copy);

			///
			///Przeci��ony operator przypisania przenoszenia
			///
			///@param &&other -  referencja do r-warto�ci
			///
			Actor & operator=(Actor && other);

			///
			///Wirtualna metoda aktualizuj�ca obiekt
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