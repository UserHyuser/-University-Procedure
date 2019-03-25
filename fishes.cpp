#include <fstream>
#include "fish_atd.h"

using namespace std;

namespace simple_animals {
  // ���� ��������� ���� �� ������
  void In(fish &t, ifstream &ifst) 
  {
    ifst >> t.place;
  }
  void Out(fish &t, char name[20],int age ,ofstream &ofst)
  {
	  if (t.place == 0) {
		  ofst << "���� " <<name<< " ����� � �����"
			  << " �������:" << age << endl;
	  }
	  else if (t.place == 1) {
		  ofst << "���� " << name << " ����� � ����"
			  << " �������:" << age << endl;
	  }
	  else if (t.place == 2) {
		  ofst << "���� " << name << " ����� � ����"
			  << " �������:" << age << endl;
	  }
  }
} // end simple_animals namespace

