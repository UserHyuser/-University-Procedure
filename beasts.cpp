#include <fstream>
#include "beast_atd.h"

using namespace std;

namespace simple_animals
{
	// Ввод параметров прямоугольника из файла
	void In(beast &b, ifstream &ifst)
	{
		ifst >> b.eat;
	}
	int LenghtName(beast &b, char name[20]) {
		int arrayLength = 0;
		for (int i = 0; name[i]; i++) {
			arrayLength++;
		}
		return arrayLength;
	}

	// Вывод параметров прямоугольника 
	void Out(beast &b, char name[20], int age, ofstream &ofst)
	{
		if (b.eat == 0) {
			ofst << "Это хищный зверь " << name << " возраст:" << age << endl;
		}
		else if (b.eat == 1) {
			ofst << "Это травоядный зверь " << name << " возраст:" << age << endl;
		}
		else {
			ofst << "Это насекомоядный зверь " << name << " возраст:" << age << endl;
		}
	}
} // end simple_animals namespace


