#include <fstream>
#include "fish_atd.h"

using namespace std;

namespace simple_animals {
  // Ââîä ïàðàìåòðà øàðà èç ïîòîêà
  void In(fish &t, ifstream &ifst) 
  {
    ifst >> t.place;
  }

  int LenghtName(fish &t, char name[20]) {
	  int arrayLength = 0;
	  for (int i = 0; name[i]; i++) {
		  arrayLength++;
	  }
	  return arrayLength;
  }

  void Out(fish &t, char name[20],int age ,ofstream &ofst)

  {
	  if (t.place == 0) {
		  ofst << "Fish " <<name<< " lives in"
			  << " lake:" << age << endl;
	  }
	  else if (t.place == 1) {
		  ofst << "Fish " << name << " lives in"
			  << " sea:" << age << endl;
	  }
	  else if (t.place == 2) {
		  ofst << "Fish " << name << " lives in"
			  << " river:" << age << endl;
	  }
  }
} // end simple_animals namespace
