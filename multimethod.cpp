#include "container_atd.h"
#include "animal_atd.h"
#include <fstream>

using namespace std;

namespace simple_animals {
	// Signatures of using external functions
	void Out(animal &s, ofstream &ofst);

	// Multimethod
	void MultiMethod(container &c, ofstream &ofst) {
		ofst << "Multimethod." << endl;
		for (int i = 0; i < c.len - 1; i++) {
			for (int j = i + 1; j < c.len; j++) {
				switch (c.cont[i]->k) {
				case animal::FISH:
					switch (c.cont[j]->k) {
					case animal::FISH:
						ofst << "Fish and fish." << endl;
						break;
					case animal::BIRD:
						ofst << "Fish and bird." << endl;
						break;
					case animal::BEAST:
						ofst << "Fish and beast." << endl;
						break;
					default:
						ofst << "Unknown type." << endl;
					}
					break;
				case animal::BIRD:
					switch (c.cont[j]->k) {
					case animal::FISH:
						ofst << "Bird and fish." << endl;
						break;
					case animal::BIRD:
						ofst << "Bird and bird." << endl;
						break;
					case animal::BEAST:
						ofst << "Bird and beast." << endl;
						break;
					default:
						ofst << "Unknown type." << endl;
					}
					break;
				case animal::BEAST:
					switch (c.cont[j]->k) {
					case animal::FISH:
						ofst << "Beast and fish." << endl;
						break;
					case animal::BIRD:
						ofst << "Beast and bird." << endl;
						break;
					case animal::BEAST:
						ofst << "Beast and beast." << endl;
						break;
					default:
						ofst << "Unknown type." << endl;
					}
					break;
				default:
					ofst << "Unknown type." << endl;
				}
				Out(*(c.cont[i]), ofst);
				Out(*(c.cont[j]), ofst);
			}
		}
		ofst << endl;
	}
}