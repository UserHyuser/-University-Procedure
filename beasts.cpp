#include "beast_atd.h"
using namespace std;
namespace simple_animals {
	// ���� ���������� ���������������
	void beast::InData(ifstream &ifst)
	{
		ifst >> eat;
		ifst >> name;
		ifst >> age;
	}
} // end simple_animals namespace

using namespace std;
namespace simple_animals {
	// ����� ���������� ���������������
	void beast::Out(ofstream &ofst)
	{
		if (eat == 0) {
			ofst << "��� ������ ����� " << name << " ���������: " << age << endl;
		}
		else if (eat == 1){
			ofst << "��� ���������� ����� " << name << " ���������: " << age << endl;
		}
		else {
			ofst << "��� ������������� ����� " << name << " ���������: " << age << endl;
		}

	}
	int beast::LenghtName() {
		int arrayLength = 0;
		for (int i = 0; name[i]; i++) {
			arrayLength++;
		}
		return arrayLength;
	}


} // end simple_animals namespace
