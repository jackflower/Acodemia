////////////////////////////////////////////////////////////
//
// Acodemia Copyright (C) Jacek Kwiatek
// e-mail: jackflower (at) poczta.onet.pl
// acodemia.pl
//
// To oprogramowanie dostarczane jest w postaci takiej,
// w jakiej jest, bez wyraŸnych ani domniemanych gwarancji.
//
// W ¿adnym wypadku Autor nie ponosi odpowiedzialnoœci
// za jakiekolwiek szkody powsta³e w wyniku korzystania
// z tego oprogramowania.
//
// Zezwala siê na korzystanie z tego oprogramowania
// w dowolnym celu, tak¿e komercyjnym. Mo¿na je zmieniæ
// i swobodnie rozpowszechniaæ.
//
// Zastrzega siê nastêpuj¹ce ograniczenia:
//
// 1. Jeœli u¿ywasz tego oprogramowania w swoich
//    produktach, potwierdzenie pochodzenia tego
//    oprogramowania w dokumentacji produktu,
//    by³oby docenione, ale nie jest wymagane.
//
////////////////////////////////////////////////////////////


///
///Szablon reprezentuje wzorzec Singleton
///
template <typename T> class Singleton
{

protected:

	///
	///Konstruktor
	///
	Singleton()
	{
	}

	///
	///Destruktor wirtualny
	///
	virtual ~Singleton()
	{
	}

public:

	static T & getSingleton()
	{
		static T m_singleton;
		return m_singleton;
	}
};
