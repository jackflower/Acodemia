/*
 _____________________________________
| CAnim.h - definicja klasy. 	      |
| SCI - by Jack Flower December 2009. |
|_____________________________________|

*/

#ifndef ANIM_JACK
#define ANIM_JACK

#include "CAnimFrame.h"
#include <vector>

namespace animation
{

	///
	///Klasa reprezentuje animacjê
	///
	class CAnim
	{
	public:

		///
		///Konstruktor domyœlny
		///
		CAnim(void);

		///
		///Konstruktor parametryczny
		///
		///@param img - tekstura
		///
		///@param width_frame - szerokoœæ klatki animacji
		///
		///@param height_frame - wysokoœæ klatki animacji
		///
		CAnim(const sf::Image& img, int width_frame, int height_frame);

		///
		///Konstruktor kopiuj¹cy
		///
		///@param &animframe_copy - obiekt klasy CAnim
		///
		CAnim(const CAnim& animframe_copy);

		///
		///Destruktor
		///
		virtual ~CAnim(void);

		///
		///Metoda zwraca iloœæ obieków klasy CAnimFrame w wektorze
		///
		size_t Size() const;

		///
		///Deklaracja operatora dla obiektu klasy CAnimFrame
		///
		CAnimFrame& operator [] (size_t N);

		///
		///Metoda dodaje do wektora obiekty klasy CAnimFrame
		///
		///@param img - tekstura
		///
		///@param width_frame - szerokoœæ klatki animacji
		///
		///@param height_frame - wysokoœæ klatki animacji
		///
		bool AnimFromImage(const sf::Image& img, int width_frame, int height_frame);

		///
		///Metoda dodaje do wektora obiekt klasy CAnimFrame
		///
		void AnimFromImage(const sf::Image& _img, sf::IntRect _rect );

		///
		///Metoda usuwa z wektora obiekt klasy CAnimFrame o podanym indeksie
		///
		///@param index - indeks klatki do uzuniêcia
		///
		void DeleteAnimFrame(int index);

		///
		///Metoda usuwa z wektora wszystkie elementy
		///
		void ClearAllAnimFrame();
	
		///
		///Metoda zwraca z wektora szerokoœæ klatki animacji o podanym indeksie
		///
		///@param animframe_index - indeks klatki animacji
		///
		int const GetAnimFrameWidth(int animframe_index);
	
		///
		///Metoda zwraca z wektora wysokoœæ klatki animacji o podanym indeksie
		///
		///@param animframe_index - indeks klatki animacji
		///
		int const GetAnimFrameHeight(int animframe_index);

	private:
		///
		///Metoda wstawia do wektora pojedynczy obiekt klasy CAnimFrame
		///
		///@param &NewFrame - obiekt klasy CAnimFrame
		///
		void PushFrame(const CAnimFrame& NewFrame);

		///
		///Wektor do przechowywania obiektów klasy CAnimFrame
		///
		std::vector<CAnimFrame> m_Frame;
	};

}//namespace animation

#endif // ANIM_JACK