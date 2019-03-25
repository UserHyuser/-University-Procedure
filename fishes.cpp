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
		  ofst << "Ðûáà " <<name<< " æèâåò â îçåðå"
			  << " âîçðàñò:" << age << endl;
	  }
	  else if (t.place == 1) {
		  ofst << "Ðûáà " << name << " æèâåò â ìîðå"
			  << " âîçðàñò:" << age << endl;
	  }
	  else if (t.place == 2) {
		  ofst << "Ðûáà " << name << " æèâåò â ðåêå"
			  << " âîçðàñò:" << age << endl;
	  }
  }
} // end simple_animals namespace
