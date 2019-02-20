#ifndef H_APTECZKA
#define H_APTECZKA

#include <string>

class Apteczka
{
public:
	//konstruktor
	Apteczka();
	//destruktor
	~Apteczka();
	

	void Bumm();
	void Leczenie(float ilosc_tabletek);

private:

	std::string kolor; //kolor apteczki
	bool detonator;


};
#endif//H_APTECZKA
