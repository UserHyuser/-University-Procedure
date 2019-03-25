#include <fstream>
#include "bird_atd.h"

using namespace std;

namespace simple_animals 
{
	
	// ���� ���������� �������������� �� �����
  void In(bird &r, ifstream &ifst)
  {
    ifst >> r.fly;
  }

  int LenghtName(bird &r, char name[20]) {
	  int arrayLength = 0;
	  for (int i = 0; name[i]; i++) {
		  arrayLength++;
	  }
	  return arrayLength;
  }

  // ����� ���������� �������������� 
  void Out(bird &r, char name[20], int age ,ofstream &ofst) 
  {
	  if (r.fly == 0) {
		  ofst << "��� ������������ ����� "<< name << " �������:"<< age << endl;
	  }
	  else {
		  ofst << "��� ���������� ����� " << name << " �������:" << age << endl;
	  }
  }
} // end simple_animals namespace


