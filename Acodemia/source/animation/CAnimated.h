/*
 ______________________________________
| CAnimated.h - definicja klasy.       |
| SCI - by Jack Flower March 2009.     |
|______________________________________|

*/

#ifndef ANIMATED_JACK
#define ANIMATED_JACK
 
#include "CAnim.h"
#include "../Factory/Creator/Creator_New/CEntity.h"

namespace animation
{

	///
	///Klasa reprezentuje animowany obiekt
	///
	class CAnimated : public CEntity, public sf::Sprite
	{
	public:

		///
		///Konstruktor domy�lny
		///
		CAnimated();

		///
		///Konstruktor parametryczny
		///
		///@param newAnim - wska�nik na obiekt klasy CAnim (animacja)
		///
		///@param Play - tryb Pause/Play
		///
		///@param Loop - tryb Loop
		///
		///@param Time - czas ekspozycji klatki
		///
		CAnimated (CAnim* newAnim, bool Play = true, bool Loop = true, float Time = 0.f);

		///
		///Konstruktor kopiuj�cy
		///
		///@param &CAnimatedCopy - parametr - obiekt klasy CAnimated
		///
		CAnimated(const CAnimated& CAnimatedCopy);

		///
		///Destruktor wirtualny
		///
		virtual ~CAnimated();

		///
		///Metoda zwraca wska�nik na obiekt klasy CAnim
		///
		CAnim* GetAnim() const {return m_anim;}

		///
		///Metoda ustawia wska�nik na obiekt klasy CAnim
		///
		///@param newAnim - wska�nik na obiekt klasy CAnim (animacja)
		///
		///@param _play - tryb Pause/Play
		///
		const void SetAnim(CAnim* newAnim, bool _play = false);

		///
		///Metoda wyrejestrowuje animacj� - obiekt klasy CAnim
		///
		void UnsetAnim();

		///
	    ///Metoda zwraca numer aktualnej klatki animacji obiektu klasy CAnim
		///
		const int GetCurrentFrame() const {return m_currentframe;}

		///
		///Metoda ustawia numer klatki animacji obiektu klasy CAnim
		///
		///@param _frame - klatka animacji
		///
		const void SetFrame(int _frame);

		///
		///Metoda zwraca czas ekspozycji klatki animacji obiektu klasy CAnim
		///
		const float GetFrameTime() const {return m_time;}

		///
		///Metoda ustawia czas ekspozycji klatki animacji obiektu klasy CAnim
		///
		///@param _time - czas ekspozycji klatki animacji
		///
		const void SetFrameTime(float _time);

		///
		///Metoda zwraca tryb pause animacji
		///
		const bool GetPaused() const {return m_paused;}

		///
	    ///Metoda ustwia tryb pause animacji
		///
		///@param _pause - tryb pause
		///
		const void SetPaused(bool _paused);

		///
		///Metoda sprawdza czy ustawiony jest tryb Loop
		///
		const bool IsLoop() {return m_loop;}

		///
		///Metoda ustawiaj�ca tryb Loop animacji
		///
		///@param _loop - tryb Loop
		///
		const void SetLoop(bool _loop);
 
		///
	    ///Metoda zatrzymuje odtwarzanie animacji
		///
		void Pause();
 
		///
		///Metoda uruchamia animacj�
		///
		void Play();
 
		///
		///Metoda zatrzymuje animacj�
		///
		void Stop();
 
		///
		///Metoda sprawdza, czy animacja jest w trybie Pause
		///
		const bool IsPaused() {return m_paused;}

		///
	    ///Metoda sprawdza, czy animacja jest zatrzymana
		///
		const bool IsStoped() {return (m_paused && (m_currentframe == 0) && (m_elapsedtime == m_time));}

		///
	    ///Metoda uruchamia animacj�
		///
		///@_elapsedtime _elapsedtime parametr - czas
		///
	    void Update(float _elapsedtime);
	
		///
		///Metoda pobiera numer ostatnio wy�wietlanej klatki animacji
		///
		const int GetLastAnimFrame() const {return m_lastanimframe;}

		///
		///Metoda zwraca ilo�� klatek animacji
		///
		const int GetAnimSize() const {return m_anim->Size();}

		///
		///Metoda zwraca flag� standardowej konfiguracji animacji
		///
		const bool GetAnimMode() const {return m_default_anim_mode;}

		///
		///Metoda zwraca sta��, zdefiniowan� statycznie warto�� ekspozycji klatki animacji
		///
		const float GetDefaultFrameTime() const { return m_default_time; }

		///
		///Metoda renderuj�ca obiekt klasy CAnimated
		///
		///@render render - parametr drawable
		///
		void Draw(sf::RenderWindow* render);

	protected:

		float				m_time;					//czas ekspozycji klatki
	    float				m_elapsedtime;			//czas up�ywaj�cy
	    bool				m_paused;				//tryb Pause
	    bool				m_loop;					//tryb Loop
	    CAnim*				m_anim;					//wska�nik na obiekt klasy CAnim (animacja)
	    int					m_currentframe;			//bie��ca klatka animacji
		int					m_lastanimframe;		//klatka, na kt�rej zako�czy�a si� animacja
		bool				m_default_anim_mode;	//flaga standardowej konfiguracji trybu animacji
		static const float	m_default_time;			//warto�� domy�lna czasu ekspozycji klatki animacji
	};

}//namespace animation

#endif //ANIMATED_JACK
