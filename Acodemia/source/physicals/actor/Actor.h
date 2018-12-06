﻿////////////////////////////////////////////////////////////
//
// Acodemia Copyright (C) Jacek Kwiatek
// e-mail: jackflower (at) poczta.onet.pl
// acodemia.pl
//
// To oprogramowanie dostarczane jest w postaci takiej,
// w jakiej jest, bez wyraźnych ani domniemanych gwarancji.
//
// W żadnym wypadku Autor nie ponosi odpowiedzialności
// za jakiekolwiek szkody powstałe w wyniku korzystania
// z tego oprogramowania.Zastrzega
//
// Zezwala się na korzystanie z tego oprogramowania
// w dowolnym celu, także komercyjnym. Można je zmienić
// i swobodnie rozpowszechniać.
//
// Zastrzega się następujące ograniczenia:
//
// 1. Jeśli używasz tego oprogramowania w swoich
//    produktach, potwierdzenie pochodzenia tego
//    oprogramowania w dokumentacji produktu,
//    byłoby docenione, ale nie jest wymagane.
//
////////////////////////////////////////////////////////////


#ifndef H_ACTOR_ACODEMIA
#define H_ACTOR_ACODEMIA

#include "../physical/Physical.h"
#include "../gun/Gun.h"

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
			///Konstruktor domyślny
			///
			Actor();

			///
			///Konstruktor kopiujący
			///
			///@param &copy - stała referencja na obiekt klasy Actor
			///
			Actor(const Actor & copy);

			///
			///Konstruktor przenoszący
			///
			///@param &&other = referencja do r-wartości
			///
			Actor(Actor && other);

			///
			///Destruktor wirtualny
			///
			virtual ~Actor();

			///
			///Przeciążony operator przypisania kopiowania
			///
			///@param &copy - stała referencja na obiekt klasy Actor
			///
			Actor & operator=(const Actor & copy);

			///
			///Przeciążony operator przypisania przenoszenia
			///
			///@param &&other -  referencja do r-wartości
			///
			Actor & operator=(Actor && other);

			///
			///Metoda ustawia teksturę dla kontekstu graficznego pocisku
			///
			///@param &texture - stała referencja na obiekt klasy Texture
			///
			void setBulletTexture(const Texture & texture);

			///
			///Wirtualna metoda aktualizująca obiekt
			///
			///@param dt - czas
			///
			virtual void update(float dt);

		protected:

			//Chroniona wirtualna metoda - strzał
			virtual void shoot();
		
		private:
			Gun gun;//działo...
			

		};
	}//namespace physical
}//namespace acodemia

#endif//H_ACTOR_ACODEMIA