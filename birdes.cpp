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
  // ����� ���������� �������������� 
  void Out(bird &r, char name[20] ,ofstream &ofst) 
  {
	  if (r.fly == 0) {
		  ofst << "��� ������������ ����� "<< name << endl;
	  }
	  else {
		  ofst << "��� ���������� ����� " << name << endl;
	  }
  }
} // end simple_animals namespace


