//
//acodemia.pl
//

#ifndef H_PHYSICAL_ACODEMIA
#define H_PHYSICAL_ACODEMIA

#include "../../rendering/Displayable.h"

using namespace acodemia::rendering;

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
			Physical();
			virtual ~Physical();

		protected:


		private:

			Displayable		m_displayable;		//reprezentacja graficzna
			bool			m_destruction;		//flaga destrukcji
			bool			m_use_displayable;	//flaga okre�la, czy obiekt posiada reprezentacj� graficzn�
			sf::Vector2f	m_speed;			//wektor pr�dko�ci obiektu
			sf::Vector2f	m_position;			//wektor pozycji
			float			m_rotation;			//warto�� obrotu
			sf::Vector2f	m_origin;			//wektor uchwytu obiektu
			sf::Vector2f	m_scale;			//skala
			sf::Color		m_color;			//kolor obiektu
											
			//sf::Transformable m_transformable; // czy to b�dzie potrzebne?
			//	position
			//	rotation
			//	origin
			//	scale

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