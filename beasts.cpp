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
	// Вывод параметров прямоугольника 
	void Out(beast &b, char name[20], ofstream &ofst)
	{
		if (b.eat == 0) {
			ofst << "Это хищный зверь " << name << endl;
		}
		else if (b.eat == 1) {
			ofst << "Это травоядный зверь " << name << endl;
		}
		else {
			ofst << "Это насекомоядный зверь " << name << endl;
		}
	}
} // end simple_animals namespace


