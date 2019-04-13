#include <fstream>
#include "beast_atd.h"

using namespace std;

namespace simple_animals
{
	// Input parameters of beast from file
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

	// Output parameters of beast to file 
	void Out(beast &b, char name[20], int age, ofstream &ofst)
	{
		if (b.eat == 0) {
			ofst << "Beast " << name << " is predator. Age: " << age << endl;
		}
		else if (b.eat == 1) {
			ofst << "Beast " << name << " is herbivorous. Age: " << age << endl;
		}
		else {
			ofst << "Beast " << name << " is insectivorous. Age: " << age << endl;
		}
	}
} // end simple_animals namespace


