#ifndef __animal_atd__
#define __animal_atd__
#include "bird_atd.h"
#include "fish_atd.h"
#include "beast_atd.h"
namespace simple_animals {
	// Structure generalizing all types of animals
	struct animal {
		enum key { BIRD, FISH, BEAST };
		key k; 
		char name[20];
		int age = 0;
		// Used alternatives
		union { 
			bird r;
			fish t;
			beast b;
		};
	};
} // end simple_animals namespace
#endif
