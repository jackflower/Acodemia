////////////////////////////////////////////////////////////
//
// Acodemia Copyright (C) Jacek Kwiatek
// e-mail: jackflower (at) poczta.onet.pl
// acodemia.pl
//
// To oprogramowanie dostarczane jest w postaci takiej,
// w jakiej jest, bez wyra�nych ani domniemanych gwarancji.
//
// W �adnym wypadku Autor nie ponosi odpowiedzialno�ci
// za jakiekolwiek szkody powsta�e w wyniku korzystania
// z tego oprogramowania.Zastrzega
//
// Zezwala si� na korzystanie z tego oprogramowania
// w dowolnym celu, tak�e komercyjnym. Mo�na je zmieni�
// i swobodnie rozpowszechnia�.
//
// Zastrzega si� nast�puj�ce ograniczenia:
//
// 1. Je�li u�ywasz tego oprogramowania w swoich
//    produktach, potwierdzenie pochodzenia tego
//    oprogramowania w dokumentacji produktu,
//    by�oby docenione, ale nie jest wymagane.
//
////////////////////////////////////////////////////////////

#include "Player.h"

namespace acodemia
{
	namespace physical
	{
		//Konstruktor domy�lny
		Player::Player()
		{
			//doliczy� klas� bazow�
		}

		//Konstruktor kopiuj�cy
		Player::Player(const Player & copy)
		{
			//doliczy� klas� bazow�
		}

		//Konstruktor przenosz�cy
		Player::Player(Player && other)
		{
			//doliczy� klas� bazow�
		}

		//Destruktor
		Player::~Player()
		{
			//doliczy� klas� bazow�
		}

		//Przeci��ony operator przypisania kopiowania
		Player & Player::operator=(const Player & copy)
		{
			if (this != &copy)
			{
				//doliczy� klas� bazow�

				//m_displayable = copy.m_displayable;
				//m_use_displayable = copy.m_use_displayable;
				//m_destruction = copy.m_destruction;
				//m_position = copy.m_position;
				//m_rotation = copy.m_rotation;
				//m_scale = copy.m_scale;
				//m_origin = copy.m_origin;
				//m_color = copy.m_color;
				//m_stored_color = copy.m_stored_color;
			}
			return *this;
		}

		//Przeci��ony operator przypisania przenoszenia
		Player & Player::operator=(Player && other)
		{
			if (this != &other)
			{
				//doliczy� klas� bazow�

				//m_displayable = other.m_displayable;
				//m_use_displayable = other.m_use_displayable;
				//m_destruction = other.m_destruction;
				//m_position = other.m_position;
				//m_rotation = other.m_rotation;
				//m_scale = other.m_scale;
				//m_origin = other.m_origin;
				//m_color = other.m_color;
				//m_stored_color = other.m_stored_color;
			}
			return *this;
		}
		
	}//namespace physical
}//namespace acodemia
