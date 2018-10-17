﻿//
//acodemia.pl
//

#ifndef H_ANIMATION_ACODEMIA
#define H_ANIMATION_ACODEMIA

#include "AnimationFrame.h"
#include <vector>


namespace acodemia
{
	namespace animation
	{
		///
		///Klasa reprezentuje animację
		///
		class Animation
		{
		public:

			///
			///Konstruktor domyślny
			///
			Animation();

			///
			///Konstruktor kopiujący
			///
			///@param & copy - stała referencja na obiekt klasy Animation
			///
			Animation(const Animation & copy);

			///
			///Konstruktor przenoszący
			///
			///@param && other = referencja do r-wartości
			///
			Animation(Animation && other);

			///
			///Konstruktor parametryczny
			///
			///@param texture - tekstura
			///
			///@param width_frame - szerokość klatki animacji
			///
			///@param height_frame - wysokość klatki animacji
			///
			Animation(const acodemia::rendering::Texture & texture, int width_frame, int height_frame);

			///
			///Destruktor
			///
			~Animation(void);

			///
			///Przeciążony operator przypisania kopiowania
			///
			///@param & copy - stała referencja na obiekt klasy Animation
			///
			Animation & operator=(const Animation & copy);

			///
			///Przeciążony operator przypisania przenoszenia
			///
			///@param && other -  referencja do r-wartości
			///
			Animation & operator=(Animation && other);

			///
			///Metoda zwraca ilość obieków klasy AnimationFrame w wektorze
			///
			unsigned int getSize() const;

			///
			///Operator [] dla obiektu klasy AnimationFrame
			///
			AnimationFrame & operator [] (unsigned N);

			///
			///Metoda dodaje do wektora obiekty klasy AnimationFrame
			///
			///@param texture - tekstura
			///
			///@param width_frame - szerokość klatki animacji
			///
			///@param height_frame - wysokość klatki animacji
			///
			bool setAnimationFramesFromAtlasTexture(const acodemia::rendering::Texture & texture, int width_frame, int height_frame);

			///
			///Metoda dodaje do wektora obiekt klasy AnimationFrame
			///
			///@param & texture - tekstura
			///
			///@param & rectangle - obszar prostokątny
			///
			void setSingleAnimationFrameTexture(const acodemia::rendering::Texture & texture, const sf::IntRect & rectangle);

			///
			///Metoda usuwa z wektora obiekt klasy AnimationFrame o podanym indeksie
			///
			///@param index - indeks klatki do usunięcia
			///
			void deleteAnimationFrame(int index);

			///
			///Metoda usuwa z wektora wszystkie elementy
			///
			void clearAllAnimationFrame();

			///
			///Metoda zwraca z wektora szerokość klatki animacji o podanym indeksie
			///
			///@param animation_frame_index - indeks klatki animacji
			///
			const int getAnimationFrameWidth(int animation_frame_index) const;

			///
			///Metoda zwraca z wektora wysokość klatki animacji o podanym indeksie
			///
			///@param animation_frame_index - indeks klatki animacji
			///
			const int getAnimationFrameHeight(int animation_frame_index) const;

		private:

			std::vector<AnimationFrame> m_frame; //kontener na klatki animacji

			//metoda wstawia do wektora pojedynczy obiekt klasy AnimationFrame
			void pushFrame(const AnimationFrame & new_frame);
		};
	}//namespace animation
}//namespace acodemia
#endif //H_ANIMATION_ACODEMIA