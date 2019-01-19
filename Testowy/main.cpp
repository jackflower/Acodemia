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
	std::default_random_engine
		URBG{ std::random_device{}() };
	// to emulate rand() or random()
	std::uniform_int_distribution<long>
		dist(0, RAND_MAX);

	//for (int i = 0; i < 10; i++)
	//{
	//	long next_random = dist(URBG);
	//	std::cout << next_random << std::endl;
	//}

	//std::srand((unsigned)time(nullptr));

	//for (int i = 0; i < 10; i++)
	//{
	//	int liczba = std::rand();
	//	std::cout << liczba << std::endl;
	//}

	Demo mydemo;
	int myint = 50;
	std::cout << "myint has type: " << typeid(myint).name() << '\n';
	std::cout << "mydemo has type: " << typeid(mydemo).name() << '\n';
	std::string napis = typeid(mydemo).name();
	std::string olo = napis;

	std::cout << napis << std::endl;
	std::srand((unsigned)time(0));
	int liczba = rand();
	//std::cout << liczba << std::endl;

	getchar();
	return 0;
}

