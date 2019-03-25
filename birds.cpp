#include "bird_atd.h"
using namespace std;
namespace simple_animals {
	// Ввод параметров параллелепипеда
	void bird::InData(ifstream &ifst)
	{
		ifst >> fly;
		ifst >> name;
		ifst >> age;
	}
} // end simple_animals namespace

using namespace std;
namespace simple_animals {
	// Вывод параметров
	void bird::Out(ofstream &ofst)
	{
		if (fly==0) {
			ofst << "Это неперелетная птица " << name << " возраст: "<< age << endl;
		}
		else {
			ofst << "Это перелетная птица " << name << " возраст: " << age << endl;
		}
			
	}
	int bird::LenghtName() {
		int arrayLength = 0;
		for (int i = 0; name[i]; i++) {
			arrayLength++;
		}
		return arrayLength;
	}
} // end simple_animals namespace
