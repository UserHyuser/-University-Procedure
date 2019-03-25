#include <fstream>
#include "fish_atd.h"

using namespace std;

namespace simple_animals {
  // Ввод параметра шара из потока
  void In(fish &t, ifstream &ifst) 
  {
    ifst >> t.place;
  }
  void Out(fish &t, char name[20],int age ,ofstream &ofst)
  {
	  if (t.place == 0) {
		  ofst << "Рыба " <<name<< " живет в озере"
			  << " возраст:" << age << endl;
	  }
	  else if (t.place == 1) {
		  ofst << "Рыба " << name << " живет в море"
			  << " возраст:" << age << endl;
	  }
	  else if (t.place == 2) {
		  ofst << "Рыба " << name << " живет в реке"
			  << " возраст:" << age << endl;
	  }
  }
} // end simple_animals namespace

