//
//acodemia.pl
//

#ifndef H_ANIMATED_ACODEMIA
#define H_ANIMATED_ACODEMIA
 
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "../rendering/Sprite.h"

namespace acodemia
{
	namespace animation
	{
		///
		///Klasa reprezentuje animowany obiekt
		///
		class Animated : public acodemia::rendering::Sprite
		{
		public:

			///
			///Konstruktor domyślny
			///
			Animated();

			///
			///Konstruktor kopiujący
			///
			///@param & copy - parametr - obiekt klasy Animated
			///
			Animated(const Animated & copy);

			///
			///Konstruktor przenoszący
			///
			///@param && other = referencja do r-wartości
			///
			Animated(Animated && other);

			///
			///Konstruktor parametryczny
			///
			///@param p_animation - wskaźnik na obiekt klasy Animation (animacja)
			///
			///@param play - tryb Pause/Play
			///
			///@param loop - tryb Loop
			///
			///@param time - czas ekspozycji klatki
			///
			Animated(Animation* p_animation, bool play = true, bool Loop = true, float time = 0.f);

			///
			///Destruktor
			///
			 ~Animated();

			///
			///Przeciążony operator przypisania kopiowania
			///
			///@param & copy - stała referencja na obiekt klasy Displayable
			///
			///Displayable & operator=(const Displayable & copy);

			///
			///Przeciążony operator przypisania przenoszenia
			///
			///@param && other -  referencja do r-wartości
			///
			///Displayable & operator=(Displayable && other);


			 // r e f a k t o r y z a c j a

			///
			///Metoda zwraca wskaźnik na obiekt klasy Animation
			///
			Animation* getAnimation() const;

			///
			///Metoda ustawia wskaźnik na obiekt klasy Animation
			///
			///@param animated - wskaźnik na obiekt klasy Animation (animacja)
			///
			///@param playmode - tryb Pause/Play
			///
			void setAnimation(Animation* animated, bool playmode = false);

			///
			///Metoda wyrejestrowuje animację - obiekt klasy Animation
			///
			void unsetAnim();

			///
			///Metoda zwraca numer aktualnej klatki animacji obiektu klasy Animation
			///
			const int getCurrentFrame() const;

			///
			///Metoda ustawia numer klatki animacji obiektu klasy Animation
			///
			///@param frame - klatka animacji
			///
			void setFrame(int frame);

			///
			///Metoda zwraca czas ekspozycji klatki animacji obiektu klasy Animation
			///
			const float getFrameTime() const;

			///
			///Metoda ustawia czas ekspozycji klatki animacji obiektu klasy Animation
			///
			///@param time - czas ekspozycji klatki animacji
			///
			void setFrameTime(float time);

			///
			///Metoda zwraca tryb pause animacji
			///
			const bool getPaused() const;

			///
			///Metoda ustwia tryb pause animacji
			///
			///@param paused - tryb pause
			///
			const void setPaused(bool paused);

			///
			///Metoda sprawdza czy ustawiony jest tryb Loop
			///
			const bool isLoop() const;

			///
			///Metoda ustawiająca tryb Loop animacji
			///
			///@param loop - tryb Loop
			///
			const void setLoop(bool loop);

			///
			///Metoda zatrzymuje odtwarzanie animacji
			///
			void pause();

			///
			///Metoda uruchamia animację
			///
			void play();

			///
			///Metoda zatrzymuje animację
			///
			void stop();

			///
			///Metoda sprawdza, czy animacja jest w trybie Pause
			///
			const bool isPaused() const;

			///
			///Metoda sprawdza, czy animacja jest zatrzymana
			///
			const bool isStoped() const;

			///
			///Metoda aktualizuje animację
			///
			///@param elapsed_time - czas
			///
			void update(float elapsed_time);

			///
			///Metoda zwraca numer ostatnio wyświetlanej klatki animacji
			///
			const int getLastAnimFrame() const;

			///
			///Metoda zwraca ilość klatek animacji
			///
			const int getAnimSize() const;

			///
			///Metoda zwraca flagę standardowej konfiguracji animacji
			///
			//const bool getAnimMode() const;

			///
			///Metoda zwraca stałą, zdefiniowaną statycznie wartość ekspozycji klatki animacji
			///
			//const float getDefaultFrameTime() const;

			///
			///Metoda renderująca obiekt klasy Animated
			///
			///@render render - kontekst graficzny
			///
			virtual void draw(sf::RenderWindow* render);

		protected:

			float				m_time;					//czas ekspozycji klatki
			float				m_elapsedtime;			//czas upływający
			bool				m_paused;				//tryb Pause
			bool				m_loop;					//tryb Loop
			Animation*			p_animation;			//wskaźnik na obiekt klasy Animation (animacja)
			int					m_currentframe;			//bieżąca klatka animacji
			int					m_lastanimframe;		//klatka, na której zakończyła się animacja

			static const float	m_default_time;			//wartość domyślna czasu ekspozycji klatki animacji
		};
	}//namespace animation
}//namespace acodemia
#endif //H_ANIMATED_ACODEMIA


// //usage
//acodemia::rendering::Texture animation_texture;
//animation_texture.loadFromFile("../data/logo_sci_atlas.png");
//acodemia::animation::Animation animacja;
//animacja.setAnimationFramesFromAtlasTexture(animation_texture, 50, 50);
//acodemia::animation::Animated animek;
//animek.setAnimation(&animacja);
//animek.setPosition(700.f, 100.f);
//animek.setFrameTime(0.0125f);
////usage
