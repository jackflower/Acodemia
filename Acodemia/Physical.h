//
//acodemia.pl
//

#ifndef H_PHYSICAL_ACODEMIA
#define H_PHYSICAL_ACODEMIA

#include "source/rendering/Displayable.h"

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

			// P h y s i c a l
			//physCategory			m_category;					//kategoria CPhysical
			//std::wstring			m_unique_id;				//unikalny identyfikator (nadawany w CPhysicalManager)
			//std::wstring			m_genre;					//nazwa "gatunku" obiektu (np. robot, human, gun, etc.)
			//float					m_circle_radius;			//promie� detekcji kolizji
			//ECollisionShape		m_collision_shape;			//wyliczenie - typ detekcji kolizji
			//sf::Vector2f			m_rect_size;				//wektor przechowuj�cy rozmiar obszaru prostok�tnego
			//sf::Vector2f			m_rect_size_body;			//wektor przechowuj�cy rozmiar obszaru prostok�tnego - body (wykorzystywany do tworzenia syntetyk�w)
			//sf::Vector2f			m_rect_size_head;			//wektor przechowuj�cy rozmiar obszaru prostok�tnego - head (wykorzystywany do tworzenia syntetyk�w)
			//CPhysicalTemplate*	p_template;					//wska�nik na obiekt klasy CPhysicalTemplate
			//bool					m_ready_for_destruction;	//flaga ustawia obiekty gotowe do destrukcji
			//CPartCollisionData	m_part_collision_data;		//opakowanie informacji o kolidowaniu
			//float					m_new_anim_speed;			//wyliczony wsp�czynnik pr�dko�ci odtwarzania animacji

			// P h y s i c a l d a t a
			//CPhysicsData		m_physics_data;				//opakowanie informacji o fizyce
			//bool				m_use_displayable_body;		//flaga okre�la, czy obiekt posiada reprezentacj� graficzn� - body
			//bool				m_use_shadow_body;			//flaga okre�la, czy obiekt posiada reprezentacj� graficzn� - body - cie�
			//bool				m_use_displayable_head;		//flaga okre�la, czy obiekt posiada reprezentacj� graficzn� - head
			//bool				m_use_shadow_head;			//flaga okre�la, czy obiekt posiada reprezentacj� graficzn� - head - cie�
			//CDisplayable*		p_displayable_body;			//wska�nik na obiekt CDisplayable - body (cz�� zasadnicza)
			//CDisplayable*		p_displayable_body_shadow;	//wska�nik na obiekt CDisplayable - body shadow	(cie� cz�ci zasadniczej)
			//CDisplayable*		p_displayable_head;			//wska�nik na obiekt CDisplayable - head (cz�� dodatkowa)
			//CDisplayable*		p_displayable_head_shadow;	//wska�nik na obiekt CDisplayable - head shadow (cie� cz�ci dodatkowej)
			//sf::Color			m_color_body;				//kolor obiektu - body
			//sf::Color			m_color_head;				//kolor obiektu - head
			//sf::Color			m_color_stored_body;		//zapami�tany kolor obiektu
			//sf::Color			m_color_stored_head;		//zapami�tany kolor obiektu
			//sf::Color			m_color_shadow;				//kolor cienia
			//sf::Vector2f		m_shadow_offset_body;		//wektor przesuni�cia cienia - body
			//sf::Vector2f		m_shadow_offset_head;		//wektor przesuni�cia cienia - head
			//CAnimation*			p_animation_body;			//wska�nik na animacj� - body (cienie - taka sama animacja)
			//CAnimation*			p_animation_head;			//wska�nik na animacj� - head (cienie - taka sama animacja)
			//float				m_anim_speed_body;			//pr�dko�� odtwarzania animacji (body)
			//float				m_anim_speed_head;			//pr�dko�� odtwarzania animacji (head)
			//float				m_stored_anim_speed_body;	//zapami�tana pr�dko�� odtwarzania animacji (body)
			//float				m_stored_anim_speed_head;	//zapami�tana pr�dko�� odtwarzania animacji (head)
			//int					m_z_index_body;				//indeks warstwy rysowania (body)
			//int					m_z_index_shadow_body;		//indeks warstwy rysowania (body shadow)
			//int					m_z_index_head;				//indeks warstwy rysowania (head)
			//int					m_z_index_shadow_head;		//indeks warstwy rysowania (head shadow)
			//std::string			m_texture_body;				//nazwa tekstury reprezentacji graficznej obiektu - body
			//std::string			m_texture_head;				//nazwa tekstury reprezentacji graficznej obiektu - head
			//CTexture*			p_synthetic_texture;		//wska�nik na obiekt klasy CTexture - wykorzytywany przy tworzeniu syntetycznej tekstury
			//sf::Image*			p_synthetic_image;			//wska�nik na obiekt klasy sf::Image - wykorzytywany przy tworzeniu syntetycznego obrazu
			//sf::Texture			p_texture;					//obiekt klasy sf::Texture - obiekt pomozniczy

			// P h y s i c s d a t a
			//float				m_weight;				//waga obiektu w kilogramach SI
			//sf::Vector2f		m_position;				//wektor pozycji
			//sf::Vector2f		m_old_position;			//wektor pozycji (przed aktualizacj�)
			//sf::Vector2f		m_velocity;				//wektor pr�dko�ci obiektu
			//float				m_altitude;				//warto�� pu�apu obiektu wzgl�dem pod�o�a
			//float				m_init_height;			//wyliczona wirtualna wysoko�� obiektu
			//sf::Vector2f		m_stored_scale_body;	//zapami�tana skala - pole pomocniczne - body
			//sf::Vector2f		m_stored_scale_head;	//zapami�tana skala - pole pomocniczne - head
			//float				m_rotation_uniform;		//warto�� obrotu (body and head)
			//float				m_rotation_body;		//warto�� obrotu (body)
			//float				m_rotation_head;		//warto�� obrotu (head)

														//docelowo pogrupowa� funkcjonalno�ci
														//fizyka do wrapper'a sf::Transformable
			//sf::Transformable	m_transformable_data;	//opakowanie skali i rotacji (na razie nieaktywowane)...
														//przygotowa� opakowanie sf::Transformable,
														//w kt�rych b�d� przechowywane dane transformacji:
														//	position
														//	rotation
														//	origin
														//	scale
														//odpowiednio dla sk�adowych CPhysical (obiekt sk�ada si� z element�w)


		private:

			acodemia::rendering::Displayable m_displayable;
			sf::Transformable m_transformable;
			//bool				m_smooth; - gdzie to umie�ci�???

			//CPhysicalData		m_physical_data;			//opakowanie funkcjonalno�ci klasy CPhysical
			//bool				m_smooth;					//flaga, czy obiekt wyg�adza piksele tekstury
			//static float		m_increase;					//wsp�czynnik wirtualnej wysoko�ci obiektu

		};
	}//namespace physical
}//namespace acodemia

#endif//H_PHYSICAL_ACODEMIA


/*

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