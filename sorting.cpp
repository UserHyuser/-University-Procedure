#include <fstream>
#include "animal_atd.h"
#include "container_atd.h"

using namespace std;

namespace simple_animals {
	//Signatures of using external functions
	int LenghtName(animal &s);

	bool Compare(animal *first, animal *second) {
		return LenghtName(*first) < LenghtName(*second);
	}
}