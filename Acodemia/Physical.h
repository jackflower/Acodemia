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
			//float					m_circle_radius;			//promieñ detekcji kolizji
			//ECollisionShape		m_collision_shape;			//wyliczenie - typ detekcji kolizji
			//sf::Vector2f			m_rect_size;				//wektor przechowuj¹cy rozmiar obszaru prostok¹tnego
			//sf::Vector2f			m_rect_size_body;			//wektor przechowuj¹cy rozmiar obszaru prostok¹tnego - body (wykorzystywany do tworzenia syntetyków)
			//sf::Vector2f			m_rect_size_head;			//wektor przechowuj¹cy rozmiar obszaru prostok¹tnego - head (wykorzystywany do tworzenia syntetyków)
			//CPhysicalTemplate*	p_template;					//wskaŸnik na obiekt klasy CPhysicalTemplate
			//bool					m_ready_for_destruction;	//flaga ustawia obiekty gotowe do destrukcji
			//CPartCollisionData	m_part_collision_data;		//opakowanie informacji o kolidowaniu
			//float					m_new_anim_speed;			//wyliczony wspó³czynnik prêdkoœci odtwarzania animacji

			// P h y s i c a l d a t a
			//CPhysicsData		m_physics_data;				//opakowanie informacji o fizyce
			//bool				m_use_displayable_body;		//flaga okreœla, czy obiekt posiada reprezentacjê graficzn¹ - body
			//bool				m_use_shadow_body;			//flaga okreœla, czy obiekt posiada reprezentacjê graficzn¹ - body - cieñ
			//bool				m_use_displayable_head;		//flaga okreœla, czy obiekt posiada reprezentacjê graficzn¹ - head
			//bool				m_use_shadow_head;			//flaga okreœla, czy obiekt posiada reprezentacjê graficzn¹ - head - cieñ
			//CDisplayable*		p_displayable_body;			//wskaŸnik na obiekt CDisplayable - body (czêœæ zasadnicza)
			//CDisplayable*		p_displayable_body_shadow;	//wskaŸnik na obiekt CDisplayable - body shadow	(cieñ czêœci zasadniczej)
			//CDisplayable*		p_displayable_head;			//wskaŸnik na obiekt CDisplayable - head (czêœæ dodatkowa)
			//CDisplayable*		p_displayable_head_shadow;	//wskaŸnik na obiekt CDisplayable - head shadow (cieñ czêœci dodatkowej)
			//sf::Color			m_color_body;				//kolor obiektu - body
			//sf::Color			m_color_head;				//kolor obiektu - head
			//sf::Color			m_color_stored_body;		//zapamiêtany kolor obiektu
			//sf::Color			m_color_stored_head;		//zapamiêtany kolor obiektu
			//sf::Color			m_color_shadow;				//kolor cienia
			//sf::Vector2f		m_shadow_offset_body;		//wektor przesuniêcia cienia - body
			//sf::Vector2f		m_shadow_offset_head;		//wektor przesuniêcia cienia - head
			//CAnimation*			p_animation_body;			//wskaŸnik na animacjê - body (cienie - taka sama animacja)
			//CAnimation*			p_animation_head;			//wskaŸnik na animacjê - head (cienie - taka sama animacja)
			//float				m_anim_speed_body;			//prêdkoœæ odtwarzania animacji (body)
			//float				m_anim_speed_head;			//prêdkoœæ odtwarzania animacji (head)
			//float				m_stored_anim_speed_body;	//zapamiêtana prêdkoœæ odtwarzania animacji (body)
			//float				m_stored_anim_speed_head;	//zapamiêtana prêdkoœæ odtwarzania animacji (head)
			//int					m_z_index_body;				//indeks warstwy rysowania (body)
			//int					m_z_index_shadow_body;		//indeks warstwy rysowania (body shadow)
			//int					m_z_index_head;				//indeks warstwy rysowania (head)
			//int					m_z_index_shadow_head;		//indeks warstwy rysowania (head shadow)
			//std::string			m_texture_body;				//nazwa tekstury reprezentacji graficznej obiektu - body
			//std::string			m_texture_head;				//nazwa tekstury reprezentacji graficznej obiektu - head
			//CTexture*			p_synthetic_texture;		//wskaŸnik na obiekt klasy CTexture - wykorzytywany przy tworzeniu syntetycznej tekstury
			//sf::Image*			p_synthetic_image;			//wskaŸnik na obiekt klasy sf::Image - wykorzytywany przy tworzeniu syntetycznego obrazu
			//sf::Texture			p_texture;					//obiekt klasy sf::Texture - obiekt pomozniczy

			// P h y s i c s d a t a
			//float				m_weight;				//waga obiektu w kilogramach SI
			//sf::Vector2f		m_position;				//wektor pozycji
			//sf::Vector2f		m_old_position;			//wektor pozycji (przed aktualizacj¹)
			//sf::Vector2f		m_velocity;				//wektor prêdkoœci obiektu
			//float				m_altitude;				//wartoœæ pu³apu obiektu wzglêdem pod³o¿a
			//float				m_init_height;			//wyliczona wirtualna wysokoœæ obiektu
			//sf::Vector2f		m_stored_scale_body;	//zapamiêtana skala - pole pomocniczne - body
			//sf::Vector2f		m_stored_scale_head;	//zapamiêtana skala - pole pomocniczne - head
			//float				m_rotation_uniform;		//wartoœæ obrotu (body and head)
			//float				m_rotation_body;		//wartoœæ obrotu (body)
			//float				m_rotation_head;		//wartoœæ obrotu (head)

														//docelowo pogrupowaæ funkcjonalnoœci
														//fizyka do wrapper'a sf::Transformable
			//sf::Transformable	m_transformable_data;	//opakowanie skali i rotacji (na razie nieaktywowane)...
														//przygotowaæ opakowanie sf::Transformable,
														//w których bêd¹ przechowywane dane transformacji:
														//	position
														//	rotation
														//	origin
														//	scale
														//odpowiednio dla sk³adowych CPhysical (obiekt sk³ada siê z elementów)


		private:

			acodemia::rendering::Displayable m_displayable;
			sf::Transformable m_transformable;
			//bool				m_smooth; - gdzie to umieœciæ???

			//CPhysicalData		m_physical_data;			//opakowanie funkcjonalnoœci klasy CPhysical
			//bool				m_smooth;					//flaga, czy obiekt wyg³adza piksele tekstury
			//static float		m_increase;					//wspó³czynnik wirtualnej wysokoœci obiektu

		};
	}//namespace physical
}//namespace acodemia

#endif//H_PHYSICAL_ACODEMIA


/*

//Wirtualna metoda ustawiaj¹ca wartoœæ promienia detekcji wykorzystywan¹ przy liczeniu kolizji
void CPhysical::SetBoundingCircle(float radius)
{
m_collision_shape = SHAPE_CIRCLE;
m_circle_radius = radius;
//obliczamy boki prostok¹ta (uproszczenie do kwadratu) wpisanego w okrag
m_rect_size.x = m_rect_size.y = radius * 2.0f;
}


//Metoda ustawia wartoœæ obszaru prostok¹tnego detekcji wykorzystywany przy liczeniu kolizji
void CPhysical::SetBoundingRect(const sf::Vector2f & rect_size)
{
m_collision_shape = SHAPE_RECT;
m_rect_size = rect_size;
//obliczamy przeciwprostok¹tn¹, czyli œrednicê okrêgu opisanego na prostok¹cie
m_circle_radius =  sqrtf(rect_size.x * rect_size.x + rect_size.y * rect_size.y);
}


*/