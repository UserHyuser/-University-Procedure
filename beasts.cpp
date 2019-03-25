#include "beast_atd.h"
using namespace std;
namespace simple_animals {
	// Ввод параметров параллелепипеда
	void beast::InData(ifstream &ifst)
	{
		ifst >> eat;
		ifst >> name;
		ifst >> age;
	}
} // end simple_animals namespace

using namespace std;
namespace simple_animals {
	// Вывод параметров параллелепипеда
	void beast::Out(ofstream &ofst)
	{
		if (eat == 0) {
			ofst << "Это хищный зверь " << name << " возрастом: " << age << endl;
		}
		else if (eat == 1){
			ofst << "Это травоядный зверь " << name << " возрастом: " << age << endl;
		}
		else {
			ofst << "Это насекомоядный зверь " << name << " возрастом: " << age << endl;
		}

	}
	int beast::LenghtName() {
		int arrayLength = 0;
		for (int i = 0; name[i]; i++) {
			arrayLength++;
		}
		return arrayLength;
	}


} // end simple_animals namespace
