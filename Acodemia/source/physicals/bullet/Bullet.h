////////////////////////////////////////////////////////////
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
// z tego oprogramowania.
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

#ifndef H_BULLET_ACODEMIA
#define H_BULLET_ACODEMIA

#include "SFML/Graphics.hpp"
#include "../physical/Physical.h"

namespace acodemia
{
	namespace physical
	{
		///
		///Klasa reprezentje pocisk
		///
		class Bullet : public Physical
		{
		public:

			///
			///Konstruktor domyślny
			///
			Bullet();

			///
			///Konstruktor kopiujący
			///
			///@param & copy - stała referencja na obiekt klasy Bullet
			///
			Bullet(const Bullet & copy);

			///
			///Konstruktor przenoszący
			///
			///@param && other = referencja do r-wartości
			///
			Bullet(Bullet && other);

			///
			///Destruktor wirtualny
			///
			virtual ~Bullet();

			///
			///Przeciążony operator przypisania kopiowania
			///
			///@param & copy - stała referencja na obiekt klasy Bullet
			///
			Bullet & operator=(const Bullet & copy);

			///
			///Przeciążony operator przypisania przenoszenia
			///
			///@param && other -  referencja do r-wartości
			///
			Bullet & operator=(Bullet && other);

			///
			///Metoda zwraca stałą referencję na wektor kierunku
			///
			const sf::Vector2f & getMotion() const;

			///
			///Metoda ustawia wektor kierunku
			///
			///@param const & motion - stała referencja na obiekt klasy sf::Vector2f
			///
			void setMotion(const sf::Vector2f & motion);

			///
			///Metoda ustawia wektor kierunku
			///
			///@param x - składowa X wektora kierunku
			///
			//////@param y - składowa Y wektora kierunku
			///
			void setMotion(float x, float y);

			///
			///Metoda zwraca prędkość pocisku
			///
			const float getSpeed() const;

			///
			///Metoda ustawia prędkość pocisku
			///
			///@param speed - prędkość pocisku
			///
			void setSpeed(float speed);

			///
			///Metoda zwraca kaliber pocisku
			///
			const float getCaliber() const;

			///
			///Metoda ustawia kaliber pocisku
			///
			///@param caliber - kaliber pocisku
			///
			void setCaliber(float caliber);

			///
			///Metoda zwraca czas życia pocisku
			///
			const float getLifeTime() const;

			///
			///Metoda ustawia czas życia pocisku
			///
			///@param lifetime - czas życia pocisku
			///
			void setLifeTime(float lifetime);

			///
			///Wirtualna metoda aktualizująca obiekt
			///
			///@param dt - czas
			///
			virtual void update(float dt);

		private:

			sf::Vector2f m_motion; //wektor kierunku pocisku
			float m_speed; //prędkość pocisku
			float m_caliber; //kaliber - siła rażenia
			float m_lifetime; //czas życia pocisku
			float m_elapsedtime; //upływający czas
		};

	}//namespace physical
}//namespace acodemia
#endif//H_BULLET_ACODEMIA
