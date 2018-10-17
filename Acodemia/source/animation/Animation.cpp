//acodemia.pl

#include "Animation.h"

namespace acodemia
{
	namespace animation
	{
		//Konstruktor
		Animation::Animation()
		:
			m_frame()
		{
		}

		//Konstruktor kopiujący
		Animation::Animation(const Animation & copy)
		:
			m_frame(copy.m_frame)
		{
		}

		//Konstruktor przenoszący
		Animation::Animation(Animation && other)
		:
			m_frame(std::move(other.m_frame))
		{
		}

		//Konstruktor parametryczny
		Animation::Animation(const acodemia::rendering::Texture & texture, int width_frame, int height_frame)
		{
			setAnimationFramesFromAtlasTexture(texture, width_frame, height_frame);
		}

		//Destruktor
		Animation::~Animation(void)
		{
			m_frame.clear();
		}

		//Przeciążony operator przypisania kopiowania
		Animation & Animation::operator=(const Animation & copy)
		{
			//to do...
			//patrz class Displayable
			return *this;
		}

		//Przeciążony operator przypisania przenoszenia
		Animation & Animation::operator=(Animation && other)
		{
			//to do...
			//patrz class Displayable
			return *this;
		}

		//Metoda zwraca ilość obieków klasy AnimationFrame w wektorze
		unsigned int Animation::getSize() const
		{
			return m_frame.size();
		}

		//Operator [] dla obiektu klasy AnimationFrame
		AnimationFrame & Animation::operator [] (unsigned N)
		{
			return m_frame[N];
		}

		//Metoda dodaje do wektora obiekty klasy AnimationFrame
		bool Animation::setAnimationFramesFromAtlasTexture(const acodemia::rendering::Texture & texture, int width_frame, int height_frame)
		{
			//Zakładamy, że szerokość i wysokość tekstury jest dodatnia
			if (width_frame <= 0 || height_frame <= 0)
				return false;//rozmiar musi być dodatni, a dzielnik nie może być równy zero...
			else
			{
				int width_i = texture.getSize().x / width_frame;	//pobieramy szerokość tekstury
				int height_j = texture.getSize().y / height_frame;	//pobieramy wysokość tekstury

				for (int j = 0; j < height_j; j++)
				{
					for (int i = 0; i < width_i; i++)
					{
						pushFrame(AnimationFrame(texture, sf::IntRect
						(width_frame*i,
							height_frame*j,
							width_frame,
							height_frame
						)));
					}
				}
				return true;
			}
		}

		//Metoda dodaje do wektora obiekt klasy AnimationFrame
		void Animation::setSingleAnimationFrameTexture(const acodemia::rendering::Texture & texture, const sf::IntRect & rectangle)
		{
			pushFrame(AnimationFrame(texture, rectangle));
		}

		//Metoda usuwa z wektora obiekt klasy AnimationFrame o podanym indeksie
		void Animation::deleteAnimationFrame(int index)
		{
			m_frame.erase(m_frame.begin() + index);
		}

		//Metoda usuwa z wektora wszystkie elementy
		void Animation::clearAllAnimationFrame()
		{
			m_frame.clear();
		}

		//Metoda zwraca z wektora szerokość klatki animacji o podanym indeksie
		const int Animation::getAnimationFrameWidth(int animation_frame_index) const
		{
			return m_frame[animation_frame_index].GetFrameRectangle().width;
		}

		//Metoda zwraca z wektora wysokość klatki animacji o podanym indeksie
		const int Animation::getAnimationFrameHeight(int animation_frame_index) const
		{
			return m_frame[animation_frame_index].GetFrameRectangle().height;
		}

		//metoda wstawia do wektora pojedynczy obiekt klasy AnimationFrame
		void Animation::pushFrame(const AnimationFrame & new_frame)
		{
			m_frame.push_back(new_frame);
		}
	}//namespace animation
}//namespace animation
