//
//acodemia.pl
//

#ifndef H_PHYSICAL_ACODEMIA
#define H_PHYSICAL_ACODEMIA

#include "../../rendering/Displayable.h"

using namespace acodemia::rendering;

//uporz�dkowa� bajzel...

namespace acodemia
{
	namespace physical
	{
		///
		///Klasa reprezentuje behawioralne cechy fizyczne i logiczne
		///
		class Physical
		{

		public:

			///
			///Konstruktor domy�lny
			///
			Physical();

			///
			///Konstruktor kopiuj�cy
			///

			///
			///Konstruktor przenosz�cy
			///

			///
			///Destruktor wirtualny
			///
			virtual ~Physical();

			///
			///Przeci��ony operator przypisania kopiowania
			///
			///@param & copy - sta�a referencja na obiekt klasy Physical
			///
			//Physical & operator=(const Physical & copy);

			///
			///Przeci��ony operator przypisania przenoszenia
			///
			///@param && other -  referencja do r-warto�ci
			///
			//Physical & operator=(Physical && other);


			//sets, gets...

			void setUseDisplayable(bool use_displayable);
			Displayable & getDisplayable();

			///
			///Metoda ustawia tekstur� dla kontekstu graficznego
			///
			///@param & texture - sta�a referencja na obiekt klasy Texture
			///
			void setTexture(const Texture & texture);

			virtual void update(float dt);
			virtual void draw(sf::RenderWindow & render);

		protected:

			Displayable m_displayable;	//reprezentacja graficzna
			bool m_destruction;			//flaga destrukcji
			bool m_use_displayable;		//czy jest reprezentacja graficzna
			sf::Vector2f m_position;	//wektor pozycji
			float m_rotation;			//warto�� obrotu
			sf::Vector2f m_origin;		//wektor uchwytu obiektu
			sf::Vector2f m_scale;		//skala
			sf::Color m_color;			//kolor obiektu
											
			//sf::Transformable m_transformable; // czy to b�dzie potrzebne?
			//	position
			//	rotation
			//	origin
			//	scale
			
		private:

		};
	}//namespace physical
}//namespace acodemia

#endif//H_PHYSICAL_ACODEMIA


/*
// P h y s i c a l
//float					m_circle_radius;			//promie� detekcji kolizji
//ECollisionShape		m_collision_shape;			//wyliczenie - typ detekcji kolizji
//sf::Vector2f			m_rect_size;				//wektor przechowuj�cy rozmiar obszaru prostok�tnego

//Wirtualna metoda ustawiaj�ca warto�� promienia detekcji wykorzystywan� przy liczeniu kolizji
void CPhysical::SetBoundingCircle(float radius)
{
	m_collision_shape = SHAPE_CIRCLE;
	m_circle_radius = radius;
	//obliczamy boki prostok�ta (uproszczenie do kwadratu) wpisanego w okrag
	m_rect_size.x = m_rect_size.y = radius * 2.0f;
}


//Metoda ustawia warto�� obszaru prostok�tnego detekcji wykorzystywany przy liczeniu kolizji
void CPhysical::SetBoundingRect(const sf::Vector2f & rect_size)
{
	m_collision_shape = SHAPE_RECT;
	m_rect_size = rect_size;
	//obliczamy przeciwprostok�tn�, czyli �rednic� okr�gu opisanego na prostok�cie
	m_circle_radius =  sqrtf(rect_size.x * rect_size.x + rect_size.y * rect_size.y);
}


*/