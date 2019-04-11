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
	int LenghtName(beast &b, char name[20]) {
		int arrayLength = 0;
		for (int i = 0; name[i]; i++) {
			arrayLength++;
		}
		return arrayLength;
	}

	// ����� ���������� �������������� 
	void Out(beast &b, char name[20], int age, ofstream &ofst)
	{
		if (b.eat == 0) {
			ofst << "��� ������ ����� " << name << " �������:" << age << endl;
		}
		else if (b.eat == 1) {
			ofst << "��� ���������� ����� " << name << " �������:" << age << endl;
		}
		else {
			ofst << "��� ������������� ����� " << name << " �������:" << age << endl;
		}
	}
} // end simple_animals namespace


