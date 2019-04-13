#include <fstream>
#include "bird_atd.h"

using namespace std;

namespace simple_animals
{
	// Input parameters of bird from file
	void In(bird &r, ifstream &ifst)
	{
		ifst >> r.fly;
	}

	int LenghtName(bird &r, char name[20]) {
		int arrayLength = 0;
		for (int i = 0; name[i]; i++) {
			arrayLength++;
		}
		return arrayLength;
	}

	// Output parameters of bird to file 
	void Out(bird &r, char name[20], int age, ofstream &ofst)
	{
		if (r.fly == 0) {
			ofst << "Bird " << name << " is non-migratory. Age: " << age << endl;
		}
		else {
			ofst << "Bird " << name << " is migratory. Age: " << age << endl;
		}
	}
} // end simple_animals namespace


