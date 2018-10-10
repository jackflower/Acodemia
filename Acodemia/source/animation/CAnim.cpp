/*
 _____________________________________
| CAnim.cpp - implementacja klasy.    |
| SCI - by Jack Flower february 2009. |
|_____________________________________|

*/

#include "CAnim.h"
#include "CAnimFrame.h"

namespace animation
{

	//Konstruktor
	CAnim::CAnim(void)
	{
	}

	//Konstruktor parametryczny
	CAnim::CAnim(const sf::Image& img, int width_frame, int height_frame)
	{
		AnimFromImage(img,width_frame,height_frame);
	}

	//Konstruktor kopiuj¹cy
	CAnim::CAnim(const CAnim& animframe_copy)
	:
		m_Frame(animframe_copy.m_Frame)
	{
	}

	//Destruktor
	CAnim::~CAnim(void)
	{
		m_Frame.clear();
	}

	//Metoda zwraca iloœæ obieków klasy CAnimFrame w wektorze
	size_t CAnim::Size() const
	{
	    return m_Frame.size();
	}

	//Definicja operatora dla obiektu klasy CAnimFrame
	CAnimFrame& CAnim::operator [] (size_t N)
	{
		return m_Frame[N];
	}

	//Metoda dodaje do wektora obiekty klasy CAnimFrame
	bool CAnim::AnimFromImage(const sf::Image& img, int width_frame, int height_frame)
	{
		//Zak³adamy, ¿e parametr img dzieli przez szerokoœæ i wysokoœæ ramki
		if (width_frame==0 || height_frame==0)
		{
			return false;
		}
		else
		{
			int i,j;
			//Wyliczamy iteracjê do pêtli:
			int width_i = img.GetWidth()/width_frame;		//Pobieramy szerokoœæ macierzy
			int height_j = img.GetHeight()/height_frame;	//Pobieramy wysokoœæ macierzy

			for (j=0 ; j<height_j; j++)
			{
				for (i=0 ; i<width_i; i++)
				{
					PushFrame( CAnimFrame(img, sf::IntRect
								(	width_frame*i,
									height_frame*j,
									(width_frame*i) + width_frame,
									(height_frame*j) + height_frame
								)));
				}
			}
			return true;
		}
	}

	//Metoda dodaje do wektora obiekt klasy CAnimFrame
	void CAnim::AnimFromImage(const sf::Image& _img, sf::IntRect _rect )
	{
		PushFrame(CAnimFrame(_img, _rect));
	}

	//Metoda usuwa z wektora obiekt klasy CAnimFrame o podanym indeksie
	void CAnim::DeleteAnimFrame(int index)
	{
		m_Frame.erase(m_Frame.begin() + index);
	}

	//Metoda usuwa z wektora wszystkie elementy
	void CAnim::ClearAllAnimFrame()
	{
		m_Frame.clear();
	}

	//Metoda zwraca z wektora szerokoœæ klatki animacji o podanym indeksie
	int const CAnim::GetAnimFrameWidth(int animframe_index) 
	{
		return m_Frame[animframe_index].GetFrameRectangle().GetWidth();  
	}

	//Metoda zwraca z wektora wysokoœæ klatki animacji o podanym indeksie
	int const CAnim::GetAnimFrameHeight(int animframe_index)
	{
		return m_Frame[animframe_index].GetFrameRectangle().GetHeight();
	}

	//Metoda wstawia do wektora pojedynczy obiekt klasy CAnimFrame
	void CAnim::PushFrame(const CAnimFrame& NewFrame)
	{
		m_Frame.push_back(NewFrame);
	}

}//namespace animation