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
// z tego oprogramowania.
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

#ifndef H_ENEMY_GENERATOR_ACODEMIA
#define H_ENEMY_GENERATOR_ACODEMIA

#include "../utilities/Singleton.h"

#define gEnemyGenerator EnemyGenerator::getSingleton()

///
///Klasa reprezentuje fabryk� produkuj�c� wrog�w,
///dziedziczy po szablonie, kt�ry jest wzorcem singletona
///
class EnemyGenerator : public Singleton<EnemyGenerator>
{
public:

	///
	///Konstruktor domy�lny
	///
	EnemyGenerator();

	///
	///Destruktor wirtualny
	///
	virtual ~EnemyGenerator();
};

#endif//H_ENEMY_GENERATOR_ACODEMIA
