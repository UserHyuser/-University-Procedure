#include <fstream>
#include "animal_atd.h"
#include "conteiner.h"

using namespace std;

namespace simple_animals {
	
	int LenghtName(animal &s);


	bool Compare(animal *first, animal *second) {
		return LenghtName(*first) < LenghtName(*second);
	}
}