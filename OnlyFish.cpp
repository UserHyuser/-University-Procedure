#include <fstream>
#include "conteiner.h"
#include "animal_atd.h"

using namespace std;

namespace simple_animals {
	void Out(animal &s, ofstream &ofst);
	// ���� ��������� ���� �� ������
	void OnlyFish(container &c, ofstream &ofst) {
		ofst << "������ ����." << endl;
		for (int i = 0; i < c.len; i++) {
			ofst << i << ": ";
			if (c.cont[i]->k == animal::FISH)
				Out(*(c.cont[i]), ofst);
			else
				ofst << endl;
		}
	}
} // end simple_animals namespace

