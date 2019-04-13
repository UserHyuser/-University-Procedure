#include <fstream>
#include "container_atd.h"
#include "animal_atd.h"

using namespace std;

namespace simple_animals {
	// Signatures of using external functions
	void Out(animal &s, ofstream &ofst);

	// Filtered output
	void OnlyFish(container &c, ofstream &ofst) {
		ofst << "Only fishes:" << endl;
		for (int i = 0; i < c.len; i++) {
			ofst << i << ": ";
			if (c.cont[i]->k == animal::FISH)
				Out(*(c.cont[i]), ofst);
			else
				ofst << endl;
		}
		ofst << endl;
	}
} // end simple_animals namespace

