#include <fstream>
#include "animal_atd.h"

using namespace std;

namespace simple_animals {
  // ��������� ��������� ������� ������� 
  void In(bird &r, ifstream &ist);
  void In(fish  &t, ifstream &ist);

  // ���� ���������� ���������� ������ �� �����
  animal* In(ifstream &ifst)
  {
    animal *sp;
    int k;
    ifst >> k;
    switch(k) {
    case 1:
      sp = new animal;
      sp->k = animal::key::BIRD;
      In(sp->r, ifst);
	  ifst >> sp->name;
      return sp;
    case 2:
      sp = new animal;
      sp->k = animal::key::FISH;
      In(sp->t, ifst);
	  ifst >> sp->name;
      return sp;
    default:
      return 0;
    }
  }

  void Out(bird &r, char name[20],ofstream &ofst);
  void Out(fish  &t, char name[20],ofstream &ofst);

  // ����� ���������� ������� ������ � �����
  void Out(animal &s, ofstream &ofst) {
    switch(s.k) {
    case animal::key::BIRD:
      Out(s.r, s.name,ofst);
      break;
    case animal::key::FISH:
      Out(s.t, s.name, ofst);
      break;
    default:
      ofst << "Incorrect figure!" << endl;
    }
  }
} // end simple_animals namespace


