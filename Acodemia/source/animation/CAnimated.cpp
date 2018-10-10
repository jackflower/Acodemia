/*
 ______________________________________
| CAnimated.cpp - implementacja klasy. |
| SCI - by Jack Flower March 2009.     |
|______________________________________|

*/

#include "CAnimated.h"

namespace animation
{

	// Konstruktor domyœlny
	CAnimated::CAnimated()
	:
		sf::Sprite					(),//Konstruktor klasy bazowej
			m_time					(m_default_time),
		    m_elapsedtime			(0),
		    m_paused				(false),
			m_loop					(true),
		    m_anim					(NULL),
			m_currentframe			(0),
			m_lastanimframe			(0),
			m_default_anim_mode		(true)
	{
		SetFrame(0);
		SetCenter(GetSize().x * 0.5f, GetSize().y * 0.5f);
	}

	// Konstruktor parametryczny
	CAnimated::CAnimated (CAnim* newAnim, bool Play, bool Loop, float Time)
	:
		sf::Sprite					(),//Konstruktor klasy bazowej
			m_time					(Time),
		    m_elapsedtime			(Time),
		    m_paused				(!Play),
			m_loop					(Loop),
		    m_anim					(newAnim),
			m_currentframe			(0),
			m_lastanimframe			(0),
			m_default_anim_mode		(true)
	{
		SetFrame(0);
		SetCenter(GetSize().x * 0.5f, GetSize().y * 0.5f);
	}

	//Konstruktor kopiuj¹cy
	CAnimated::CAnimated(const CAnimated& CAnimatedCopy)
	:
		sf::Sprite(CAnimatedCopy),//Konstruktor kopiuj¹cy klasy bazowej
			//Kopiowanie sk³adowych tej klasy
			m_time					(CAnimatedCopy.m_time),
			m_elapsedtime			(CAnimatedCopy.m_elapsedtime),
			m_paused				(CAnimatedCopy.m_paused),
			m_loop					(CAnimatedCopy.m_loop),
			m_anim					(CAnimatedCopy.m_anim),
			m_currentframe			(CAnimatedCopy.m_currentframe),
			m_lastanimframe			(CAnimatedCopy.m_lastanimframe),
			m_default_anim_mode		(CAnimatedCopy.m_default_anim_mode)
	{
	}

	//Destruktor wirtualny
	CAnimated::~CAnimated() 
	{
		m_time					= 0.f;
	    m_elapsedtime			= 0.f;
		m_paused				= false;
		m_loop					= false;
		m_anim					= NULL;
		m_currentframe			= 0;
		m_lastanimframe			= 0;
		m_default_anim_mode		= false;
	}

	//Metoda ustawia wskaŸnik na obiekt klasy CAnim
	const void CAnimated::SetAnim(CAnim* newAnim, bool _play)
	{
		m_anim = newAnim;
		Stop();
		if (_play) Play();
		//Rowi¹zanie alternatywne - niebezpieczne
		//m_lastanimframe = GetCurrentFrame();
		//m_anim = newAnim;
		//SetFrame(m_lastanimframe);
		SetCenter(GetSize().x *0.5f, GetSize().y *0.5f);
	}

	//Metoda wyrejestrowuje animacjê - obiekt klasy CAnim
	void CAnimated::UnsetAnim()
	{
		m_anim = 0;
		Stop();
	}

	//Metoda ustawia numer klatki animacji obiektu klasy CAnim
	const void CAnimated::SetFrame(int _frame)
	{
		if ( m_anim != NULL)
		{
			if (m_anim->Size() > 0)
			{
				if ((*m_anim)[_frame].GetFrameImage() != NULL)
					SetImage(*((*m_anim)[_frame].GetFrameImage()));
	            SetSubRect((*m_anim)[_frame].GetFrameRectangle());
		        SetColor((*m_anim)[_frame].GetFrameColor());
			    m_currentframe = _frame;
			}
		}
	}

	//Metoda ustawia czas ekspozycji klatki animacji obiektu klasy CAnim
	const void CAnimated::SetFrameTime(float _time)
	{
		m_time = _time;
	}

	//Metoda ustwia tryb pause animacji
	const void CAnimated::SetPaused(bool _paused)
	{
		m_paused = _paused;
	}

	//Metoda ustawiaj¹ca tryb Loop animacji
	const void CAnimated::SetLoop(bool _loop)
	{
		m_loop = _loop;
	}

	//Metoda zatrzymuje odtwarzanie animacji
	void CAnimated::Pause()
	{
		m_paused = true;
	}
 
	//Metoda uruchamia animacjê
	void CAnimated::Play()
	{
		m_paused = false;
	}
 
	//Metoda zatrzymuje animacjê
	void CAnimated::Stop()
	{
		SetFrame(0);
		m_elapsedtime = m_time;
		m_paused = true;
	}

	//Metoda uruchamia animacjê
	void CAnimated::Update(float _elapsedtime)
	{
		if (!m_paused && m_anim != NULL)
		{
			m_elapsedtime -= _elapsedtime;
			if (m_elapsedtime <= 0.f)
			{
				m_elapsedtime = m_time;
				if (m_currentframe + 1 < (int)m_anim->Size())
	                m_currentframe++;
		        else
			    {
				    if (m_loop)
					    m_currentframe = 0;
					else
					{
	                    Stop();
		            }
			    }
	            SetFrame(m_currentframe);
		    }
		}
	}

	//Metoda renderuj¹ca obiekt klasy CAnimated
	void CAnimated::Draw(sf::RenderWindow* render)
	{
		render->Draw(*this);
	}

	//Nadanie wartoœci sk³adowej statycznej i sta³ej
	const float CAnimated::m_default_time	= 0.06250f;

}//namespace animation