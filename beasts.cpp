#include <fstream>
#include "beast_atd.h"

using namespace std;

namespace simple_animals
{
	// ���� ���������� �������������� �� �����
	void In(beast &b, ifstream &ifst)
	{
		ifst >> b.eat;
	}
	// ����� ���������� �������������� 
	void Out(beast &b, char name[20], ofstream &ofst)
	{
		if (b.eat == 0) {
			ofst << "��� ������ ����� " << name << endl;
		}
		else if (b.eat == 1) {
			ofst << "��� ���������� ����� " << name << endl;
		}
		else {
			ofst << "��� ������������� ����� " << name << endl;
		}
	}
} // end simple_animals namespace


