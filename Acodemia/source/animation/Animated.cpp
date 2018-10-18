//acodemia.pl

#include "Animated.h"

namespace acodemia
{
	namespace animation
	{
		// Konstruktor domyślny
		Animated::Animated()
		:
			Sprite				(), //konstruktor klasy bazowej
			m_time				(m_default_time),
			m_elapsedtime		(0.f),
			m_paused			(false),
			m_loop				(true),
			p_animation			(nullptr),
			m_currentframe		(0),
			m_lastanimframe		(0)
		{
			setFrame(0);
			setOrigin(getGlobalBounds().width * 0.5f, getGlobalBounds().height * 0.5f);
		}

		//Konstruktor kopiujący
		Animated::Animated(const Animated & copy)
		:
			Sprite				(copy), //konstruktor kopiujący klasy bazowej
			m_time				(copy.m_time),
			m_elapsedtime		(copy.m_elapsedtime),
			m_paused			(copy.m_paused),
			m_loop				(copy.m_loop),
			p_animation			(copy.p_animation),
			m_currentframe		(copy.m_currentframe),
			m_lastanimframe		(copy.m_lastanimframe)
		{
		}

		//Konstruktor przenoszący
		Animated::Animated(Animated && other)
		:
			Sprite				(other), //konstruktor przenoszący klasy bazowej
			m_time				(std::move(other.m_time)),
			m_elapsedtime		(std::move(other.m_elapsedtime)),
			m_paused			(std::move(other.m_paused)),
			m_loop				(std::move(other.m_loop)),
			//kopiujemy pod wskaźnik dane obiektu źródłowego
			p_animation			(std::move(other.p_animation)),
			m_currentframe		(std::move(other.m_currentframe)),
			m_lastanimframe		(std::move(other.m_lastanimframe))

		{
			//zerujemy składowe obiektu źródłowego...
			other.m_time				= 0.f;
			other.m_elapsedtime			= 0.f;
			other.m_paused				=  0.f;
			other.m_loop				= false;
			//zwalniamy wskaźnik na dane obiektu źródłowego tak,
			//aby destruktor nie zwalniał pamięci wielokrotnie
			other.p_animation			= nullptr;
			other.m_currentframe		= 0;
			other.m_lastanimframe		= 0;
		}

		// Konstruktor parametryczny
		Animated::Animated(Animation* p_animation, bool play, bool loop, float time)
		:
			Sprite				(), //konstruktor klasy bazowej
			m_time				(time),
			m_elapsedtime		(time),
			m_paused			(!play),
			m_loop				(loop),
			p_animation			(p_animation),
			m_currentframe		(0),
			m_lastanimframe		(0)
		{
			setFrame(0);
			setOrigin(getGlobalBounds().width * 0.5f, getGlobalBounds().height * 0.5f);
		}

		//Destruktor
		Animated::~Animated()
		{
			m_time				= 0.f;
			m_elapsedtime		= 0.f;
			m_paused			= false;
			m_loop				= false;
			p_animation			= nullptr;
			m_currentframe		= 0;
			m_lastanimframe		= 0;
		}

		//Metoda zwraca wskaźnik na obiekt klasy Animation
		Animation* Animated::getAnimation() const
		{
			return p_animation;
		}

		//Metoda ustawia wskaźnik na obiekt klasy Animation
		void Animated::setAnimation(Animation* animated, bool playmode)
		{
			p_animation = animated;
			stop();

			if (!playmode)
				play();
			setOrigin(getGlobalBounds().width * 0.5f, getGlobalBounds().height * 0.5f);
		}

		//Metoda wyrejestrowuje animację - obiekt klasy Animation
		void Animated::unsetAnim()
		{
			p_animation = 0;
			stop();
		}

		//Metoda zwraca numer aktualnej klatki animacji obiektu klasy Animation
		const int Animated::getCurrentFrame() const
		{
			return m_currentframe;
		}

		//Metoda ustawia numer klatki animacji obiektu klasy Animation
		void Animated::setFrame(int frame)
		{
			if (p_animation != nullptr)
			{
				if (p_animation->getSize() > 0)
				{
					if ((*p_animation)[frame].GetFrameImage() != nullptr)
						setTexture(*((*p_animation)[frame].GetFrameImage()));
					setTextureRect((*p_animation)[frame].GetFrameRectangle());
					m_currentframe = frame;
				}
			}
		}

		//Metoda zwraca czas ekspozycji klatki animacji obiektu klasy Animation
		const float Animated::getFrameTime() const
		{
			return m_time;
		}

		//Metoda ustawia czas ekspozycji klatki animacji obiektu klasy Animation
		void Animated::setFrameTime(float time)
		{
			m_time = time;
		}

		//Metoda zwraca tryb pause animacji
		const bool Animated::getPaused() const
		{
			return m_paused;
		}

		//Metoda ustwia tryb pause animacji
		const void Animated::setPaused(bool paused)
		{
			m_paused = paused;
		}

		//Metoda sprawdza czy ustawiony jest tryb Loop
		const bool Animated::isLoop() const
		{
			return m_loop;
		}

		//Metoda ustawiająca tryb Loop animacji
		const void Animated::setLoop(bool loop)
		{
			m_loop = loop;
		}

		//Metoda zatrzymuje odtwarzanie animacji
		void Animated::pause()
		{
			m_paused = true;
		}

		//Metoda uruchamia animację
		void Animated::play()
		{
			m_paused = false;
		}

		//Metoda zatrzymuje animację
		void Animated::stop()
		{
			setFrame(0);
			m_elapsedtime = m_time;
			m_paused = true;
		}

		//Metoda sprawdza, czy animacja jest w trybie Pause
		const bool Animated::isPaused() const
		{
			return m_paused;
		}

		//Metoda sprawdza, czy animacja jest zatrzymana
		const bool Animated::isStoped() const
		{
			return (m_paused && (m_currentframe == 0) && (m_elapsedtime == m_time));
		}

		//Metoda uruchamia animację
		void Animated::update(float elapsed_time)
		{
			if (!m_paused && p_animation != nullptr)
			{
				m_elapsedtime -= elapsed_time;
				if (m_elapsedtime <= 0.f)
				{
					m_elapsedtime = m_time;
					if (m_currentframe + 1 < (int)p_animation->getSize())
						m_currentframe++;
					else
					{
						if (m_loop)
							m_currentframe = 0;
						else
						{
							stop();
						}
					}
					setFrame(m_currentframe);
				}
			}
		}

		//Metoda zwraca numer ostatnio wyświetlanej klatki animacji
		const int Animated::getLastAnimFrame() const
		{
			return m_lastanimframe;
		}

		//Metoda zwraca ilość klatek animacji
		const int Animated::getAnimSize() const
		{
			return p_animation->getSize();
		}

		//Metoda renderująca obiekt klasy Animated
		void Animated::draw(sf::RenderWindow* render)
		{
			render->draw(*this);
		}
	}//namespace animation
}//namespace acodemia

//Nadanie wartości stałej składowej statycznej
const float acodemia::animation::Animated::m_default_time = 0.06250f;
