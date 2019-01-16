#include <iostream>
#include <ctime>
#include <typeinfo>
#include <string>

class Demo{};
int main()
{
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


	//randomize
	//EnemyGenerator

	getchar();

	return 0;
}

