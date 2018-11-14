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


#ifndef H_PLAYER_ACODEMIA
#define H_PLAYER_ACODEMIA

#include "../physical/Physical.h"

namespace acodemia
{
	namespace physical
	{
		///
		///Klasa reprezentuje gracza
		///
		class Player : public Physical
		{
		public:

			///
			///Konstruktor domy�lny
			///
			Player();

			///
			///Konstruktor kopiuj�cy
			///
			///@param &copy - sta�a referencja na obiekt klasy Player
			///
			Player(const Player & copy);

			///
			///Konstruktor przenosz�cy
			///
			///@param &&other = referencja do r-warto�ci
			///
			Player(Player && other);

			///
			///Destruktor wirtualny
			///
			virtual ~Player();

			///
			///Przeci��ony operator przypisania kopiowania
			///
			///@param &copy - sta�a referencja na obiekt klasy Player
			///
			Player & operator=(const Player & copy);

			///
			///Przeci��ony operator przypisania przenoszenia
			///
			///@param &&other -  referencja do r-warto�ci
			///
			Player & operator=(Player && other);

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

#endif//H_PLAYER_ACODEMIA