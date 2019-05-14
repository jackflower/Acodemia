////////////////////////////////////////////////////////////
//
// Acodemia Copyright (C) Jacek Kwiatek
// e-mail: jackflower (at) poczta.onet.pl
// acodemia.pl
//
// To oprogramowanie dostarczane jest w postaci takiej,
// w jakiej jest, bez wyraźnych ani domniemanych gwarancji.
//
// W żadnym wypadku Autor nie ponosi odpowiedzialności
// za jakiekolwiek szkody powstałe w wyniku korzystania
// z tego oprogramowania.
//
// Zezwala się na korzystanie z tego oprogramowania
// w dowolnym celu, także komercyjnym. Można je zmienić
// i swobodnie rozpowszechniać.
//
// Zastrzega się następujące ograniczenia:
//
// 1. Jeśli używasz tego oprogramowania w swoich
//    produktach, potwierdzenie pochodzenia tego
//    oprogramowania w dokumentacji produktu,
//    byłoby docenione, ale nie jest wymagane.
//
////////////////////////////////////////////////////////////

#ifndef H_ENEMY_GENERATOR_ACODEMIA
#define H_ENEMY_GENERATOR_ACODEMIA

#include "../utilities/Singleton.h"

#define gEnemyGenerator EnemyGenerator::getSingleton()

///
///Klasa reprezentuje fabrykę produkującą wrogów,
///dziedziczy po szablonie, który jest wzorcem singletona
///
class EnemyGenerator : public Singleton<EnemyGenerator>
{
public:

	///
	///Konstruktor domyślny
	///
	EnemyGenerator();

	///
	///Destruktor wirtualny
	///
	virtual ~EnemyGenerator();
};

#endif//H_ENEMY_GENERATOR_ACODEMIA
