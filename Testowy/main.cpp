#include <iostream>
#include <ctime>
#include <typeinfo>
#include <string>
#include <random>
#include <cmath>
#include <math.h>

#define _USE_MATH_DEFINES // for C++  

class Demo{};
int main()
{
	const int rozmiar = 100;
	int tablica[rozmiar];

	//pêtla...
	for (int i = 0; i < rozmiar; i++)
	{
		tablica[i] = i+1;
		std::cout << tablica[i] << std::endl;
	}



	getchar();
	return 0;
}

