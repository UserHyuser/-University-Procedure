#include <fstream>
#include "fish_atd.h"

using namespace std;

namespace simple_animals {
  // ���� ��������� ���� �� ������
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
  void Out(fish &t, char name[20] ,ofstream &ofst)
  {
	  if (t.place == 0) {
		  ofst << "���� " <<name<< " ����� � �����"
			  << endl;
	  }
	  else if (t.place == 1) {
		  ofst << "���� " << name << " ����� � ����"
			  << endl;
	  }
	  else if (t.place == 2) {
		  ofst << "���� " << name << " ����� � ����"
			  << endl;
	  }
  }
} // end simple_animals namespace

